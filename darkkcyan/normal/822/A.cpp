#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++i < n; )
#define sz(v) ((int)v.size())

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  llong a, b; cin >> a >> b;
  a = min(a, b);
  llong ans = 1;
  for (int i = 2; i <= a; ++i) ans *= i;
  cout << ans;
  return 0;
}