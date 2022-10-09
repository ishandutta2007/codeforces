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
  int x, t, a, b, c, d; cin >> x >> t >> a >> b >> c >> d;
  if (x == 0) cout << "YES", exit(0);
  rep(u, t) {
    if (a - u * c == x or b - u * d == x) cout << "YES", exit(0);
  }
  rep(u, t) rep(v, t) {
    if (a - u * c + b - v * d == x) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  
  return 0;
}