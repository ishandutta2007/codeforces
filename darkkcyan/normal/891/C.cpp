#include <bits/stdc++.h>
using namespace std;

#define llong long long /*{{{*/
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
#define _pt(x) typename iterator_traits<x>::value_type
template<class u> vector<_pt(u)> tovec(u a, u b) { return vector<_pt(u)>(a, b); }
template<class x> ostream& operator<<(ostream& cout, const vector<x>& a) {
  cout << "[";
  rep(i, len(a)) cout << a[i] << (i == len(a) - 1 ? "" : ", ");
  return cout << "]";
}
template<class u, class v> ostream& operator<<(ostream& cout, const pair<u, v>& a) {
  return cout << a.xx << ": " << a.yy;
}/*}}}*/

struct edge {
  int u, v, w;
  edge() {}
};

#define maxn 501010
int n, m, q;
edge edgeList[maxn];
vector<edge> groupedEdgeList[maxn];
vector<int> query[maxn];
vector<int> queryGroup[maxn];

int dsu[maxn], cacheDsu[maxn];
vector<int> changes;
void assignDsu(int u, int val) {
  if (cacheDsu[u] == -1) {
    changes.push_back(u);
    cacheDsu[u] = dsu[u];
  }
  dsu[u] = val;
}

int findp(int u) {
  if (dsu[u] != u) 
    assignDsu(u, findp(dsu[u]));
  return dsu[u];
}

void join(int u, int v) {
  if (rand() & 1) swap(u, v);
  assignDsu(findp(u), findp(v));
}

void clearCache() {
  for (auto i: changes) cacheDsu[i] = -1;
  changes.clear();
}

void rollBack() {
  for (auto i: changes)dsu[i] = cacheDsu[i];
  clearCache();
}

bool ans[maxn];
int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  rep1(i, m) {
    cin >> edgeList[i].u >> edgeList[i].v >> edgeList[i].w;
    groupedEdgeList[edgeList[i].w].push_back(edgeList[i]);
  }

  cin >> q;
  rep(i, q) {
    int k; cin >> k;
    query[i].resize(k);
    for (auto& f: query[i]) {
      cin >> f;
      int cost = edgeList[f].w;
      if (!len(queryGroup[cost]) or queryGroup[cost].back() != i)
        queryGroup[cost].push_back(i);
    }
    sort(all(query[i]), [](int u, int v) {
        return edgeList[u].w > edgeList[v].w;
      });
    ans[i] = 1;
  }

  rep1(i, n) {
    dsu[i] = i;
    cacheDsu[i] = -1;
  }

  rep(cost, maxn) {
    for (auto f: queryGroup[cost]) {
      for (; ans[f] == 1 and len(query[f]) and edgeList[query[f].back()].w == cost; query[f].pop_back()) {
        edge& e = edgeList[query[f].back()];
        if (findp(e.u) == findp(e.v))
          ans[f] = 0;
        else join(e.u, e.v);
      }
      rollBack();
    }

    for (auto e: groupedEdgeList[cost])
      join(e.u, e.v);
    clearCache();
  }
  
  rep(i, q) cout << (ans[i] ? "YES" : "NO") << '\n';
  return 0;
}