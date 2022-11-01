#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
const int mod = 1e9+7;
const ll INF =2e15;

ll power[maxn],cnt[maxn];
ll dp[maxn];

int main(int argc, char const *argv[]) {
  power[0] = 1;
  for(int i=1;i<=200000;i++) {
    power[i] = power[i-1] * 2LL % mod;
  }
  int n;
  std::cin >> n;
  int maxx = 0;
  for(int i=1;i<=n;i++) {
    int x;
    std::cin >> x;
    cnt[x] ++;
    maxx = max(maxx,x);
  }
  ll ans = 0;
  for(int i = maxx;i > 1;--i) {
    ll tmp = 0;
    for(int j = i;j <= maxx; j+=i) {
      tmp += cnt[j];
    }
    if(tmp==0) continue;
    dp[i] = tmp * power[tmp - 1] % mod;
    for(int j = 2 * i; j <= maxx; j += i)
    {
      dp[i] = (dp[i] - dp[j] + mod) % mod;
    }
    ans = (ans + dp[i] * i) % mod;
  }
  std::cout << ans << '\n';
  return 0;
}