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

const int N = 100007;
pair<int, int> sum[N];

void solve() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (auto &x : v) cin >> x;

  vector<pair<int, pair<int, int> > > options;
  options.pb(mp(v.back(), mp(1, 0)));

  int ans = 0;

  for (int i = n - 2; i >= 0; --i) {
    for (auto x : options) add(ans, x.y.y);
    vector<int> possible;

    for (auto x : options) {

     // per(i, x.x, v[i]);
      int d = (v[i] + x.x - 1) / x.x;

      int W = x.y.y;
      add(W, mult(d - 1, x.y.x));

      int pos = v[i] / d;

      add(sum[pos].x, x.y.x);
      add(sum[pos].y, W);
      possible.pb(pos);
    }

    possible.pb(v[i]);
    add(sum[v[i]].x, 1);

    options.clear();

    for (auto x : possible) {
      if (sum[x] == mp(0, 0)) continue;
      options.pb(mp(x, sum[x]));
      sum[x] = mp(0, 0);
    }

    //per(i, options);

  }

  for (auto x : options) add(ans, x.y.y);
  cout << ans << '\n';

//exit(0);

}

int main(){
#ifdef LOCAL
  freopen("C_input.txt", "r", stdin);
  //freopen("C_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}