#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
  if(b==0) return a;
  return gcd(b,a%b);
}

ll lcm(ll a, ll b) {
  return (a/gcd(a,b))*b;
}

int main() {
  ll n,a,b,p,q;
  cin >>n>>a>>b>>p>>q;
  ll l = lcm(a,b);
  ll ans = (n/a - n/l)*p + (n/b-n/l)*q + (n/l)*max(p,q);
  cout << ans << "\n";
}