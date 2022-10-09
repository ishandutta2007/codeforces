#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 101010
int n, m, k;
int a[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m >> k;
  rep(i, n) cin >> a[i];
  if (n % 2 == 0) {
    cout << 0;
    return 0;
  }
  llong ans = (llong)m /((n + 1) / 2)* k;
  for (int i = 0; i < n; i += 2) ans = min(ans, (llong)a[i]);
  cout << ans;
  
  return 0;
}