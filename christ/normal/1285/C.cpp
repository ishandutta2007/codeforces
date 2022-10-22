#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define all(x) (x).begin(),(x).end()
const int MN = 2e5+3, MOD = 1e9+7;
int main () {
  ll a;
  scanf ("%lld",&a);
  ll cur = a; pll ret = {a,1};
  for (ll i = 2; i * i <= cur; i++) if (cur%i==0) {
    if (__gcd(i,a/i) == 1) ret = min(ret,pll{max(a/i,i),min(a/i,i)});
  } 
  assert(__gcd(ret.first,ret.second) == 1);
  printf ("%lld %lld\n",ret.first,ret.second);
  return 0;
}