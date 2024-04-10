#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 800
int dp[maxn][maxn][2] = {0};

int n;
int a[maxn];
bool gr[maxn][maxn] = {0};

bool get(int l, int r, bool isright) {
  if (l > r) return true;
  // clog << l << ' ' << r << ' ' << isright << ' ' << dp[l][r][isright] << endl;
  if (dp[l][r][isright] != -1) return (bool)dp[l][r][isright];
  int pid = isright ? l - 1 : r + 1;
  dp[l][r][isright] = 0;
  for (int i = l; i <= r; ++i) {
    if (!gr[i][pid]) continue;
    if (get(l, i - 1, 0) and get(i + 1, r, 1)) {
      dp[l][r][isright] = 1;
      break;
    }
  }
  // clog << l << ' ' << r << ' ' << isright << ' ' << a[pid] << ' ' << dp[l][r][isright] << endl;
  return dp[l][r][isright];
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep(i, n) cin >> a[i];
  rep(i, n) rep(f, n) if (__gcd(a[i], a[f]) > 1) gr[i][f] = 1;
  
  memset(dp, -1, sizeof(dp));
  rep(i, n) {
    // clog << i << endl;
    if (get(0, i - 1, 0) and get(i + 1, n - 1, 1)) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
  
  return 0;
}