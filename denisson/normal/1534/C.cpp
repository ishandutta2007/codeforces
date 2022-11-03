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
  static const int SZ = 1000007;
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


int n;
int a[1000007];
int b[1000007];

void solve() {
  cin >> n;
  readArr(a, a + n);
  readArr(b, b + n);

  dsu.reset(n + 1);
  for (int i = 0; i < n; ++i) {
    dsu.merge(a[i] - 1, b[i] - 1);
  }

  set<int> se;
  for (int i = 0; i < n; ++i) se.insert(dsu.get(i));

  cout << bp(2, se.size()) << "\n";

}


int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

}