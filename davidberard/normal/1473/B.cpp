#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    string s,t;
    cin >> s >> t;
    int a = s.size();
    int b = t.size();
    int z = a*b/__gcd(a,b);
    string x, y;
    for (int i=0; i<z; i+=a) {
      x += s;
    }
    for (int i=0; i<z; i+=b) {
      y += t;
    }
    //cerr << "! " << x << " " << y << endl;
    if (x == y) {
      cout << x << "\n";
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}