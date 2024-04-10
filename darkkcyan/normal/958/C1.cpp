#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

#define maxn 101010
int n, p;
int a[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> p;
  rep1(i, n) cin >> a[i], (a[i] += a[i - 1]) %= p;
  int ans = 0;
  rep1(i, n - 1) {
    int s1 = a[i], s2 = a[n] - a[i];
    if (s2 < 0) s2 += p;
    ans = max(ans, s1 + s2);
  }
  cout << ans;

  return 0;
}