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

string s;

int n;
int16_t ma[5007][5007];
bool le[5007][5007];

int dp[5007][5007];

int val[5007];

void solve() {
  cin >> n >> s;


  for (int i = 0; i <= n + 1; ++i) 
    for (int j = 0; j <= n + 1; ++j) 
      ma[i][j] = le[i][j] = dp[i][j] = 0;

  for (int i = n - 1; i >= 0; --i) {
    for (int j = i + 1; j < n; ++j) {
      if (s[i] == s[j]) {
        ma[i][j] = ma[i + 1][j + 1] + 1;
        le[i][j] = le[i + 1][j + 1];
      } else {
        le[i][j] = s[i] < s[j];
      }
    }
  }

  int res = 0;

  for (int i = 0; i < n; ++i) {

    fill(val + i, val + n + 1, -1e9);

    for (int j = 0; j < i; ++j) {
      if (le[j][i]) {
        uax(val[ i + ma[j][i] ], dp[j][n - 1]);
      }
    }


    int v = i - 1;
    for (int j = i; j < n; ++j) {
      dp[i][j] = 1;
      uax(dp[i][j], val[j] + 1);
      if (i != j) {
        uax(dp[i][j], dp[i][j - 1] + 1);
      }
      uax(res, dp[i][j]);
     // per(i, j, dp[i][j]);
    }
  }

  cout << res << '\n';
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
  while (tt--) { solve(); }

}