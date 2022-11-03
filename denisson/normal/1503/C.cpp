#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Tree {
  ll t[100007 * 4];

  void build(int v, int vl, int vr) {
    t[v] = 1e18;
    if (vl != vr) {
      int vm = (vl + vr) >> 1;
      build(v * 2 + 1, vl, vm);
      build(v * 2 + 2, vm + 1, vr);
    }
  }

  void up(int v, int vl, int vr, int l, int r, ll val) {
    if (l > r) return;
    if (r < vl || l > vr) return;
    if (vl >= l && vr <= r) t[v] = min(t[v], val);
    else {
      int vm = (vl + vr) >> 1;
      up(v * 2 + 1, vl, vm, l, r, val);
      up(v * 2 + 2, vm + 1, vr, l, r, val);
    }
  }

  ll get(int v, int vl, int vr, int pos) {
    if (vl == vr) {
      return t[v];
    } else {
      int vm = (vl + vr) >> 1;
      if (pos <= vm) return min(t[v], get(v * 2 + 1, vl, vm, pos));
      return min(t[v], get(v * 2 + 2, vm + 1, vr, pos));
    }
  }
} t1, t2;

int n;
pair<pair<ll, ll>, int> a[100007];

ll dp[100007];

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x.x >> a[i].x.y, ans += a[i].x.y; a[i].y = i;
  }
  t1.build(0, 0, n);
  t2.build(0, 0, n);
  sort(a, a + n);  

  int v;
  ll to = a[0].x.x;
  for (int i = 0; i < n; ++i) {
   // cout << i << ' ' << to << endl;
    if (to < a[i].x.x) ans += a[i].x.x - to;
    to = max(to, a[i].x.x + a[i].x.y);

  //  if (a[i].y == 0) v = i;
  //  cout << i << ' ' << a[i].x.x << ' ' << a[i].x.y << ' ' << a[i].y << endl;
  }



/*
  for (int i = 0; i <= v; ++i) {
    int vl = i, vr = n;
    while (vl + 1 < vr) {
      int vm = (vl + vr) >> 1;
      if (a[vm].x.x - a[i].x.x <= a[i].x.y) vl = vm; else vr = vm;
    }
    t1.up(0, 0, n, i, vl, 0);
    t2.up(0, 0, n, vr, n - 1, -a[i].x.x -a[i].x.y);
  }

  for (int i = v + 1; i < n; ++i) {
    dp[i] = min(t1.get(0, 0, n, i), t2.get(0, 0, n, i) + a[i].x.x);

    cout << i << ' ' << dp[i] << endl;

    int vl = i, vr = n;
    while (vl + 1 < vr) {
      int vm = (vl + vr) >> 1;
      if (a[vm].x.x - a[i].x.x <= a[i].x.y) vl = vm; else vr = vm;
    }

    t1.up(0, 0, n, i, vl, dp[i]);
    t2.up(0, 0, n, vr, n - 1, dp[i] - a[i].x.x -a[i].x.y);
  }
*/

  cout << ans + dp[n - 1];
}