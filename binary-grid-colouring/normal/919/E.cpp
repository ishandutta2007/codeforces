#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll qpower(ll a,ll b, ll mod)
{
  ll ans = 1;
  while(b){
    if(b&1) ans = ans * a % mod;
    b>>=1;
    a=a*a%mod;
  }
  return ans;
}
ll a,b,mod,x;
int main(int argc, char const *argv[]) {
  std::cin >> a >> b >> mod >> x;
  ll ans = 0;
  for(int i=1;i <= mod-1;i++) {
    ll  c = qpower( qpower(a, i , mod) , mod-2, mod) * b % mod;
    ll  n = ((mod-1) * (mod-1) * c + mod * i) % (mod * (mod-1));
    ans += ( x / (mod * (mod-1)) ) + (x % (mod * (mod-1)) >= n );
  }
  std::cout << ans << '\n';
  return 0;
}