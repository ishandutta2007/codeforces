#ifdef LOCAL
#include <debug.hpp>
#else
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#define debug(...)
#endif 

#include <bits/stdc++.h>

using namespace std;

struct ST {
  map<int, int> ltor;
  vector<tuple<int, int, int, int>> history;

  void Insert(int l, int r) {
    //cerr << "insert: " << l << " " << r << endl;
    auto it = ltor.lower_bound(l);
    if (it != ltor.end() && it->second < r) {
      history.emplace_back(-1, -1, -1, -1);
      return;
    }
    if (it == ltor.begin()) {
      ltor[l] = r;
      history.emplace_back(-1, -1, l, r);
    } else {
      --it;
      auto [oldl, oldr] = *it;
      if (oldr < l) {
        history.emplace_back(-1, -1, l, r);
        ltor[l] = r;
      } else {
        assert(oldr > r);
        ltor.erase(it);
        history.emplace_back(oldl, oldr, l, r);
        ltor[l] = r;
      }
    }
    //dump();
  }

  void dump() {
    for (auto [l, r] : ltor)
      cerr << "[" << l << " " << r << "] ";
    cerr << endl;
  }
  
  void Undo() {
    //cerr << "undo" << endl;
    auto [oldl, oldr, newl, newr] = history.back();
    history.pop_back();
    if (newl != -1) {
      auto it = ltor.find(newl);
      assert(it != ltor.end() && it->second == newr);
      ltor.erase(it);
    }
    if (oldl != -1) ltor[oldl] = oldr;
    //dump();
  }

  int Get() { return ltor.size(); }
};

vector<vector<int>> graph1, graph2;
vector<int> lf, rt;
ST st;
int timer, answer;

void DFS1(int node) {
  lf[node] = timer++;
  for (auto vec : graph2[node]) {
    DFS1(vec);
  }
  rt[node] = timer++;
}
void DFS2(int node) {
  st.Insert(lf[node], rt[node]);
  answer = max(answer, st.Get());
  for (auto vec : graph1[node])
    DFS2(vec);
  st.Undo();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    graph1.assign(n, {});
    graph2.assign(n, {});
    lf.assign(n, -1);
    rt.assign(n, -1);
    timer = 0;
    for (int i = 1; i < n; ++i) {
      int par; cin >> par;
      graph1[par - 1].push_back(i);
    }
    for (int i = 1; i < n; ++i) {
      int par; cin >> par;
      graph2[par - 1].push_back(i);
    }
    answer = 0;
    DFS1(0);
    DFS2(0);
    cout << answer << '\n';
  }
  return 0;
}