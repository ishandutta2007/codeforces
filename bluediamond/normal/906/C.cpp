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

const int N = 22;
int n;
int m;
int vecs[N];
int dp[1 << N];
pair<int, int> par[1 << N];

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


  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    vecs[i] |= (1 << i);
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    assert(0 <= a && a < n);
    assert(0 <= b && b < n);
    vecs[a] |= (1 << b);
    vecs[b] |= (1 << a);
  }
  for (int mask = 1; mask < (1 << n); mask++) {
    dp[mask] = (int)1e9 + 7;
  }
  vector<int> guys;
  for (int mask = 1; mask < (1 << n); mask++) {
    bool is = true;
    guys.clear();
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        is &= ((vecs[i] & mask) == mask);
        guys.push_back(i);
      }
    }
    if (is) {
      dp[mask] = 0;
    }
    for (auto& i : guys) {
      int nmask = mask | vecs[i];
      if (dp[mask] + 1 < dp[nmask]) dp[nmask] = 1 + dp[mask], par[nmask] = { mask, i };
    }
  }
  int mask = (1 << n) - 1;
  vector<int> path;
  while (dp[mask]) {
    path.push_back(par[mask].second);
    mask = par[mask].first;
  }
  reverse(path.begin(), path.end());
  cout << dp[(1 << n) - 1] << "\n";
  for (auto& x : path) {
    cout << x + 1 << " ";
  }
  cout << "\n";
}