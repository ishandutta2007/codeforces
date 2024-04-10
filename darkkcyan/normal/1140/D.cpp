#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

#define maxn 555
int n;
llong dp[maxn][maxn];
llong cal(int u, int v) {
  if (u == v or v == u % n + 1) return 0;
  if (dp[u][v] != -1) return dp[u][v];
  dp[u][v] = LLONG_MAX;
  for (int i = u % n + 1; i != v; i = i % n + 1) 
    dp[u][v] = min(dp[u][v], cal(u, i) + cal(i, v) + 1LL * u * i * v);
  return dp[u][v];
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << cal(2, 1);

    return 0;
}