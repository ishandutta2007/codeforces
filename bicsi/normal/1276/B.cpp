#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
 
using namespace std;
 
 
struct BCC {
  int n;
  vector<pair<int, int>> edges;
  vector<vector<int>> G;
  vector<int> enter, low, stk;
  
  BCC(int n) : n(n), G(n), enter(n, -1), which(n) {}
  
  int AddEdge(int a, int b) {
    int ret = edges.size();
    edges.emplace_back(a, b);
    G[a].push_back(ret);
    G[b].push_back(ret);
    return ret;
  }
  
  vector<vector<int>> comps, which;
 
  template<typename Iter>
  void Callback(Iter bg, Iter en) {
    vector<int> comp;
    for (Iter it = bg; it != en; ++it) {
      auto edge = edges[*it];
      comp.push_back(edge.first);
      comp.push_back(edge.second);
    }
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    
    //cerr << "CALLBACK: ";
    //for (auto x : comp) cerr << x + 1 << " "; cerr << endl;
 
    for (auto x : comp) {
      which[x].push_back(comps.size());
    }
    comps.push_back(comp);
  }
 
  void Merge(set<int>& big, set<int>& small) {
    if (big.size() < small.size()) swap(small, big);
    for (auto x : small) big.insert(x);
  }
  
  long long Solve(int a, int b) {
    //cerr << "SOLVING: " << a + 1 << " " << b + 1 << endl;
    dfs(a, -1);
 
    if (which[a].size() == 1 || which[b].size() == 1) {
      return 0;
    }
 
 
    vector<set<int>> nodes(n);
    vector<bool> seen(n, false);
 
    for (int i = 0; i < n; ++i)
      nodes[i].insert(i);
 
    int sub_b = 0, sub_a = n - 1;
 
    for (int i = 0; i < (int)comps.size(); ++i) {
      int to = -1;
      for (auto x : comps[i]) {
        if (which[x].size() >= 2) {
          if (to == -1 || enter[to] > enter[x]) {
            to = x;
          }
        }
      }
 
      if (to != b) {
        bool flag = false;
        for (auto x : comps[i]) {
          if (x == b) {
            flag = true;
            break;
          }
        }
        if (flag) {
          for (auto x : {b}) {
            sub_b += nodes[x].size();
            if (nodes[x].count(b))
              sub_b -= 1;
          }
        }
      }
 
      if (to == a) {
        bool flag = false;
        for (auto x : comps[i]) {
          if (x == a) continue;
          if (nodes[x].count(b)) {
            flag = true;
            break;
          }
        }
        if (flag) {
          for (auto x : comps[i]) {
            if (x == a) continue;
            sub_a -= nodes[x].size();
            if (nodes[x].count(a))
              sub_a += 1;
          }
        }
      }
 
      if (to != -1) {
        // seen[to] = true;
        for (auto x : comps[i]) {
            if (to != x) {
          Merge(nodes[to], nodes[x]);
            }
        }
      }
    }
 
    //cerr << sub_a << " " << sub_b << endl;
 
    return 1LL * sub_a * sub_b;
  }
  
  int timer = 0;
  int dfs(int node, int pei) {
    //cerr << "DFS: " << node << endl;
    enter[node] = timer++;
    int ret = enter[node];
    
    for (auto ei : G[node]) if (ei != pei) {
      int vec = (edges[ei].first ^ edges[ei].second ^ node);
      if (enter[vec] != -1) {
        ret = min(ret, enter[vec]);
        if (enter[vec] < enter[node])
          stk.push_back(ei);
      } else {
        int sz = stk.size(), low = dfs(vec, ei);
        ret = min(ret, low);
        stk.push_back(ei);
        if (low >= enter[node]) {
          Callback(stk.begin() + sz, stk.end());
          stk.resize(sz);
        }
      }
    }
    return ret;
  }
};
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m, x, y; 
    cin >> n >> m >> x >> y; 
    --x; --y;
    BCC bcc(n);
    for (int i = 0; i < m; ++i) {
      int a, b; cin >> a >> b; --a; --b;
      bcc.AddEdge(a, b);
    }
    long long ret = bcc.Solve(x, y);
    cout << ret << '\n';
  }
  return 0;
}