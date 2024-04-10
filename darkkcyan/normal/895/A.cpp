#include <bits/stdc++.h>
using namespace std;
#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())

#define maxn 444
int n;
int a[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep(i, n) cin >> a[i];
  
  llong ans = 360;
  rep(i, n) rep(f, n) {
    llong t = a[f];
    for (int g = i; g != f; g = (g + 1) %n) t += a[g];
    ans = min(ans, abs(360 - 2 * t));
  }
  cout << ans;

  return 0;
}