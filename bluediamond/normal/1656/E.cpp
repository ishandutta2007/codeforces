#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 
#include <random> 
#include <chrono> 

bool home = true;

using namespace std;
typedef long long ll;


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    FILE* stream;
    freopen_s(&stream, "iron_man.txt", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int tests;
  cin >> tests;
  while (tests--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> sol(n, 0);
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    vector<int> que = { 0 };
    sol[0] = (int)g[0].size();
    for (int it = 0; it < (int)que.size(); it++) {
      int vertex = que[it];
      for (auto& v2 : g[vertex]) {
        if (!sol[v2]) {
          sol[v2] = -sol[vertex] / abs(sol[vertex]) * (int)g[v2].size();
          que.push_back(v2);
        }
      }
    }
    for (auto& x : sol) {
      cout << x << " ";
    }
    cout << "\n";
  }

}