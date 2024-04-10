#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

#define maxn 1010101
bool isnp[maxn] = {0};
vector<int> p;
void sieve() {
  for (int i = 2; i < maxn; ++i) {
    if (isnp[i]) continue;
    p.push_back(i);
    for (llong f = (llong)i * i; f < maxn; f += i) {
      isnp[f] = 1;
    }
  }
}

int dp[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  sieve();
  rep(i, maxn) dp[i] = INT_MAX;
  for (auto i: p) {
    for (llong f = 2; f * i < maxn; ++f) {
      dp[f * i] = min(dp[f * i], (int)f * i - i + 1);
    }
  }
  //for (int i = maxn - 1; i--; ) dp[i] = min(dp[i], dp[i + 1]);
  rep(i, 20) clog << i << ' ' << dp[i] << endl;
  int ans = INT_MAX;
  int x; cin >> x;
  for (auto i: p) {
    if (x % i) continue;
    for (int f = x - i + 1; f < x; ++f) {
      ans = min(ans, dp[f]);
      ans = min(ans, f);
    }
  }
  cout << ans;

  return 0;
}