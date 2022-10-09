#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; ++i <= n; )

#define maxn 111
int n, a, b;
ii d[maxn];

bool canfit(int u, int v) {
  return u <= a and v <= b;
}

bool canfit(const ii& u, const ii& v) {
  bool ans = 0;
  rep(i, 4) {
    ii x = u, y = v;
    if (i & 1) swap(x.xx, x.yy);
    if ((i >> 1) & 1) swap(y.xx, y.yy);
    ans |= canfit(x.xx + y.xx, max(x.yy, y.yy));
    ans |= canfit(max(x.xx, y.xx), x.yy + y.yy);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> a >> b;
  rep(i, n) cin >> d[i].xx >> d[i].yy;

  int ans = 0;
  rep(i, n) for (int f = i; ++f < n;)
    if (canfit(d[i], d[f])) ans = max(ans, d[i].xx * d[i].yy + d[f].xx * d[f].yy);
  cout << ans;

  return 0;
}