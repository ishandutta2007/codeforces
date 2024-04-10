#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  llong a, b, x, y;
  cin >> a >> b >> x >> y;
  
  llong g = __gcd(x, y);
  x /= g;
  y /= g;
  cout << min(a / x, b / y);



  return 0;
}