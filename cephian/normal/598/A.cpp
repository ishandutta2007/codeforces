#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
  int T;
  cin >> T;
  while(T--) {
    ll n;
    cin >> n;
    ll sum = (n*(n+1))/2;
    ll pw2 = 1;
    while(n > 1) {
      n/=2;
      pw2 *=2;
    }
    cout << sum- 4*pw2+2 << "\n";
  }
  return 0;
}