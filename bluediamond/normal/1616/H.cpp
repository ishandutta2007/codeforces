#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

void addup(int &a, int b) {
  a = add(a, b);
}

void mulup(int &a, int b) {
  a = mul(a, b);
}

int limit;

int solve(vector<int> v1, vector<int> v2, int bit) {
  if (bit == -1 || v1.empty() || v2.empty()) {
    /// no restrictions
    return add(pw(2, (int) v1.size() + (int) v2.size()), -1);
  }
  vector<vector<int>> k1(2), k2(2);
  for (auto &it : v1) {
    k1[!!(it & (1 << bit))].push_back(it);
  }
  for (auto &it : v2) {
    k2[!!(it & (1 << bit))].push_back(it);
  }
  if (limit & (1 << bit)) {
    /// v1 had restrictions with v2
    /// now k1[0] has restrictions with k2[1]
    /// now k1[1] has restrictions with k2[0]
    int X = solve(k1[0], k2[1], bit - 1);
    int Y = solve(k1[1], k2[0], bit - 1);
    return add(mul(add(X, 1), add(Y, 1)), -1);
  } else {
    /// v1 had restrictions with v2
    /// now k1[0] has restrictions with k2[0]
    /// now k1[1] has restrictions with k2[1]
    int sol = 0;
    addup(sol, solve(k1[0], k2[0], bit - 1));
    addup(sol, solve(k1[1], k2[1], bit - 1));
    /**

    restrictions:
    (k1[0], k2[0])
    (k1[1], k2[1])

    not allowed:
    (k1[0], k2[1])
    (k1[1], k2[0])

    I might have k1[0], k1[1] together or k2[0], k2[1] together but be careful to not count them twice

    2^(k1[0]) + 2^(k1[1]) - 1 is already counted so I need to subtract it

    **/


    assert((int) v1.size() == (int) k1[0].size() + (int) k1[1].size());
    assert((int) v2.size() == (int) k2[0].size() + (int) k2[1].size());

    addup(sol, pw(2, (int) v1.size()));
    addup(sol, pw(2, (int) v2.size()));

    addup(sol, -pw(2, (int) k1[0].size()));
    addup(sol, -pw(2, (int) k1[1].size()));
    addup(sol, -pw(2, (int) k2[0].size()));
    addup(sol, -pw(2, (int) k2[1].size()));
    addup(sol, 2);

    return sol;
  }
}

int solve(vector<int> v, int bit) {
  /// I care about the restrictions for every from v to every from v
  if (bit == -1 || v.empty()) {
    /// no restrictions
    return add(pw(2, (int) v.size()), -1);
  }
  vector<vector<int>> g(2);
  for (auto &it : v) {
    g[!!(it & (1 << bit))].push_back(it);
  }
  if (limit & (1 << bit)) {
    return solve(g[0], g[1], bit - 1);
  } else {
    return add(solve(g[0], bit - 1), solve(g[1], bit - 1));
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  //freopen ("input", "r", stdin);
  int n;
  cin >> n >> limit;
  vector<int> v(n);
  for (auto &x : v) {
    cin >> x;
  }
  cout << solve(v, 30) << "\n";
}