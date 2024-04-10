#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define db double
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

const int N = 107;
db dp[2][N][N];

int uk = 0;

int main(){
#ifdef LOCAL
  freopen("M_input.txt", "r", stdin);
  //freopen("M_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  vector<int> v(n);
  for (auto &x : v) cin >> x;

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) dp[0][i][j] = 1.;
  }

  if (k > 900) k = 900;

  int Q = n * (n+1) / 2;

  //[3;4] = 7
  //[4;4] = 8

  for (int a = 0; a < k; ++a) {
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {

        db tp = ((db) ((i*(i+1)/2) + (j - i) * (j - i - 1) / 2 + (n - j) * (n - j - 1) / 2) / Q) * dp[uk][i][j];

        for (int sum = (i + 1) + j; sum <= j + (n - 1); ++sum) {
          int we = abs(2 * j - sum), he = min(abs(2 * n - sum), abs(2 * i - sum));
          if (we < he) tp += ((db) (he - we) / (2*Q)) * dp[uk][i][sum - j];
        }

       // per(tp);

        for (int sum = i; sum <= i + (j - 1); ++sum) {
          int we = abs(2 * i - sum), he = min(abs(2 * (-1) - sum), abs(2 * j - sum));
          if (we < he) tp += ((db) (he - we) / (2*Q)) * dp[uk][sum - i][j];
        }

        for (int sum = j; sum <= i + (n - 1); ++sum) {
          int we = max(abs(2 * i - sum), abs(2 * j - sum)), he = min(abs(2 * (-1) - sum), abs(2 * n - sum));
          if (we < he) tp += ((db) (he - we) / (2*Q)) * dp[uk][sum - i][sum - j];
        }

       // per(tp);
       // exit(0);

        dp[uk^1][i][j] = tp;
        dp[uk^1][j][i] = 1.-tp;

      }
    }
    uk ^= 1;
  }

  db ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (v[i] > v[j]) ans += dp[uk][i][j];
    }
  }

  cout.precision(10);
  cout << fixed << ans;



}