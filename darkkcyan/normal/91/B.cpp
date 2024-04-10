#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 101010

struct bit {
  int d[maxn];
  void upd(int i, int val) {
    for (++i; i < maxn; i += i & -i) d[i] = max(d[i], val);
  }
  int get(int i) {
    int ans = -1;
    for (++i; i > 0; i -= i & -i) ans = max(d[i], ans);
    return ans;
  }
} bit;

int n;
int a[maxn];
int ans[maxn];
vector<int> p;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep(i, n) {
    cin >> a[i];
    p.push_back(a[i]);
  }
  sort(p.begin(), p.end()); p.resize(unique(p.begin(), p.end()) - p.begin());
  rep(i, n) {
    a[i] = lower_bound(p.begin(), p.end(), a[i]) - p.begin();
  }
  for (int i = n; i--; ) {
    int t = bit.get(a[i] - 1);
    if (t < i) ans[i] = -1;
    else ans [i] = t - i - 1;
    bit.upd(a[i], i);
  }
  rep(i, n) cout << ans[i] << ' ';
  
  return 0;
}