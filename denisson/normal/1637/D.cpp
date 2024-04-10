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

ll dp[2][101 * 101];

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {

    int n;
    cin >> n;
    vector<int> a(n);
    readArr(all(a));
    vector<int> b(n);
    readArr(all(b));

    int sum = 0;

    int uk = 0; 

    const ll INF = 1e18;
    fill((ll*)dp, (ll*)dp + 2 * 101 * 101, INF);

    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
      fill(dp[uk ^ 1], dp[uk ^ 1] + 101 * 101, INF);

      for (int fr_w = 0; fr_w <= i * 100; ++fr_w) {
        uin(dp[uk ^ 1][fr_w + a[i]], dp[uk][fr_w] + a[i] * a[i] * (n - 1) + b[i] * b[i] * (n - 1) + 2 * (a[i] * fr_w + b[i] * (sum - fr_w)));
        uin(dp[uk ^ 1][fr_w + b[i]], dp[uk][fr_w] + a[i] * a[i] * (n - 1) + b[i] * b[i] * (n - 1) + 2 * (b[i] * fr_w + a[i] * (sum - fr_w)));
      }

      uk ^= 1;

      sum += a[i] + b[i];
    }


    ll res = INF;
    for (int i = 0 ;i < 101 * 101; ++i) uin(res, dp[uk][i]);
    cout << res << "\n";

  }


}