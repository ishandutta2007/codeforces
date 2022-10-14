#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using ll = long long;
using pii = pair<int, int>;
//#define int ll
const int MOD = 1000000007;

int dp[35005][55];
int ar[35005];
int pr[35005];

int seg[35005 << 2];
int laza[35005 << 2];
void pd(int idx, int l, int r) {
  if (r - l == 1)
    return;
  seg[idx * 2] += laza[idx];
  laza[idx * 2] += laza[idx];
  seg[idx * 2 + 1] += laza[idx];
  laza[idx * 2 + 1] += laza[idx];
  laza[idx] = 0;
}
void tag(int idx, int l, int r, int v) {
  laza[idx] += v;
  seg[idx] += v;
}
void aaa(int idx, int l, int r, int L, int R, int v) {
  if (L <= l && r <= R)
    return tag(idx, l, r, v);
  if (R <= l || r <= L)
    return;
  pd(idx, l, r);
  aaa(idx * 2, l, (l + r) / 2, L, R, v);
  aaa(idx * 2 + 1, (l + r) / 2, r, L, R, v);
  seg[idx] = max(seg[idx * 2], seg[idx * 2 + 1]);
  // cout << idx << ' ' << l << ' ' << r << ' ' << seg[idx] << endl;
}
int qmax(int idx, int l, int r, int L, int R) {
  if (L <= l && r <= R)
    return seg[idx];
  if (R <= l || r <= L)
    return -1000000000;
  pd(idx, l, r);
  return max(qmax(idx * 2, l, (l + r) / 2, L, R),
             qmax(idx * 2 + 1, (l + r) / 2, r, L, R));
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> ar[i];
  memset(pr, 0, sizeof pr);
  int icx = 0;
  dp[0][1] = -1000000000;
  for (int i = 1; i <= n; i++) {
    icx += (pr[ar[i]] == 0);
    pr[ar[i]] = i;
    dp[i][1] = icx;
  }
  for (int j = 2; j <= k; j++) {
    memset(seg, 0, sizeof seg);
    memset(laza, 0, sizeof laza);
    memset(pr, 0, sizeof pr);
    for (int i = 0; i <= n; i++) {
      // seg[i] = dp[i][j - 1];
      aaa(1, 0, n + 1, i, i + 1, dp[i][j - 1]);
      // cout << dp[i][j - 1] << endl;
    }
    dp[0][j] = -1000000000;
    for (int i = 1; i <= n; i++) {
      // for (int z = pr[ar[i]]; z < i; z++)
      // seg[z]++;
      aaa(1, 0, n + 1, pr[ar[i]], i, 1);
      // int t = -1000000000;
      // for (int z = 0; z < i; z++)
      // t = max(t, seg[z]);
      // dp[i][j] = t;
      dp[i][j] = qmax(1, 0, n + 1, 0, i);
      pr[ar[i]] = i;
    }
    // for (int i = 1; i <= n; i++) {
    //   int cnt = 0, x = -1000000000;
    //   memset(pr, 0, sizeof pr);
    //   for (int v = i; v >= 1; v--) {
    //     if (pr[ar[v]] == 0)
    //       cnt++;
    //     pr[ar[v]] = v;
    //     x = max(x, cnt + dp[v - 1][j - 1]);
    //   }
    //   if (x != dp[i][j])
    //     cout << "no " << i << ' ' << j << ' ' << x << ' ' << dp[i][j] << endl;
    // }
  }
  cout << dp[n][k] << endl;
}