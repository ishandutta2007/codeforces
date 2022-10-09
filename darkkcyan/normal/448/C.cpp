#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 5050
int n;
int a[maxn];

int process(int l, int r, int lastmin = 0) {
  if (l == r) {
    return a[l] != lastmin;
  }
  if (l > r) return 0;
  int ans = max(r - l + 1, 0);
  int mi = l;
  for (int i = l; ++i <= r; )
    if (a[mi] > a[i]) mi = i;
  ans = min(ans, a[mi] - lastmin + process(l, mi - 1, a[mi]) + process(mi + 1, r, a[mi]));
  // clog << l << ' ' << r << ' ' << ans << endl;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep(i, n) cin >> a[i];
  cout << process(0, n - 1);
  
  return 0;
}