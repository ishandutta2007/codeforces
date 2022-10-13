#include <bits/stdc++.h>
 
using namespace std;
 
vector<vector<int>> graph;
vector<int> a;
vector<vector<tuple<int, int, int>>> qrs;
vector<int> ans;
vector<int> frq;
vector<int> lf, sf, pos;
 
void Dump() {
  int j = 0;
  for (int i = 0; i < (int)lf.size(); ++i) {
    while (j < lf[i])
      cerr << sf[j++] << " ";
    cerr << " | ";
  }
  cerr << endl;
}
void Rem(int x) {
  int f = frq[x], y = sf[lf[f]];
  lf[f] += 1; frq[x] -= 1;
  swap(sf[pos[x]], sf[pos[y]]);
  swap(pos[x], pos[y]);
  //cerr << "rem: " << x;
  //Dump();
}
void Add(int x) {
  int f = frq[x], y = sf[lf[f + 1] - 1];
  lf[f + 1] -= 1; frq[x] += 1;
  swap(sf[pos[x]], sf[pos[y]]);
  swap(pos[x], pos[y]);
  //cerr << "add: " << x ;
  //Dump();
}
void DFS(int node) {
  Add(a[node]);
  
  for (auto [l, k, i] : qrs[node]) {
    int p = lf[l];
    if (p + k - 1 < (int)sf.size()) 
      ans[i] = sf[p + k - 1];
  }
  for (auto vec : graph[node]) 
    DFS(vec);
  
  Rem(a[node]);
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int t; cin >> t;
  while (t--) {
    int n, q; cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i]; --a[i];
    }
    graph.resize(n);
    for (int i = 0; i < n; ++i)
      graph[i].clear();
    for (int i = 1; i < n; ++i) {
      int p; cin >> p; --p;
      graph[p].push_back(i);
    }
    qrs.resize(n);
    for (int i = 0; i < n; ++i)
      qrs[i].clear();
    for (int i = 0; i < q; ++i) {
      int v, l, k; cin >> v >> l >> k;
      qrs[v - 1].emplace_back(l, k, i);
    }
    ans.resize(q);
    frq.resize(n + 1);
    for (int i = 0; i <= n; ++i)
      frq[i] = 0;
    for (int i = 0; i < q; ++i)
      ans[i] = -1;
 
    lf.assign(n + 2, n);
    sf.resize(n);
    pos.resize(n);
    for (int i = 0; i < n; ++i) {
      sf[i] = i;
      pos[i] = i;
    }
    lf[0] = 0;
 
    DFS(0);
    for (int i = 0; i < q; ++i) {
      if (ans[i] >= 0) ++ans[i];
      cout << ans[i] << " ";
    }
    cout << '\n';
  }
 
  return 0;
}