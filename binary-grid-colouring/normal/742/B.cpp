#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
const int mod = 1e9+7;
const ll INF =2e15;
int a[maxn],b[maxn];
int vis[maxn];
int ans[maxn];
std::map<int, int> mp;
int main(int argc, char const *argv[]) {

  int n;
  int x;
  std::cin >> n >> x;
  int maxx = 0;
  for(int i=0;i<n;i++) {
    std::cin >> a[i];
    mp[a[i]]++;
    maxx = max(maxx,a[i]);
  }
  ll ans = 0;
  if(x==0) {
    for(int i=1;i<=maxx;i++) {
      if(mp[i]>=1) {
        ans += 1LL*(mp[i]) * (mp[i]-1) / 2 ;
      }
    }
    std::cout << ans << '\n';
    return 0;
  }
  ll cnt = 0;
  for(int i=0;i<n;i++) {
    int tmp = a[i];
    if(mp[a[i]^x]>=1) {
      cnt += mp[a[i]^x];
    }
  }
  if(x) cnt /= 2;
  std::cout << cnt << '\n';
  return 0;
}