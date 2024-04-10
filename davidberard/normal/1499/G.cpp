#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 400400;
const ll MOD = 998244353;
pair<int, int> endpoints[N];

int tpow[N];

int par[N];
list<int> edges[N];
ll csum[N], tsum[N];
int color[N];
int label[N];
int curans[N];
int zz;

ll hsh = 0;

void setup() {
  memset(par, -1, sizeof par);
  tpow[0] = 1;
  for (int i=1; i<N; ++i) {
    tpow[i] = tpow[i-1]*2%MOD;
  }
}
int FIND(int u) {
  if (par[u] == -1) {
    return u;
  }
  return par[u] = FIND(par[u]);
}
void UNION(int u, int v) {
  //cerr << "   UNION " << u << " " << v << " . " << edges[u].size() << "+" << edges[v].size() << endl;
  u = FIND(u);
  v = FIND(v);
  if (u == v) {
    assert(false);
    return;
  }
  hsh = (hsh - csum[u] - csum[v] + MOD*2)%MOD;
  if (edges[u].size() < edges[v].size()) {
    swap(u, v);
  }
    ////cerr << " " << endpoints[u].first << " . " << endpoints[u].second << endl;
    ////cerr << " " << endpoints[v].first << " . " << endpoints[v].second << endl;
  if (endpoints[u].first == endpoints[v].first || endpoints[u].second == endpoints[v].second) {
    ////cerr << " REVERSE " << v << " WHICH IS " << endpoints[v].first << "," << endpoints[v].second << endl;
    edges[v].reverse();
    swap(endpoints[v].first, endpoints[v].second);
    if (edges[v].size()%2 == 0) {
      csum[v] = (tsum[v] + MOD - csum[v])%MOD;
    }
  }
  if (endpoints[u].first == endpoints[v].second) {
    ////cerr << " PUT v FIRST " << endl;
    if (edges[v].size()%2 == 1) {
      csum[u] = (tsum[u] + MOD - csum[u])%MOD;
    }
    edges[u].insert(edges[u].begin(), edges[v].begin(), edges[v].end());
    endpoints[u].first = endpoints[v].first;
    label[endpoints[v].second] = 0;
    csum[u] = (csum[u] + csum[v])%MOD;
    tsum[u] = (tsum[u] + tsum[v])%MOD;
  } else if (endpoints[u].second == endpoints[v].first) {
    if (edges[u].size()%2 == 1) {
      csum[v] = (tsum[v] + MOD - csum[v])%MOD;
    }
    edges[u].insert(edges[u].end(), edges[v].begin(), edges[v].end());
    endpoints[u].second = endpoints[v].second;
    label[endpoints[v].first] = 0;
    csum[u] = (csum[u] + csum[v])%MOD;
    tsum[u] = (tsum[u] + tsum[v])%MOD;
  } else {
    assert(false);
  }
  hsh = (hsh + csum[u])%MOD;
  //label[endpoints[u].first] = u;
  //label[endpoints[u].second] = u;
  par[v] = u;
  //cerr << "    . " << edges[u].size() << endl;
}

  int n1, n2, m;
  int ecount;
void proc_new_edge() {
      int v1, v2;
      cin >> v1 >> v2;
      //cerr << "  DEF " << ecount+1 << " = " << v1 << " -> " << v2 << endl;
      v2 += n1;
      ++ecount;
      ++zz;
      edges[zz].push_back(ecount);
      endpoints[zz] = {v1, v2};
      ////cerr << " .. " << endpoints[zz].first << " " << endpoints[zz].second << endl;
      csum[zz] = tsum[zz] = tpow[ecount];
      hsh = (hsh + csum[zz])%MOD;
      if (label[v1] && label[v2] && FIND(label[v1]) == FIND(label[v2])) {
          //cerr << " MAKE CYCLE " << endl;
        UNION(zz, label[v1]);
        int w = FIND(zz);
        int idx = 0;
        for (auto& x : edges[w]) {
          color[x] = idx%2+1;
          idx++;
        }
        label[endpoints[w].first] = label[endpoints[w].second] = 0;
      } else {
        if (label[v1] && label[v2]) {
          //cerr << " UNION BOTH " << endl;
          UNION(zz, label[v1]);
          UNION(zz, label[v2]);
          int w = FIND(zz);
          label[endpoints[w].first] = label[endpoints[w].second] = w;
        } else if (label[v1] && !label[v2]) {
          //cerr << " v1 not v2 " << endl;
          UNION(zz, label[v1]);
          int w = FIND(zz);
          label[endpoints[w].first] = label[endpoints[w].second] = w;
        } else if (!label[v1] && label[v2]) {
          //cerr << " v2 not v1 " << endl;
          UNION(zz, label[v2]);
          int w = FIND(zz);
          label[endpoints[w].first] = label[endpoints[w].second] = w;
        } else {
          //cerr << " neither " << endl;
          label[endpoints[zz].first] = label[endpoints[zz].second] = zz;
        }
      }

}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  setup();
  cin >> n1 >> n2 >> m;
  while (m--) {
    proc_new_edge();
    ////cerr << "(" << hsh << ")" << endl;
  }
  int q;
  cin >> q;
  for (int tt=0; tt<q; ++tt) {
    int type;
    cin >> type;
    if (type == 1) {
      proc_new_edge();
      cout << hsh << endl;
      ////cerr << "  (" << ecount << endl;
    } else if (type == 2) {
      for (int i=0; i<=ecount; ++i) {
        curans[i] = 0;
      }
      for (int i=1; i<=n1+n2; ++i) {
        if (!label[i]) {
          continue;
        }
        int w = label[i];
        if (endpoints[w].first != i) {
          continue;
        }
        int idx = 0;
        for (auto& x : edges[w]) {
          //cerr << "          .FROM " << w << " : " << x << endl;
          curans[x] = idx%2+1;
          idx++;
        }
      }
      for (int i=1; i<=ecount; ++i) {
        if (!curans[i]) {
          curans[i] = color[i];
        }
      }
      int k = 0;
      for (int i=1; i<=ecount; ++i) {
        if (curans[i] == 1) {
          ++k;
        }
      }
      cout << k;
      for (int i=1; i<=ecount; ++i) {
        if (curans[i] == 1) {
          cout << " " << i;
        }
      }
      cout << endl;

    }
  }
  return 0;
}