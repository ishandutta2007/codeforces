#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

int n, m;
vector<pair<int, int>> g[200006];
vector<pair<int, int>> gr[200006];

int was[300007];

vector<int> ord;
void dfs(int v) {
  was[v] = 1;
  for (auto [to, _] : g[v]) if (!was[to]) dfs(to);
  ord.pb(v);
}

int color[300007];
vector<ll> f[200007];
ll func[200007];

ll p[200007];

void go(int v, int cc, ll le = 0) {
  p[v] = le;
  color[v] = cc;
  was[v] = 1;

  for (auto [to, w] : gr[v]) if (!was[to]) {
    go(to, cc, le + w); 
  } else if (color[to] == cc) {
 //   cout << v + 1 << ' ' << to + 1 << ' ' << cc << ' ' << le << ' ' << p[v] + w - p[to] << endl;
    f[cc].pb(p[v] + w - p[to]);
  }
}

int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int w1, w2, w3;
    cin >> w1 >> w2 >> w3; --w1; --w2;
    g[w1].pb(mp(w2, w3));
    gr[w2].pb(mp(w1, w3));
  }

  for (int i = 0; i < n; ++i) if (!was[i]) dfs(i);

  for (int i = 0; i < n; ++i) was[i] = 0;

  int cc = 0;

  reverse(all(ord));
  for (int v : ord) if (!was[v]) {
    go(v, cc);

    ll g = 0;
    for (auto w : f[cc]) g = __gcd(g, w);
   //   cout << "FGGDSGDSG"<< ' ' << cc << ' ' << g << endl;
    func[cc] = g;
  ++cc;
  }

  int q; cin >> q;
  while (q--) {
    ll v, s, t;
    cin >> v >> s >> t; --v;
 //   cout << v << ' ' << color[v] << ' ' << func[color[v]] << ' ' << endl;
    if (s % __gcd(t, func[color[v]]) == 0) cout << "YES\n"; else cout << "NO\n";
  }
}