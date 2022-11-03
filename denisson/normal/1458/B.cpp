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
ll a[111];
ll b[111];

db dp[2][101][103 * 103];

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];

  int uk = 0;

  for (int j = 0; j < 101; ++j) for (int w = 0; w < 103 * 103; ++w) dp[0][j][w] = -1;

  dp[0][0][0] = 0;

  for (int i = 0; i < n; ++i) {

    for (int j = 0; j < 101; ++j) for (int w = 0; w <= (i + 1) * 100; ++w) dp[uk ^ 1][j][w] = -1;

    for (int j = 0; j <= i; ++j)
    for (int w = 0; w <= i * 100; ++w) if (dp[uk][j][w] > -0.5) {

    //  per(i, j, w);

      uax(dp[uk ^ 1][j + 1][w + a[i]], b[i] + dp[uk][j][w]);
      uax(dp[uk ^ 1][j][w], dp[uk][j][w] + (db)b[i] / 2);
    }

    uk ^= 1;
  }

  for (int j = 1; j <= n; ++j) {
    db res = 0;

    for (int w = 0; w < 101 * 100; ++w) if (dp[uk][j][w] > -0.5) {

    //  per(j, w, dp[uk][j][w]);

      uax(res, min(dp[uk][j][w], (db)w));
    }

    cout.precision(10);
    cout << fixed << res << ' ';
  }
}