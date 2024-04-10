#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

template<class u>
pair<u, u> ordered_pair(const u& a, const u& b) {
  return a < b ? make_pair(a, b) : make_pair(b, a);
}

#define maxn 201010
int n, m, k;
set<int> gr[maxn];
vector<pair<int, int>> edge_list;
set<pair<int, int>> removed_edges;

struct cmp_deg {
  bool operator()(int u, int v) { return make_pair(len(gr[u]), u) < make_pair(len(gr[v]), v); }
};
set<int, cmp_deg> node_set;

void remove_edge(int u, int v) {
  node_set.erase(u);
  node_set.erase(v);
  gr[u].erase(v);
  gr[v].erase(u);
  node_set.insert(u);
  node_set.insert(v);
  removed_edges.insert(ordered_pair(u, v));
}

void remove_node(int u) {
  while (len(gr[u])) 
    remove_edge(u, *gr[u].begin());
  node_set.erase(u);
}

void adjust() {
  while (len(node_set) and len(gr[*node_set.begin()]) < k) {
    remove_node(*node_set.begin());
  }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    rep(i, m) {
      int u, v; cin >> u >> v;
      gr[u].insert(v);
      gr[v].insert(u);
      edge_list.push_back(ordered_pair(u, v));
    }

    rep1(i, n) 
      node_set.insert(i);

    vector<int> ans(m);
    for (int i = m; i--; ) {
      adjust();
      ans[i] = len(node_set);
      if (!removed_edges.count(edge_list[i])) {
        remove_edge(edge_list[i].xx, edge_list[i].yy);
      }
    }
    for (auto i: ans) cout << i << '\n';


    return 0;
}