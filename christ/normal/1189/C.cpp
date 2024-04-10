#include <bits/stdc++.h>
using namespace std;
int bit[100001];
int dp[100001][18];
int query (int n) {
  int ret = 0;
  for (n++;n>0;n-=(n&-n))
    ret += bit[n];
  return ret;
}
void update (int n, int v) {
  for (n++;n<=100000;n+=(n&-n))
    bit[n] += v;
}
int query (int l, int j) {
  int r = l + (1 << j) - 1;
  return query(r) - query (l-1);
}
int main() {
  int n;
  scanf ("%d",&n);
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    scanf ("%d",&arr[i]);
    update(i,arr[i]);
  }
  for (int j = 0; j < 18; j++)
    for (int i = 0; i < n; i++) if (i + (1<<j) - 1 < n) {
      if (j == 0) dp[i][j] = 0;
      else {
        dp[i][j] = dp[i][j-1] + dp[i+(1<<(j-1))][j-1] + (query(i,j-1)%10 + query(i+(1<<(j-1)),j-1)%10 >= 10);
      }
    }
  int q;
  scanf ("%d",&q);
  while (q--) {
    int a,b;
    scanf ("%d %d",&a,&b); --a, --b;
    printf ("%d\n",dp[a][__builtin_ctz(b-a+1)]);
  }
  return 0;
}