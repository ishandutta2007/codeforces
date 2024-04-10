#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long double ld;

ld eps = 1e-10;

int main() {
  ld a, b, c;
  cin >> a >> b >> c;
  
  ld s[12];
  s[0] = log(a)*pow(b,c);
  s[1] = log(a)*pow(c,b);
  s[2] = log(a)*b*c;
  s[3] = s[2];
  s[4] = log(b)*pow(a,c);
  s[5] = log(b)*pow(c,a);
  s[6] = log(b)*a*c;
  s[7] = s[6];
  s[8] = log(c)*pow(a,b);
  s[9] = log(c)*pow(b,a);
  s[10] = log(c)*a*b;
  s[11] = s[10];
  
  string r[12];
  r[0] = "x^y^z";
  r[1] = "x^z^y";
  r[2] = "(x^y)^z";
  r[3] = "(x^z)^y";
  r[4] = "y^x^z";
  r[5] = "y^z^x";
  r[6] = "(y^x)^z";
  r[7] = "(y^z)^x";
  r[8] = "z^x^y";
  r[9] = "z^y^x";
  r[10] = "(z^x)^y";
  r[11] = "(z^y)^x";
  
  ld res = s[0];
  int in = 0;
  for (int i = 1; i < 12; ++i) {
    if (abs(res - s[i]) > eps and s[i] > res) {
      res = s[i];
      in = i;
    }
  }
  cout << r[in] << endl;
  
}