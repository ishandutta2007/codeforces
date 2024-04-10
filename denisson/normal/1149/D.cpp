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


int n, m, a, b;
vector<pair<int, pair<int, int>>> ed;
int color[77];
int siz[77];

int dp[71][1 << 18];

vector<int> g1[77];
vector<int> g2[77];

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> m >> a >> b;

  for (int i = 0; i < m; ++i) {
    int w1, w2, w3;
    cin >> w1 >> w2 >> w3;
    --w1; --w2;
    // if (w3 == a) g1[w1].pb(w2), g1[w2].pb(w1);
    // else g2[w1].pb(w2), g2[w2].pb(w1);
    ed.pb(mp(w3, mp(w1, w2)));
    if (w3 == a) {
      dsu.merge(w1, w2);
    }
  }

  map<int, int> ma;
  for (int i = 0; i < n; ++i) {
    int c = dsu.get(i);

    // per(i, c, dsu.get_func(i));

    if (dsu.get_func(i) > 3) {
      if (ma.find(c) == ma.end()) {
        int sz = ma.size(); ma[c] = sz + 1;
        siz[sz] = dsu.get_func(i);
      }

      color[i] = ma[c];
    }
  }

  for (int i = 0; i < ed.size(); ++i) {
    if (ed[i].x == a) g1[ed[i].y.x].pb(ed[i].y.y), g1[ed[i].y.y].pb(ed[i].y.x);
    else 
    if (dsu.get(ed[i].y.x) != dsu.get(ed[i].y.y))
      g2[ed[i].y.x].pb(ed[i].y.y), g2[ed[i].y.y].pb(ed[i].y.x);
  }

  fill((int*)dp, (int*)dp + (71 << 18), 1e9 + 7);

  set<pair<int, pair<int, int>>> se;

  if (color[0] == 0) dp[0][0] = 0, se.insert(mp(0, mp(0, 0)));
  else dp[0][1 << color[0]] = 0, se.insert(mp(0, mp(0, 1 << color[0])));

  while (se.size()) {
    auto [val, v] = *se.begin();
    se.erase(se.begin());

    // per(val, v);

    for (int to : g1[v.x]) {
      // int nxt_mask = v.y;
      // if (color[to]) nxt_mask |= 1 << color[to];
      if (dp[to][v.y] > val + a) {
        se.erase(mp(dp[to][v.y], mp(to, v.y)));
        dp[to][v.y] = val + a;
        se.insert(mp(dp[to][v.y], mp(to, v.y)));
      }
    }

    for (int to : g2[v.x]) {
      int nxt_mask = v.y;
      if (color[to] && ((nxt_mask >> color[to]) & 1)) continue;
      if (color[to]) nxt_mask |= 1 << color[to];
      if (dp[to][nxt_mask] > val + b) {
        se.erase(mp(dp[to][nxt_mask], mp(to, nxt_mask)));
        dp[to][nxt_mask] = val + b;
        se.insert(mp(dp[to][nxt_mask], mp(to, nxt_mask)));
      }
    }

  }

  for (int i = 0; i < n; ++i) {
    int res = 2e9;
    for (int mask = 0; mask < (1 << 18); ++mask) uin(res, dp[i][mask]);
    cout << res << "\n";
  }

}