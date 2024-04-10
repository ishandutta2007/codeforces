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

int n, m;
int a[1111];
int b[1111];
vector<int> g[1111];

int used[1007];
int was[1007];

vector<int> st;
bool dfs(int v, ll now, int ost, int last = -1, int can = 0) {
  
  // cout << v + 1 << ' ' << now << endl;

  st.pb(v);
  was[v] = 1;

  if (ost == 0) {
    for (int q : st) used[q] = 1;
    return 1;
  }

  for (int to : g[v]) if (to != last) {

    // cout << v + 1 << ' ' << to + 1 << ' ' << a[to] << ' ' << now << endl;

    if (was[to]) {

      if (can) {
        for (int q : st) used[q] = 1;
        return 1;
      }

    } else if (a[to] < now) {
      if (dfs(to, now + b[to] * (!used[to]), ost - (!used[to]), v, max<int>(can, !used[to]))) return 1;
    }
  }

  st.pop_back();
  return 0;
}

bool ok(ll w) {
  fill(used, used + n, 0);
  used[0] = 1;

  while (1) {

    int ost = 0;
    for (int i = 0; i < n; ++i) if (!used[i]) {
      ++ost;
    }
    if (ost == 0) break;

    fill(was, was + n, 0);

    ll cur_w = w;
    for (int i = 1; i < n; ++i) if (used[i]) {
      cur_w += b[i];
    }

    st.clear();
    if (!dfs(0, cur_w, ost)) return 0;
  }

  return 1;
}

void solve() {

  cin >> n >> m;
  for (int i = 0; i < n; ++i) g[i].clear();
  for (int i = 1; i < n; ++i) cin >> a[i];
  for (int i = 1; i < n; ++i) cin >> b[i];

  for (int i = 0; i < m; ++i) {
    int w1, w2;
    cin >> w1 >> w2;
    --w1; --w2;
    g[w1].pb(w2);
    g[w2].pb(w1);
  }

  int vl = -1, vr = 1e9 + 1;
  while (vl + 1 < vr) {
    int vm = (vl + vr) >> 1;
    if (ok(vm)) vr = vm; else vl = vm;
  }

  cout << vr << "\n";
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

}