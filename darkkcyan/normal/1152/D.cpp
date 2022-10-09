#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

#define maxn 1010
#define rem ((llong)1e9+7)

int n;
llong dp[2][maxn * 2][maxn * 2];

llong cal(bool matched_root, int lv, int open) {
  if (lv == 2 * n) {
    if (open > 0) return INT_MIN;
    return 0;
  }

  if (dp[matched_root][lv][open] != -1) return dp[matched_root][lv][open];
  dp[0][lv][open] = dp[1][lv][open] = 0;

  vector<pair<llong, llong>> child;
  child.push_back({cal(0, lv + 1, open + 1), cal(1, lv + 1, open + 1)});
  if (child.back().xx < 0) child.pop_back();

  if (open > 0) child.push_back({cal(0, lv + 1, open - 1), cal(1, lv + 1, open - 1)});
  if (child.back().xx < 0) child.pop_back();

  if (len(child) == 0) {
    dp[0][lv][open] = dp[1][lv][open] = INT_MIN;
  } else {
    for (auto& i: child) i.yy = max(i.yy, i.xx);
    for (auto i: child) {
      (dp[0][lv][open] += i.yy) %= rem;
    }
    if (len(child) == 1) dp[1][lv][open] = (child[0].xx + 1) % rem;
    else {
      dp[1][lv][open] = (child[0].xx + child[1].yy + 1) % rem;
    }
  }

  return dp[matched_root][lv][open];
}


int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << max(cal(0, 0, 0), cal(1, 0, 0));

    return 0;
}