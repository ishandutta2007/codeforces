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

const int mod = 998244353;

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

int kek[200007];
vector<int> t;

int n;
vector<pair<int, pair<int, int>>> g[200007];

vector<int> get_fac(int x) {
  vector<int> res;
  while (x > 1) {
    res.pb(kek[x] - 1);
    x /= t[kek[x] - 1];
  }
  return res;
}

int sum = 0;
int SS[200007];
map<int, int> ge;

void dfs(int v, int p = -1, int curw = 1) {
  add(sum, curw);

  for (auto [to, w] : g[v]) if (to != p) {

    auto res1 = get_fac(w.x);
    auto res2 = get_fac(w.y);

    for (int x : res1) --SS[x]; 
    for (int x : res2) ++SS[x];
    for (int x : res1) uin(ge[t[x]], SS[x]);

    dfs(to, v, mult(curw, mult(w.y, bp(w.x, mod - 2))));


    for (int x : res1) ++SS[x];
    for (int x : res2) --SS[x];

  }

}

void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) g[i].clear();
  for (int i = 1; i < n; ++i) {
    int w1, w2, x, y;
    cin >> w1 >> w2 >> x >> y;
    --w1; --w2;
    g[w1].pb(mp(w2, mp(x, y)));
    g[w2].pb(mp(w1, mp(y, x)));
  }

  ge.clear();
  sum = 0;
  dfs(0);

  for (auto [w1, w2] : ge) {
    if (w2 < 0) sum = mult(sum, bp(w1, -w2));
  }


  cout << sum << "\n";
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  for (int x = 2; x < 200007; ++x) {
    if (kek[x] == 0) {
      t.pb(x);

      for (int y = x; y < 200007; y += x) {
        kek[y] = t.size();
      }

    }
  }

  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

}