#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++i < n; )
#define sz(v) ((int)v.size())

#define iil pair<ii, llong>

#define maxn 201010
int n, x;
vector<iil> a[maxn];

bool cmp1(const iil& a, const iil& b) {
  return a.xx.yy < b.xx.yy;
}

bool cmp2(const iil& a, const iil& b) {
  return a.xx.xx < b.xx.xx;
}


int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> x;
  rep(i, n) {
    int l, r, c; cin >> l >> r >> c;
    a[r - l + 1].push_back({{l, r}, c});
  }

  llong ans = 1e15;
  rep(i, maxn) {
    if (i == 0 or sz(a[i]) == 0) continue;
    int f = x - i;
    if (f <= 0 or sz(a[f]) == 0) continue;
    sort(a[i].begin(), a[i].end(), cmp2);
    sort(a[f].begin(), a[f].end(), cmp1);
    llong curt = 1e15;
    int v = 0;
    for (auto u: a[i]) {
      while (v < sz(a[f]) and a[f][v].xx.yy < u.xx.xx) {
        curt = min(curt, a[f][v].yy);
        ++v;
      }
      ans = min(ans, u.yy + curt);
    }
  }
  if (ans == 1e15) cout << -1 << endl;
  else cout << ans;
  return 0;
}