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

const ll LINF = 1e15 + 7; 


struct Tree {
  ll t[300007 * 4];
  ll p[300007 * 4];

  void push(int v) {
    if (p[v]) {
      t[v] += p[v];
      if (v * 2 + 1 < 300007 * 4) p[v * 2 + 1] += p[v];
      if (v * 2 + 2 < 300007 * 4) p[v * 2 + 2] += p[v];
      p[v] = 0;
    }
  }

  void up(int v, int vl, int vr, int l, int r, ll val) {
    push(v);
    if (r < vl || l > vr) return;
    if (vl >= l && vr <= r) {
      p[v] += val;
      push(v);
    } else {
      int vm = (vl + vr) >> 1;

      up(v * 2 + 1, vl, vm, l, r, val);
      up(v * 2 + 2, vm + 1, vr, l, r, val);

      t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);

    }
  }

  ll get(int v, int vl, int vr, int l, int r) {
    push(v);
    if (r < vl || l > vr || l > r) return LINF;

    if (vl >= l && vr <= r) return t[v];

    int vm = (vl + vr) >> 1;
    return min(get(v * 2 + 1, vl, vm, l, r), get(v * 2 + 2, vm + 1, vr, l, r));

  }
} tr;


int n, m;
vector<int> g[300007];


vector<pair<int, int> > z[300007];
vector<pair<int, int> > de[300007];

int pos[300007];

ll dp[300007];

int tt = 0;

int tin[300007];
int tout[300007];

void dfs(int v = 0, int p = -1) {

  int start = tt;
  tin[v] = tt;

  for (auto c : z[v]) {
    pos[c.y] = tt++;
  }


  ll sum = 0;
  for (int to : g[v]) if (to != p) {
    dfs(to, v);
    sum += dp[to];
  }

  for (int to : g[v]) if (to != p) {
    if (tin[to] <= tout[to]) {
      tr.up(0, 0, 300001, tin[to], tout[to], sum - dp[to]);
    }
  }


  for (auto c : z[v]) {
    tr.up(0, 0, 300001, pos[c.y], pos[c.y], c.x + sum);
  }

  for (auto c : de[v]) {
    tr.up(0, 0, 300001, pos[c.y], pos[c.y], LINF);
  }


  dp[v] = tr.get(0, 0, 300001, start, tt - 1);


  tout[v] = tt - 1;

 // per(v + 1, dp[v], tin[v], tout[v] );
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i + 1 < n; ++i) {
    int w1, w2;
    cin >> w1 >> w2;
    --w1; --w2;
    g[w1].pb(w2);
    g[w2].pb(w1);
  }

  for (int i = 0; i < m; ++i) {
    int w1, w2, w3;
    cin >> w1 >> w2 >> w3;
    --w1; --w2;
    if (w1 == w2) continue;
    z[w1].pb(mp(w3, i));
    de[w2].pb(mp(w3, i));
  }

  dfs(0);

  ll res = 0;
  for (int to : g[0]) if (dp[to] >= LINF) cout << -1, exit(0); else res += dp[to];

  cout << res;
}