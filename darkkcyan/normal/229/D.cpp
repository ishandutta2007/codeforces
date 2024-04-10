#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 5050
int dp[maxn][maxn];
int midp[maxn][maxn];
int n;
int a[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep1(i, n) cin >> a[i];
  dp[0][0] = 0;
  memset(midp[0], 0, sizeof(midp[0]));
  rep1(i, n) {
    llong h = a[i - 1], th = a[i];
    int l = i - 1, r = i - 1;
    for (; r >= 0; --r) {
      while (l > 0 and h + a[l - 1] <= th) {
        --l;
        h += a[l];
      }
      if (h > th) dp[i][i - r] = maxn;
      else dp[i][i - r] = midp[r][min(r,r - l + 1)] + (i - r - 1);
      // clog << i << ' ' << l << ' ' << r <<' ' << dp[i][i - r] << ' ' << h << ' ' << th << endl;

      h -= a[r];
      th += a[r];
    }
    midp[i][0] = maxn;
    rep1(f, i) midp[i][f] = min(midp[i][f - 1], dp[i][f]);
  }
  cout << midp[n][n];
  
  return 0;
}