#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 4002;
const int M = 802;

int a[N][N], sum[N][N];
int dp[N], cnt[N];
int n, K;

int q[N], h, t;
int k;

// (l, r]
ll calc(ll l, ll r) {
  return (sum[r][r] - sum[l][r] - sum[r][l] + sum[l][l]) >> 1;
}

int get_f(int i, int j) {
  int l = j + 1, r = n + 1;
  while (l < r) {
    int mid = l + r >> 1;
    int t1 = dp[i] + calc(i, mid);
    int t2 = dp[j] + calc(j, mid);
    if (t1 > t2 || (t1 == t2 && cnt[i] > cnt[j]))
      r = mid;
    else
      l = mid + 1;
  }
  return l;
}

bool check(int mid) {
  h = 1, t = 1; q[h] = 0;
  for (register int i = 1; i <= n; i++) {
    while (h < t && get_f(q[h], q[h + 1]) <= i) h++;
    int H = q[h];
    dp[i] = dp[H] + calc(H, i) + mid;
    cnt[i] = cnt[H] + 1;
    while (h < t && get_f(q[t - 1], q[t]) > get_f(q[t], i)) t--;
    q[++t] = i;
  } 
  return cnt[n] <= K;
}

int main() {
  scanf("%d%d", &n, &K);
  int Sum = 0;
  for (register int i = 1; i <= n; i++) {
    for (register int j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
      Sum += a[i][j];
    }
  }
  for (register int i = 1; i <= n; i++) {
    for (register int j = 1; j <= n; j++) {
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
      //printf("sum[%d][%d] = %lld\n", i, j, sum[i][j]);
    }
  }
  
  //printf("%lld %lld %lld %lld\n", sum[5][5], sum[3][5], sum[5][3], sum[3][3]);
  //printf("%lld\n", calc(3, 5));
  
  int l = 0, r = Sum, ans = 0;
  while (l <= r) {
    int mid = l + r >> 1;
    if (check(mid)) r = mid - 1, ans = dp[n] - mid * K;
    else l = mid + 1;
  }
  printf("%d\n", ans);
  return 0;
}