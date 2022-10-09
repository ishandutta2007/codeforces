#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  int t; cin >> t;
  while (t--) {
    llong a, b; cin >> a >> b;
    if (b == 0) {
      cout << "1\n";
      continue;
    }
    if (a == 0) {
      cout << "0.5\n";
      continue;
    }
    llong t = b * 4;
    long double s = a * b;
    if (t < a) {
      s += (2 * a - t) * b / 2.0;
    } else {
      s += a * a / 8.0;
    }
    b *= 2;
    cout << fixed << setprecision(12) << s / (a * b) << '\n';
  }
  
  
  return 0;
}