#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
const int mod = 1e9+7;
const ll INF =2e15;
std::vector<ll> a,b;
int vis[maxn];
int ans[maxn];
std::map<int, int> mp;
int main(int argc, char const *argv[]) {
  int n,t;
  std::cin >> t;
  for(int i=1;i<=t;i++) {
    int a;
    std::cin >> n;
    for(int i=2;i*i<=n;i++) {
      if(n%i==0) {
        mp[i]++;
      }
      while (n%i==0) {
       n/=i;
      }
    }
    if(n > 1)mp[n]++;
  }

  int ans = 1;
  for(auto x:mp) {
    ans = max(ans,x.second);
  }
  std::cout << ans << '\n';
  return 0;
}