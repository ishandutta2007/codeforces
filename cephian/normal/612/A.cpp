#include <iostream>

using namespace std;
typedef long double ld;

int n, p, q;
string s;

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> p >> q >> s;
  for(int i = 0; i*p <=n; ++i) {
    if((n-i*p)%q == 0) {
      cout << i + (n-i*p)/q << "\n";
      for(int j = 0; j < i; ++j)
        cout << s.substr(j*p,p) << "\n";
      for(int k = 0; k < (n-i*p)/q; ++k)
        cout << s.substr(i*p+k*q, q) << "\n";
      return 0;
    }
  }

  cout << "-1\n";
  return 0;
}