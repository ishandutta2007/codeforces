#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  llong ans = LLONG_MIN;
  while (n--) {
    llong a; cin >> a;
    if (a < 0) ans = max(ans, a);
    else if ((llong)sqrt(a) * (llong)sqrt(a) != a) ans = max(ans, a);
  }
  cout << ans;

  return 0;
}