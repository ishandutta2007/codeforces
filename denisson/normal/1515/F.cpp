#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;


struct Node {
  int p, r, f;
};

struct DSU {
  static const int SZ = 300007;
  Node t[SZ];

  DSU() { reset(SZ); }

  void reset(int n) {
    for (int i = 0; i < n; ++i) {
      t[i].p = i;
      t[i].r = 0;
      t[i].f = 1;
    }
  }

  int get(int v) {
    if (t[v].p == v) return v;
    return t[v].p = get(t[v].p);
  }

  int get_func(int v) {
    return t[get(v)].f;
  }

  void merge(int a, int b) {
    a = get(a), b = get(b);
    if (a != b) {
      if (t[a].r < t[b].r) swap(a, b);
      t[b].p = a;
      t[a].f += t[b].f;
      if (t[a].r == t[b].r) ++t[a].r;
    }
  }
} dsu;


int n;
ll x;
ll a[300007];
vector<pair<int, int> > g[300007];
vector<int> ans;

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int m;
  cin >> n >> m >> x;
  ll s = 0;
  for (int i = 0; i < n; ++i) cin >> a[i], s += a[i];

  if (s < x * (ll)(n - 1)) {
    cout << "NO\n"; 
    exit(0);
  } else {
    cout << "YES\n";
  }

  for (int i = 0; i < m; ++i) {
    int w1, w2; cin >> w1 >> w2; --w1; --w2;
    if (dsu.get(w1) != dsu.get(w2)) {
      dsu.merge(w1, w2);
      g[w1].pb(mp(w2, i)); g[w2].pb(mp(w1, i));
    }
  }

  dsu.reset(n + 1);

  set<pair<ll, int>> se;
  for (int i = 0; i < n; ++i) se.insert(mp(a[i], i));

  for (int it = 0; it + 1 < n; ++it) {

    auto now = *prev(se.end());
    se.erase(prev(se.end()));

    int v = dsu.get(now.y);

    while (1) {
      auto nxt = g[v].back();
      if (v == dsu.get(nxt.x)) {
        g[v].pop_back();
      } else break;
    }

    auto nxt = g[v].back();
    ans.pb(nxt.y);
    int w1 = v, w2 = dsu.get(nxt.x);

    se.erase(mp(a[w2], w2));

  //  cout << w1 + 1 << ' ' << w2 + 1 << endl;

    dsu.merge(w1, w2);
    a[dsu.get(w1)] = a[w1] + a[w2] - x;

    if (g[w1].size() < g[w2].size()) swap(w1, w2);

    for (auto c : g[w2]) g[w1].pb(c);
    if (dsu.get(w1) != w1) swap(g[w1], g[w2]);

    se.insert(mp(a[dsu.get(w1)], dsu.get(w1)));
  }

  for (int x : ans) cout << x + 1 << '\n';
}