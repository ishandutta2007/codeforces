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

struct FenwickTree1 {

  vector<ll> t;
  int MAX_SIZE;

  // Sum [0..v]
  ll get(int v) {
    if (v < 0) return 0;
    ll res = 0;
    for (; v >= 0; v = (v & (v + 1)) - 1) {
      res += t[v];
    }
    return res;
  }

  FenwickTree1(int n) {
    MAX_SIZE = 2*n;
    t.assign(2*n, 0);
  }

  // Sum [vl..vr]
  bool get(int vl, int vr) {
    ll res = get(vr);
    if (vl > 0) {
      res -= get(vl - 1);
    }
    return (res == vr - vl + 1);
  }

  // Update t[v] += val;
  void up(int v, int val) {
    for (; v < MAX_SIZE; v = v | (v + 1)) {
      t[v] += val;
    }
  }
};

db eps = 1e-9;

int bs(vector<db> &groups, db x) {
  int L = 0, R = groups.size() + 1;
  while (R-L>1) {
    int M = (L+R)/2;
    if (groups[M - 1] > x + eps) L = M;
    else R = M;
  }

  return L;

}

void solve() {

  int n, m;
  cin >> n >> m;

  vector<int> v(n);
  for (auto &x : v) cin >> x;

  sort(all(v), greater<int>());
  vector<db> groups;

  vector<vector<int> > arr(m);
  vector<ll> sum(m, 0);

  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;

    arr[i].resize(x);
    for (auto &t : arr[i]) {
      cin >> t;
      sum[i] += t;
    }

    groups.pb((db) sum[i] / arr[i].size());
  }

  sort(all(groups), greater<db>());
  FenwickTree1 a(n), b(n), c(n);

  for (int i = 0; i < n; ++i) {
    if (i - 1 >= 0 && i - 1 < m) a.up(i, (v[i] >= groups[i - 1] - eps));
    if (i >= 0 && i < m) b.up(i, (v[i] >= groups[i] - eps));
    if (i + 1 < m) c.up(i, (v[i] >= groups[i + 1] - eps));
  }

  for (int i = 0; i < m; ++i) {
    for (auto x : arr[i]) {
      db old = ((db) sum[i] / arr[i].size());
      db nn = ((db) (sum[i] - x) / (arr[i].size() - 1));

      int index = bs(groups, old);
      int nindex = bs(groups, nn);

      if (old - eps > nn) nindex--;
      bool good = true;

      if (index <= nindex) {
        if (!b.get(0, index - 1)) good = false;
        if (!c.get(index, nindex - 1)) good = false;
        if (nn > v[nindex] + eps) good = false;
        if (!b.get(nindex + 1, m - 1)) good = false;
      }

      else {
        if (!b.get(0, nindex - 1)) good = false;
        if (nn > v[nindex] + eps) good = false;
        if (!a.get(nindex + 1, index)) good = false;
        if (!b.get(index + 1, m - 1)) good = false;
      }

      cout << good;
    }
  }

  cout << '\n';


}

int main(){
#ifdef LOCAL
  freopen("B_input.txt", "r", stdin);
  //freopen("B_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}