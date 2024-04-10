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
int n;
llong h;
pair<llong, llong> a[maxn];
llong del[maxn] = {0};

llong getdel(int l, int r) {
  return del[r - 1] - del[l - 1];
}

llong solve(int i) {
  int l = i + 1, r = n + 1;
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (getdel(i, mid) >= h) r = mid;
    else l = mid + 1;
  }
  llong th = h - getdel(i, l - 1);
  llong ans = th + a[l - 1].yy - a[i].xx;
  //cout << i << ' ' << l << ' ' << getdel(i, l) << ' ' << ans << endl;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> h;
  rep1(i, n) cin >> a[i].xx >> a[i].yy;
  sort(a + 1, a + n + 1);
  rep1(i, n - 1) del[i] = a[i + 1].xx - a[i].yy;
  rep1(i, n - 1) del[i] += del[i - 1];
  llong ans = 0;
  rep1(i, n) ans = max(ans, solve(i));
  cout << ans;
  

  return 0;
}