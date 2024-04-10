#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353; 
struct ModInt {
  int x;
  ModInt(int x = 0) : x(x + (x < 0) * MOD - (x >= MOD) * MOD){}
  ModInt operator+(ModInt o) { return x + o.x; }
  ModInt operator-(ModInt o) { return x - o.x; }
  ModInt operator*(ModInt o) { return 1LL * x * o.x % MOD; }
  ModInt operator/(ModInt b) { return *this * b.inv(); }
  ModInt inv() { return pow(MOD - 2); }
  ModInt pow(long long e) {
    if (!e) return 1;
    ModInt r = pow(e / 2); r = r * r;
    return e % 2 ? *this * r : r;
  }
  bool operator==(ModInt o) { return x == o.x; }
};

ModInt Solve(vector<string> M) {
  int n = M.size(), m = M[0].size();
  vector<vector<ModInt>> dp(n, vector<ModInt>(m, 0));
  vector<ModInt> pw(n * m, 1);
  ModInt ans = 0;
  for (int i = 1; i < n * m; ++i) 
    pw[i] = pw[i - 1] + pw[i - 1];

  int tot = 0, seen = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      tot += (M[i][j] == 'o');
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      seen += (M[i][j] == 'o');
      if (j == 0 || M[i][j] == '*' || M[i][j - 1] == '*') 
        continue;
      dp[i][j] = pw[seen - 2] - dp[i][j - 1];
      ans = ans + dp[i][j] * pw[tot - seen];
    }
  }
  cerr << "ans = " << ans.x << endl;
  return ans;
}

int main() {
  int n, m; cin >> n >> m;
  vector<string> M(n), T(m, string(n, '?'));
  for (int i = 0; i < n; ++i) {
    cin >> M[i];
    for (int j = 0; j < m; ++j)
      T[j][i] = M[i][j];
  }
  cout << (Solve(M) + Solve(T)).x << endl;

  return 0;
}