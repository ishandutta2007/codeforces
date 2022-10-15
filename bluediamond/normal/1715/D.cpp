#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 7;

struct T {
  int i, j, x;
};

int n;
int q;
int print[N];
T v[N];
int sol[N];
vector<int> g[N];

signed main() {

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE


  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    cin >> v[i].i >> v[i].j >> v[i].x;
  }

  for (int bit = 0; bit < 30; bit++) {
    for (int i = 1; i <= n; i++) {
      sol[i] = -1;
      g[i].clear();
    }
    vector<pair<int, int>> at_least, none;
    for (int i = 1; i <= q; i++) {

      if (v[i].x & (1 << bit)) {
        if (v[i].i == v[i].j) {
          sol[v[i].i] = 1;
        } else {
          at_least.push_back({v[i].i, v[i].j});
        }
      } else {
        none.push_back({v[i].i, v[i].j});
      }
    }
    for (auto &it : none) {
      sol[it.first] = sol[it.second] = 0;
    }
    for (auto &it : at_least) {
      g[it.first].push_back(it.second);
      g[it.second].push_back(it.first);
    }
    for (int i = 1; i <= n; i++) {
      if (sol[i] != -1) continue;
      bool ok0 = 1;
      for (auto &j : g[i]) {
        ok0 &= (sol[j] != 0);
      }
      sol[i] = !ok0;
    }
    for (int i = 1; i <= n; i++) {
      assert(sol[i] == 0 || sol[i] == 1);
      print[i] += (1 << bit) * sol[i];
    }
  }



  for (int i = 1; i <= n; i++) {
    cout << print[i] << " ";
  }
  cout << "\n";

  return 0;
}