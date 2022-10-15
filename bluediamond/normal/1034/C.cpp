#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e6 + 7;
const int M = (int) 1e9 + 7;
int n;
int cnt[N];
int dp[N];
ll s[N];
vector<int> g[N];

void dfs(int a) {
  for (auto &b : g[a]) {
    dfs(b);
    s[a] += s[b];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    g[p].push_back(i);
  }
  dfs(1);
  for (int i = 1; i <= n; i++) {
    ll x = s[1] / __gcd(s[1], s[i]);
    if (x <= n) {
      cnt[x]++;
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 2 * i; j <= n; j += i) {
      cnt[j] = (cnt[j] + cnt[i]) % M;
    }
  }
  int sol = 0;
  dp[1] = 1;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == i) {
      for (int j = 2 * i; j <= n; j += i) {
        dp[j] = (dp[j] + dp[i]) % M;
      }
      sol = (sol + dp[i]) % M;
    }
  }
  cout << sol << "\n";
}