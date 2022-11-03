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
  static const int SZ = 200007;
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

const db pi = acos(-1.0);

struct pt {
  ll x, y;

  pt operator-(const pt& nxt) const {
    return pt{x - nxt.x, y - nxt.y};
  }

  pt operator+(const pt& nxt) const {
    return pt{x + nxt.x, y + nxt.y};
  }

  ll operator%(const pt& nxt) const {
    return x * nxt.y - y * nxt.x;
  }

  db ang() const {
    db w = atan2(y, x);
    if (w < 0) w += 2 * pi;
    return w;
  }
};

struct st {
  pt p;
  int v;
};

int n;
st a[2222];
int color[2222];

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  vector<pair<int, int> > res;

  int le = -1;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].p.x >> a[i].p.y >> a[i].v; a[i].v--;
    if (i != a[i].v) le = i; 
  }

  if (le == -1) {
    cout << 0; exit(0);
  }

  vector<int> t;
  for (int i = 0; i < n; ++i) if (i != le) t.pb(i);

  sort(all(t), [le](int w1, int w2) {
    return (a[w1].p - a[le].p).ang() < (a[w2].p - a[le].p).ang();
  });

 // for (int q : t) cout << q + 1 << ' ' << (a[q].p - a[le].p).ang() << endl; exit(0);

  int cc = 1;
  for (int i = 0; i < n; ++i) if (color[i] == 0) {
    int v = i;
    while (color[v] == 0) {
      color[v] = cc;
      v = a[v].v;
    }
    ++cc;
  }


  for (int i = 0; i < t.size(); ++i) {

  //  cout << i << ' ' << t[i] + 1 << endl;

    int j = (i + 1) % t.size();
    if ((a[t[i]].p - a[le].p) % (a[t[j]].p - a[le].p) < 0) continue;
    if (dsu.get(color[t[i]]) != dsu.get(color[t[j]])) {
      dsu.merge(color[t[i]], color[t[j]]);
      res.pb(mp(t[i], t[j]));
      swap(a[t[i]].v, a[t[j]].v);
    }
  }


  while (1) {
    if (a[le].v == le) break;
    res.pb(mp(le, a[le].v));
    swap(a[le].v, a[a[le].v].v);
  }

  cout << res.size() << endl;
  for (auto [w1, w2] : res) cout << w1 + 1 << ' ' << w2 + 1 << "\n";
}