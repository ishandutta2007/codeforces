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
#include <cstdio> 

using namespace std;

typedef long long ll;

const int M = 998244353;

int n, a[1 << 20], dp[1 << 20];

vector<int> solve(int v) {
  if (2 * v > n) {
    dp[v] = 1;
    return { a[v] };
  }
  vector<int> x = solve(2 * v), y = solve(2 * v + 1);
  if (x > y) swap(x, y);

  dp[v] = (ll) dp[2 * v] * dp[2 * v + 1] % M;

  if (x != y) {
    dp[v] = (ll) dp[v] * 2 % M;
  }

  vector<int> sol = { a[v] };
  for (auto& it : x) sol.push_back(it);
  for (auto& it : y) sol.push_back(it);
  return sol;
}

signed main() {

  string s;
  cin >> n >> s;
  n = (1 << n) - 1;
  for (int i = 1; i <= n; i++) a[i] = s[i - 1] - 'A';

  solve(1);
  cout << dp[1] << "\n";
}