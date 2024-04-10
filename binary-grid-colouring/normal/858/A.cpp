#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
const int mod = 1e9+7;
const ll INF =2e15;

ll qpower(ll a,ll b )
{
  ll ans = 1;
  while(b>0) {
    if(b&1) ans = ans * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return ans;
}
ll n,k;
int main(int argc, char const *argv[]) {
  std::cin >> n >> k;
  if(k==0) {
    std::cout << n << '\n';
    return 0;
  }
  int cnt = 0 ;
  for(int i=0;i<k;i++) {
    if(n%10==0) {
      cnt++;
      n /= 10;
    }
    else break;
  }
  for(int i=cnt;i<k;i++) {
    if(n % 5==0) n /= 5;
    if(n % 2==0) n /= 2;
  }
  for(int i=1;i<=k;i++) {
    n*=10;
  }
  std::cout << n << '\n';
  return 0;
}