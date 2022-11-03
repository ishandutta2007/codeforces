#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Tr {
  ll s[4 * 200007];
  ll le[4 * 200007];
  ll ri[4 * 200007];
  ll t[4 * 200007];

  void go(int v) {
    s[v] = s[v * 2 + 1] + s[v * 2 + 2];
    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
    t[v] = max(t[v], ri[v * 2 + 1] + le[v * 2 + 2]);
    le[v] = max(le[v * 2 + 1], s[v * 2 + 1] + le[v * 2 + 2]);
    ri[v] = max(ri[v * 2 + 2], s[v * 2 + 2] + ri[v * 2 + 1]);
  }

  void build(int v, int vl, int vr) {
    s[v] = le[v] = ri[v] = t[v] = 0;
    if (vl == vr) {
    } else {
      int vm = (vl + vr) >> 1;
      build(v * 2 + 1, vl, vm);
      build(v * 2 + 2, vm + 1, vr);
    }
  }

  void up(int v, int vl, int vr, int pos, ll val) {
    if (vl == vr) {
      s[v] = val;
      le[v] = ri[v] = t[v] = max((ll)0, val);
    } else {
      int vm = (vl + vr) >> 1;
      if (pos <= vm) up(v * 2 + 1, vl, vm, pos, val);
      else up(v * 2 + 2, vm + 1, vr, pos, val);
      go(v);
    }
  }

  ll get() {
    return t[0];
  }
} tr;

int n;
int a[200007];
ll ans[200007];

int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  vector<pair<int, int>> p; 
  for (int i = 0; i < n; ++i) cin >> a[i], p.pb(mp(a[i], i)), ans[i] = 0;

  sort(all(p));

  tr.build(0, 0, n - 1);
  for (int i = 0; i < n; ++i) tr.up(0, 0, n - 1, i, 1);

  int i = 0;
  while (i < p.size()) {
    int j = i;

    while (j + 1 < p.size() && p[j + 1].x == p[i].x) ++j;

    for (int s = i; s <= j; ++s) {
      tr.up(0, 0, n - 1, p[s].y, 1000000000);
      ll now = tr.get() - 1000000000;
      if (abs(now) % 2 == 0) {
        ans[p[s].y] = max(ans[p[s].y], now / 2);
      } else {
        ans[p[s].y] = max(ans[p[s].y], (now + 1) / 2);
      }
      tr.up(0, 0, n - 1, p[s].y, 1);
    }

    for (int s = i; s <= j; ++s) {
      tr.up(0, 0, n - 1, p[s].y, -1); 
    }

    i = j + 1;
  }

 // for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
 // cout << endl;
 // exit(0);

  /// 2

  reverse(all(p));
  tr.build(0, 0, n - 1);
  for (int i = 0; i < n; ++i) tr.up(0, 0, n - 1, i, 1);

  i = 0;
  while (i < p.size()) {
    int j = i;

    while (j + 1 < p.size() && p[j + 1].x == p[i].x) ++j;

    for (int s = i; s <= j; ++s) {
      tr.up(0, 0, n - 1, p[s].y, 1000000000);
      ll now = tr.get() - 1000000000;
      if (abs(now) % 2 == 0) {
        ans[p[s].y] = max(ans[p[s].y], now / 2);
      } else {
        ans[p[s].y] = max(ans[p[s].y], (now + 1) / 2 - 1);
      }
      tr.up(0, 0, n - 1, p[s].y, 1);
    }

    for (int s = i; s <= j; ++s) {
      tr.up(0, 0, n - 1, p[s].y, -1); 
    }

    i = j + 1;
  }


  for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
}