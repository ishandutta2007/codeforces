#include <bits/stdc++.h>
#define ll long long
#define db long double
#define ull unsigned long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

#define pper(a) cerr << #a << " = " << a << endl;

void per() { cerr << endl; }
template<typename Head, typename... Tail> void per(Head H, Tail... T) { cerr << H << ' '; per(T...); }

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

template<class U, class V> 
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.x << ", " << a.y << ")";
}

template<class U, class V> 
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.x >> a.y;
}

template<typename W, typename T = typename enable_if<!is_same<W, string>::value, typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) { out << "{ "; for (const auto& x : v) out << x << ", "; return out << '}'; }

template<class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}

mt19937 mrand(1337); 
unsigned int myRand32() {
  return mrand() & (unsigned int)(-1);
}
 
unsigned ll myRand64() {
  return ((ull)myRand32() << 32) ^ myRand32();
}

const int mod = 1000000007;

void add(int& a, int b) {
  a += b; if (a >= mod) a -= mod;
}

void dec(int &a, int b) {
  a -= b; if (a < 0) a += mod;
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

int n, m, q;
vector<int> g[200007];
pair<int, int> d[200007];
int ans[200007];

int tt = 0;
int tin[200007];
int tout[200007];
int up[200007][18];
int up2[200007][18];
int s[200007];

void dfs(int v = 0, int p = 0) {
  up[v][0] = p;
  for (int i = 1; i < 18; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
  tin[v] = tt++;

  for (int to : g[v]) dfs(to, v);

  tout[v] = tt - 1;
}

bool isPred(int a, int b) {
  return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int getLCA(int a, int b) {
  if (isPred(a, b)) return a;
  if (isPred(b, a)) return b;
  for (int i = 17; i >= 0; --i) if (!isPred(up[a][i], b)) a = up[a][i];
  return up[a][0];
}

pair<int, int> f(int a, int b) {
  int cnt = 0;

  for (int i = 17; i >= 0; --i) if (!isPred(up2[a][i], b)) cnt += 1 << i, a = up2[a][i];

  return mp(a, cnt);
}

vector<int> p[200007];

void go(int v = 0) { 
  int nxt = v;
  for (auto c : p[v]) if (isPred(c, nxt)) nxt = c;
  for (int to : g[v]) {
    go(to);
    if (isPred(s[to], nxt)) nxt = s[to];
  }
  s[v] = nxt;
}

void go2(int v = 0) {
  up2[v][0] = s[v];
  for (int i = 1; i < 18; ++i) up2[v][i] = up2[up2[v][i - 1]][i - 1];
  for (int to : g[v]) go2(to);
}



const size_t MAX_BIT = 18;
const size_t MAX_SIZE = 1 << MAX_BIT;

/*
 * Fenwick tree on range [0..MAX_SIZE-1]
 *
 *   Range sum    [vl..vr]    - get(vl, vr)
 *   Point update t[v] += val - up(v, val)
 */

struct FenwickTree1 {
  ll t[MAX_SIZE];

  // Sum [0..v]
  ll get(int v) {
    ll res = 0;
    for (; v >= 0; v = (v & (v + 1)) - 1) {
      res += t[v];
    }
    return res;
  }

  // Sum [vl..vr]
  ll get(int vl, int vr) {
    ll res = get(vr);
    if (vl > 0) {
      res -= get(vl - 1);
    }
    return res;
  }

  // Get the leftmost position with a sum >= k
  int getKth(int k) {
    int i = 0;
    for (int bit = MAX_BIT; bit >= 0; bit--) {
      int x = i + (1 << bit) - 1;
      if (x >= MAX_SIZE) {
        continue;
      }
      if (t[x] <= k) {
        i += (1 << bit);
        k -= t[x];
      }
    }
    return i;
  }

  // Update t[v] += val;
  void up(int v, int val) {
    for (; v < MAX_SIZE; v = v | (v + 1)) {
      t[v] += val;
    }
  }
} fe;

vector<pair<int, int>> z[200007];
vector<int> h[200007];

void ru(int v = 0) {
  vector<int> d;
  for (auto c : z[v]) d.pb(fe.get(tin[c.x], tout[c.x]));
  for (int to : g[v]) ru(to);
  

  for (int to : h[v]) fe.up(tin[to], 1);

  for (int i = 0; i < d.size(); ++i) {
    if (d[i] != fe.get(tin[z[v][i].x], tout[z[v][i].x])) ans[z[v][i].y]--;
  }
  for (auto c : z[v]) d.pb(fe.get(tin[c.x], tout[c.x]));
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  for (int i = 2; i <= n; ++i) {
    int x; cin >> x;
    g[x - 1].pb(i - 1);
  }

  cin >> m;
  readArr(d, d + m); for (int i = 0; i < m; ++i) d[i].x--, d[i].y--;


  dfs();

  for (int i = 0; i < m; ++i) {
    int lca = getLCA(d[i].x, d[i].y);
    if (lca == d[i].x) {
      p[d[i].y].pb(d[i].x);
    } else if (lca == d[i].y) {
      p[d[i].x].pb(d[i].y);
    } else {
      p[d[i].x].pb(lca);
      p[d[i].y].pb(lca);
    }
  }

  go();
  go2();

  cin >> q;
  for (int i = 0; i < q; ++i) {
    int w1, w2;
    cin >> w1 >> w2;
    --w1; --w2;
    int lca = getLCA(w1, w2);

    // per(w1, w2, lca);

    if (!isPred(up2[w1][17], lca)) {
      ans[i] = -1; continue;
    }

    if (!isPred(up2[w2][17], lca)) {
      ans[i] = -1; continue;
    }

    if (lca == w1) {

      ans[i] = f(w2, w1).y + 1;

    } else if (lca == w2) {

      ans[i] = f(w1, w2).y + 1;

    } else {

      auto [q1, l1] = f(w1, lca);
      auto [q2, l2] = f(w2, lca);

      ans[i] = l1 + l2 + 2; 

      if (tin[q1] > tin[q2]) swap(q1, q2);

      z[q1].pb(mp(q2, i));

    }

  }

  for (int i = 0; i < m; ++i) {
    if (tin[d[i].x] > tin[d[i].y]) swap(d[i].x, d[i].y);
    if (!isPred(d[i].x, d[i].y)) h[d[i].x].pb(d[i].y);
  }

  ru();

  for (int i = 0; i < q; ++i) cout << ans[i] << '\n';
}