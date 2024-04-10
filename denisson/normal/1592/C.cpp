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

int n, k;
int a[100007];
vector<int> g[100007];
int w[100007];

int fi = 0;

bool dfs(int v, int x, int p = -1) {

  vector<int> t;

  w[v] = a[v];
  for (int to : g[v]) if (to != p) {
    t.pb(dfs(to, x, v));
    w[v] ^= w[to];
  }


  int su = 0;
  for (int x : t) su += x;
  if (su >= 2 || su == 1 && w[v] == 0) {
    fi = 1;
  }

  t.pb(w[v] == x);
  // sort(all(t));

  int ma = *max_element(all(t));

  return ma;
}

void solve() {
  cin >> n >> k;
  readArr(a, a + n);

  int x = 0;
  for (int i = 0; i < n; ++i) x ^= a[i];

  for (int i = 0; i < n; ++i) g[i].clear();
  for (int i = 0; i + 1 < n; ++i) {
    int w1, w2;
    cin >> w1 >> w2;
    --w1; --w2;
    g[w1].pb(w2);
    g[w2].pb(w1);
  }

  if (x == 0) {
    cout << "YES\n"; return;
  }

  if (k == 2) {
    cout << "NO\n"; return;
  }

  fi = 0;
  dfs(0, x);
  if (fi) {
    cout << "YES\n"; 
  } else cout << "NO\n";


}


int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

}