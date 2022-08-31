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

vector<ll> a, b;
vector<vector<int> > gr;
int n, m;
vector<int> monsters;

vector<int> last_v;
vector<int> kill_monsters;
vector<bool> used;

void dfs(int vertex, int last, int k, ll h) {
  used[vertex] = true;
  kill_monsters[vertex] = k;
  last_v[vertex] = last;

  for (auto to : gr[vertex]) {
    if (used[to]) continue;
    if (monsters[to]) {
      if (h <= a[to]) continue;
      dfs(to, vertex, 1, h + b[to]);
    }
    else {
      dfs(to, vertex, k, h);
    }
  }

}


bool get(ll x) {

  monsters.assign(n, 1);
  monsters[0] = 0;

  ll hp = x;


  while (true) {

    bool gg = true;
    for (auto x : monsters) if (x == 1) gg = false;
    if (gg) return true;

    last_v.assign(n, -1);
    kill_monsters.assign(n, 0);
    used.assign(n, false);

    dfs(0, -1, 0, hp);
    int u = -1, v = -1;

    for (int i = 0; i < n; ++i) for (auto to : gr[i]) {
      if (used[i] && used[to] && (kill_monsters[i] || kill_monsters[to]) && (last_v[i] != to && last_v[to] != i)) {
        u = i, v = to;
      }
    }

   // per(monsters, u, v);


    if (u == -1) return false;
    while (u != -1) {
      if (monsters[u]) {
        monsters[u] = 0;
        hp += b[u];
      }
      u = last_v[u];
    }

    while (v != -1) {
      if (monsters[v]) {
        monsters[v] = 0;
        hp += b[v];
      }
      v = last_v[v];
    }


  }

}

void solve() {

  cin >> n >> m;

  a.assign(n, -1);
  b.assign(n, -1);
  gr.assign(n, {});

  for (int i = 1; i < n; ++i) cin >> a[i];
  for (int i = 1; i < n; ++i) cin >> b[i];


  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    gr[a].pb(b), gr[b].pb(a);
  }

  ll L = -1, R = 1e18;
  while (R-L>1) {
    ll M = (L+R)/2;
    if (get(M)) R = M;
    else L = M;
  }

  cout << R << '\n';


}

int main(){
#ifdef LOCAL
  freopen("E_input.txt", "r", stdin);
  //freopen("E_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}