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
  llong a, b; cin >> a >> b;
  if (b - a > 20) cout << 0;
  else {
    llong ans = 1;
    for (llong i = a + 1; i <= b; ++i) (ans *= i) %= 10;
    cout << ans;
  }
  
  return 0;
}