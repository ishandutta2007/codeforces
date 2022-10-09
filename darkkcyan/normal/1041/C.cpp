#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

#define maxn 201010
int n, m;
llong d;
pair<llong, int> a[maxn];
int ans[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m >> d;
  rep1(i, n) cin >> a[i].xx, a[i].yy = i;
  sort(a + 1, a + n + 1);
  int minday = 0;
  set<ii> se;
  rep1(i, n) {
    llong t = len(se) ? se.begin()->xx : INT_MAX;
    if (t + d >= a[i].xx) {
      ++minday;
      ans[a[i].yy] = minday;
    } else {
      ans[a[i].yy] = se.begin()->yy;
      se.erase(se.begin());
    }
    se.insert({a[i].xx, ans[a[i].yy]});
  }
  cout << minday << '\n';
  rep1(i, n) cout << ans[i] << ' ';
  

  return 0;
}