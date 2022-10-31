#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

ll choose(ll n, ll r) {
  if(r > n) return 0;
  if(r == 0) return 1;
  ll p = choose(n,r-1);
  p *= (n-r+1);
  p /= r;
  return p;
}

int main() {
    ll n;
    cin >> n;
    cout << choose(n,5) + choose(n,6) + choose(n,7) << "\n";
    return 0;
}