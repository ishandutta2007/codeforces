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
int a[100007];

vector<int> g[100007];

bitset<1001> act;

bitset<1001> emp, prime_mask;

vector<int> ord;

struct Tree {
  bitset<1001> t[4 * 100007];
  int ad[4 * 100007];

  void build(int v, int vl, int vr) {
    if (vl == vr) {
      t[v][a[ord[vl]] % m] = 1;
    } else {
      int vm = (vl + vr) >> 1;
      build(v * 2 + 1, vl, vm);
      build(v * 2 + 2, vm + 1, vr);
      t[v] = t[v * 2 + 1] | t[v * 2 + 2];
    }
  }

  inline void push(int v) {
    if (ad[v]) {
      ad[v] %= m;

      t[v] = ((t[v] << ad[v]) & act) | (t[v] >> (m - ad[v]));


      if (v * 2 + 1 < 4 * 100007) ad[v * 2 + 1] += ad[v];
      if (v * 2 + 2 < 4 * 100007) ad[v * 2 + 2] += ad[v]; 

      ad[v] = 0;
    }
  }

  bitset<1001> get(int v, int vl, int vr, int l, int r) {
    push(v);
    if (r < vl || l > vr) return emp;
    if (vl >= l && vr <= r) return t[v];
    int vm = (vl + vr) >> 1;
    return get(v * 2 + 1, vl, vm, l, r) | get(v * 2 + 2, vm + 1, vr, l, r);
  }

  void add(int v, int vl, int vr, int l, int r, int val) {
    push(v);
    if (r < vl || l > vr) return;
    if (vl >= l && vr <= r) {
      ad[v] += val;
      push(v);
    } else {
      int vm = (vl + vr) >> 1;
      add(v * 2 + 1, vl, vm, l, r,val);
      add(v * 2 + 2, vm + 1, vr, l, r,val);
      t[v] = t[v * 2 + 1] | t[v * 2 + 2];
    }
  }

} tr;

bool is_prime(int x) {
  for (int i = 2; i * i <= x; ++i) if (x % i == 0) return 0;
  return x > 1;
}

int tin[100007];
int tout[100007];

void dfs(int v = 0, int p = -1) {
  tin[v] = ord.size();
  ord.pb(v);
  for (int to : g[v]) if (to != p) dfs(to, v);
  tout[v] = (int)ord.size() - 1;
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  for (int i = 2; i < 1000; ++i) if (is_prime(i)) prime_mask[i] = 1;

  cin >> n >> m;
  readArr(a, a + n);
  for (int i = 0; i + 1 < n; ++i) {
    int w1, w2;
    cin >> w1 >> w2; --w1; --w2;
    g[w1].pb(w2);
    g[w2].pb(w1);
  }

  for (int i = 0; i < m; ++i) act[i] = 1;

  dfs();
  tr.build(0, 0, (int)ord.size() - 1);


  int q; cin >> q;
  while (q--) {
    int type; cin >> type;
    int v; cin >> v; --v;
    if (type == 1) {
      int x; cin >> x;
      tr.add(0, 0, (int)ord.size() - 1, tin[v], tout[v], x % m);
    } else {
      cout << (prime_mask & tr.get(0, 0, (int)ord.size() - 1, tin[v], tout[v])).count() << "\n";
    }
  }

}