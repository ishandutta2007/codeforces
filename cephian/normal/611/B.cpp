#include <iostream>
#include <sstream>
#include <set>
#include <algorithm>
#include <cstdio>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;

int lowest0(ll n) {
  int a = 0;
  while((1LL<<a)&n) ++a;
  return a;
}

ll hb (ll n)
{
    if (!n)
        return 0;
    ll r = 1;
    while (n >>= 1)
        r <<= 1;
    return r;
}

void pb(ll n) {
  while(n) {
    cout << (n&1);
    n/=2;
  }
  cout << endl;
}

ll advance(ll n) {
  int a = lowest0(n);
  if(n % 2 == 0) {
    n *= 2;
    n += 3;
    ll b = hb(n);
    n -= b/2;
  } else {
    n += (1LL<<a);
    n -= (1LL << (a-1));
  }
  return n;
}

int main() {
  ios::sync_with_stdio(0);
  ll a, b;
  cin >> a >> b;
  ll l = 2;
  ll ans = 0;
  while(l <= b) {
    // pb(l);
    if(l >= a)
      ++ans;
    l = advance(l);
  }
  cout << ans << "\n";

  return 0;
}