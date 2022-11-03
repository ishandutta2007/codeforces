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


const int CC = 200002;

int n, m;
vector<int> g[200007];
bitset<200002> emp;

bitset<1000> SS[1000];


vector<pair<int, pair<int, int>>> ed, ss;

void dfs(int v) {
  sort(all(g[v]));

  int nxt = n;
  if (g[v].size() > 0) nxt = g[v][0];

  int f = emp._Find_first();
  while (f < nxt) {
    emp[f] = 0;
    ed.pb(mp(0, mp(v, f)));
    dfs(f);
    f = emp._Find_next(f);
  }

  if (g[v].size() > 0) {
    int f = emp._Find_next(g[v].back());
    while (f < n) {
      emp[f] = 0;
      ed.pb(mp(0, mp(v, f)));
    dfs(f);

      f = emp._Find_next(f);
    }    
  }

  for (int i = 0; i + 1 < g[v].size(); ++i) {

    int f = emp._Find_next(g[v][i]);
    while (f < g[v][i + 1]) {
      emp[f] = 0;
      ed.pb(mp(0, mp(v, f)));
    dfs(f);
      
      f = emp._Find_next(f);
    }  

  }
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int xo = 0;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int w1, w2, w3;
    cin >> w1 >> w2 >> w3;
    --w1; --w2;
    ed.pb(mp(w3, mp(w1, w2)));
    g[w1].pb(w2);
    g[w2].pb(w1);
    if (n < 1000) {
      SS[w1][w2] = SS[w2][w1] = 1;
    }
    xo ^= w3;
  }

  if (n * (ll)(n - 1) / 2 - m >= n) {
    for (int i = 0; i < n; ++i) emp[i] = 1;
    for (int i = 0; i < n; ++i) if (emp[i]) dfs(i);

    sort(all(ed));
    ll res = 0;


    for (auto c : ed) {
      int w1 = c.y.x;
      int w2 = c.y.y;
      if (dsu.get(w1) != dsu.get(w2)) {
        dsu.merge(w1, w2);
        res += c.x;
      }
    }

    cout << res;
  } else {
    sort(all(ed));

    for (auto c : ed) {
      int w1 = c.y.x;
      int w2 = c.y.y;
      if (dsu.get(w1) != dsu.get(w2)) {
        dsu.merge(w1, w2);
        ss.pb(c);
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) if (!SS[i][j]) ss.pb(mp(0, mp(i, j)));
    }

    sort(all(ss));
    dsu.reset(n + 1);
    int can = 0;
    ll res = 0;
    ll mi = 1e18;

    for (auto c : ss) {
      int w1 = c.y.x;
      int w2 = c.y.y;
    //  cout << w1 << ' ' << w2 << ' ' << c.x << endl;
      if (dsu.get(w1) != dsu.get(w2)) {
        dsu.merge(w1, w2);
        res += c.x;
      } else {
        if (c.x == 0) can = 1;
        else {
          mi = min(mi, (ll)c.x);
        }
      }
    }

    cout << res + (1 - can) * min((ll)xo, mi);
  }
}