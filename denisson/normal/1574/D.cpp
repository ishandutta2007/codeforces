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
vector<ll> a[11];
ll kek[11];

struct Node {
  map<int, int> was;
  ll dp;
  Node() { dp = -1e18; }
} t[2000007];

int dd = 1;

ll res = -1e18;

vector<int> st, RES;

void dfs(int v, int i = 0) {
  if (i >= n) return;

  for (int j = (int)a[i].size() - 1; j >= 0; --j) {
    st.pb(j);
    if (t[v].was.find(j) == t[v].was.end()) {

      if (t[v].dp + a[i][j] + kek[i + 1] > res) {
        res = t[v].dp + a[i][j] + kek[i + 1];
        RES = st;        
      }

      st.pop_back();
      break;

    } else {
      int to = t[v].was[j];

      t[to].dp = t[v].dp + a[i][j];
      dfs(to, i + 1);

    }
    st.pop_back();
  }

}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int sz; cin >> sz;
    a[i].resize(sz);
    readArr(all(a[i]));
  }

  t[0].dp = 0;

  int m;
  cin >> m;

  kek[n] = 0;
  for (int i = n - 1; i >= 0; --i) kek[i] = kek[i + 1] + a[i].back();

  for (int i =0 ; i < m; ++i) {
    int v = 0;
    for (int i = 0; i < n; ++i) {
      int to; cin >> to; --to;

      if (t[v].was.find(to) == t[v].was.end()) {
        t[v].was[to] = dd++;
      }

      v = t[v].was[to];

    }
  }

  dfs(0);

  int le = RES.size();
  for (int i = le; i < n; ++i) RES.pb((int)a[i].size() - 1);

  for (int x : RES) cout << x + 1 << ' ';
}