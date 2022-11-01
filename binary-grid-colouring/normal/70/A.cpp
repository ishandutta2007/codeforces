#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e6+3;
ll qpower(ll a,ll b)
{
  ll ans = 1;
  while(b){
    if(b&1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans ;
}
int main(int argc, char const *argv[]) {
  ll n;
  scanf("%lld", &n);
  if(n==0) {std::cout << "1" << '\n';return 0;}
  ll ans = qpower(3,n-1) % mod;
  printf("%lld\n", ans % mod);
  return 0;
}