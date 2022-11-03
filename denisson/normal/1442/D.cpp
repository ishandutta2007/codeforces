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
vector<ll> a[3333];
ll sum[3333];

ll res = 0;

ll dp[15][3333];

const ll LINF = 1e18;

struct Tree {
  vector< pair<int, ll> > t[3333 * 4];

  void add(int v, int vl, int vr, int l, int r, pair<int, ll> val) {
    if (r < vl || l > vr) return;
    if (vl >= l && vr <= r) t[v].pb(val); else {
      int vm = (vl + vr) >> 1;
      add(v * 2 + 1, vl, vm, l, r, val);
      add(v * 2 + 2, vm + 1, vr, l, r, val);
    }
  } 

  void go(int v, int vl, int vr, int hh = 0) {
    
    for (int w = 0; w <= k; ++w) {
      dp[hh + 1][w] = dp[hh][w];
    }

      for (auto [w1, w2] : t[v]) 
    for (int w = k; w >= 0; --w) if (w >= w1) {
        uax(dp[hh + 1][w], dp[hh + 1][w - w1] + w2);
      }

    if (vl == vr) {

      uax(res, dp[hh + 1][k]);
      ll su = 0;
      for (int i = 0; i < a[vl].size(); ++i) {
        su += a[vl][i];
        if (i + 1 > k) break;
        uax(res, dp[hh + 1][k - i - 1] + su);
      }

    } else {
      int vm = (vl + vr) >> 1;
      go(v * 2 + 1, vl, vm, hh + 1);
      go(v * 2 + 2, vm + 1, vr, hh + 1);
    }
  }
} tr;

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    int sz;
    cin >> sz;
    a[i].resize(sz);
    for (int j = 0; j < sz; ++j) cin >> a[i][j], sum[i] += a[i][j];


    if (i) tr.add(0, 0, n - 1, 0, i - 1, mp(a[i].size(), sum[i]));
    if (i + 1 != n) tr.add(0, 0, n - 1, i + 1, n - 1, mp(a[i].size(), sum[i]));

  }


  dp[0][0] = 0;
  for (int i = 1; i < 3333; ++i) dp[0][i] = -LINF;


  tr.go(0, 0, n - 1);


  
  cout << res << endl;

  
}