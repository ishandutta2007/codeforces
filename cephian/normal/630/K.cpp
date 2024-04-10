#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

int a[4] = {2,3,5,7};

int bc(int m) {
  int a=0;
  while(m) {
    a += m&1;
    m/=2;
  }
  return a;
}

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    for(int m = 0; m < 16; ++m) {
      int p = 1;
      if(bc(m)&1) p = -1;
      ll f = 1;
      for(int i = 0; i < 4; ++i) {
        if(m&(1<<i)) {
          f *= a[i];
        }
      }
      ans += p*(n/f);
    }
    cout << ans << "\n";
    return 0;
}