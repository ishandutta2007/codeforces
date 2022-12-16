#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int mask[100100];
int maskc[1<<6];
int chc[10];

const int ss = 75, tt = 76;
const int N = 100;

struct Edge { int v, r; ll f, c, p; };
vector<Edge> adj[N]; int sz[N]; ll mc;
vector<Edge> mcf_edges; // for mcf on large graphs with negative costs
void init(int n=N) {
  mc=0; fill(sz,sz+n,0); fill(adj,adj+n,vector<Edge>()); }
void add_edge(int a, int b, ll c=1, ll p=0) { mc = max(mc,c); // scaling
  //cerr << "  " << a << " -> " << b << " ( cap " << c << ")" << endl;
  // mcf_edges.push_back({b,a,0,c,p});
	adj[a].push_back({b,sz[b]++,0,c,p});
	adj[b].push_back({a,sz[a]++,0,0,-p}); }

int get_flow(int u, int v) {
  int z = -1;
  for (int i=0; i<adj[u].size(); ++i) {
    if (adj[u][i].v == v) {
      z = i;
      break;
    }
  }
  assert(z != -1);
  return adj[u][z].f;
}

void add_flow_cap(int u, int v, int flow_amt, int cap_amt) {
  int z = -1;
  for (int i=0; i<adj[u].size(); ++i) {
    if (adj[u][i].v == v) {
      z = i;
      break;
    }
  }
  assert(z != -1);
  adj[u][z].f += flow_amt;
  adj[u][z].c += cap_amt;
  int oidx = adj[u][z].r;
  adj[v][oidx].f -= flow_amt;
}

int pa[N];
int ei[N];
int ca[N];
int augment(int ss, int tt) {
  memset(ca, 0, sizeof ca);
  ca[ss] = 1e9;
  queue<int> q;
  q.push(ss);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int i=0; i<adj[u].size(); ++i) {
      auto& e = adj[u][i];
      if (e.f == e.c) {
        continue;
      }
      if (!ca[e.v]) {
        ca[e.v] = min(e.c-e.f, (ll) ca[u]);
        pa[e.v] = u;
        ei[e.v] = i;
        q.push(e.v);
      }
    }
  }
  if (!ca[tt]) {
    return 0;
  }
  int x = tt;
  int flw = ca[tt];
  //cerr << " FLOW " << flw << endl;
  while (x != ss) {
    int p = pa[x];
    adj[p][ei[x]].f += flw;
    int oidx = adj[p][ei[x]].r;
    adj[x][oidx].f -= flw;
    x = p;
  }
  return flw;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  for (int i=1; i<=n; ++i) {
    mask[i] = 63;
    chc[s[i-1]-'a']++;
  }
  int m;
  cin >> m;
  for (int i=1; i<=m; ++i) {
    int idx;
    cin >> idx;
    mask[idx] = 0;
    string t;
    cin >> t;
    for (auto& c : t) {
      mask[idx] |= (1<<(c-'a'));
    }
  }
  for (int i=1; i<=n; ++i) {
    maskc[mask[i]]++;
  }
  for (int i=0; i<6; ++i) {
    add_edge(ss, 64+i, chc[i]);
  }
  for (int i=0; i<(1<<6); ++i) {
    add_edge(i, tt, maskc[i]);
    for (int r=0; r<6; ++r) {
      if (i&(1<<r)) {
        add_edge(r+64, i, 1e5);
      }
    }
  }

  int extra = 0;
  int flw = 0;
  while (extra = augment(ss, tt)) {
    flw += extra;
  }
  if (flw < n) {
    cout << "Impossible\n";
    return 0;
  }
  string ans;
  for (int i=1; i<=n; ++i) {
    int q = mask[i];
    for (int r=0; r<6; ++r) {
      if (!(q&(1<<r))) {
        continue;
      }
      int cur_flow = get_flow(r+64, q);
      if (cur_flow) {
        add_flow_cap(ss, r+64, -1, -1);
        add_flow_cap(r+64, q, -1, 0);
        add_flow_cap(q, tt, -1, -1);
        ans.push_back(r+'a');
        break;
      }
      int y = -1;
      for (int i=0; i<adj[r+64].size(); ++i) {
        if (adj[r+64][i].f > 0) {
          y = i;
          break;
        }
      }
      if (y == -1) {
        continue;
      }
      int z = -1;
      for (int i=0; i<adj[q].size(); ++i) {
        if (adj[q][i].f < 0) {
          z = i;
          break;
        }
      }
      if (z == -1) {
        continue;
      }
      add_flow_cap(r+64, adj[r+64][y].v, -1, 0);
      add_flow_cap(adj[q][z].v, q, -1, 0);
      add_flow_cap(ss, r+64, -1, -1);
      add_flow_cap(q, tt, -1, -1);
      add_flow_cap(ss, adj[q][z].v, -1, 0);
      add_flow_cap(adj[r+64][y].v, tt, -1, 0);
      if (augment(ss, tt)) {
        ans.push_back(r+'a');
        break;
      }
      add_flow_cap(r+64, adj[r+64][y].v, 1, 0);
      add_flow_cap(adj[q][z].v, q, 1, 0);
      add_flow_cap(ss, r+64, 1, 1);
      add_flow_cap(q, tt, 1, 1);
      add_flow_cap(ss, adj[q][z].v, 1, 0);
      add_flow_cap(adj[r+64][y].v, tt, 1, 0);
    }
  }
  cout << ans << endl;
  return 0;
}