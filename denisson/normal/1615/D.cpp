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

int n;

vector<pair<int, int> > g[200007];
vector<pair<int, int> > d[200007];

void dfs(int v = 0, int p = -1) {
  for (auto [to, w] : g[v]) if (to != p) {
    if (w != -1) {
      if (__builtin_popcount(w) % 2 == 0) d[v].pb(mp(to, 0)), d[to].pb(mp(v, 0)); else  d[v].pb(mp(to, 1)), d[to].pb(mp(v, 1));
    } 
    dfs(to, v);
  }
}

int was[200007];
int ok;

void go(int v, int cc) {
  was[v] = cc;
//  per(v, cc);
//  f[cc].pb(v);

  for (auto [to, w] : d[v]) {
    if (was[to] == -1) {
      go(to, cc ^ w);
    } else {
      if (was[to] != (cc ^ w)) {
        ok = 0;
      }
    }
  }
}

void solve() {
  int m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) g[i].clear(), d[i].clear(), was[i] = -1;
  for (int i = 1; i < n; ++i) {
    int w1 ,w2, w3;
    cin >> w1 >> w2 >> w3;
    --w1; --w2;
    g[w1].pb(mp(w2, w3));
    g[w2].pb(mp(w1, w3));
  }

  dfs();

  while (m--) {
    int w1, w2, w3;
    cin >> w1 >> w2 >> w3;
    --w1; --w2;
    d[w1].pb(mp(w2, w3));
    d[w2].pb(mp(w1, w3));
  }

  ok = 1;
//  f[0].clear();
 // f[1].clear();
  for (int v = 0; v < n; ++v) if (was[v] == -1 && ok) {
    go(v, 0);
  }

  if (!ok) {
    cout << "NO\n"; return;
  }
  cout << "YES\n";

  for (int v = 0; v < n; ++v) for (auto [to, w] : g[v]) if (v > to) {
    if (w == -1) {
      cout << v + 1 << ' ' << to + 1 << ' ' << (was[v] ^ was[to]) << "\n";
    } else {
      cout << v + 1 << ' ' << to + 1 << ' ' << w << "\n";
    }
  }

}


int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

}