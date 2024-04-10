#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
#define int long long

const int N = (int) 1e5 + 7;
int a[N], pre[N];
set<int> s;

void dv(int l, int r) {
  if (l > r) {
    return;
  }
  s.insert(pre[r] - pre[l - 1]);
  int x = (a[l] + a[r]) / 2;
  int lo = l, hi = r, split = l;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] <= x) {
      split = mid;
      lo = mid + 1;
    } else hi = mid - 1;
  }
  if (split == r) return;
  dv(l, split);
  dv(split + 1, r);
}


signed main() {
  ios::sync_with_stdio(0);cin.tie(0);

///  freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    s.clear();
    dv(1, n);
    while (q--) {
      int num;
      cin >> num;
      if (s.count(num)) cout << "Yes\n"; else cout << "No\n";
    }
  }
}