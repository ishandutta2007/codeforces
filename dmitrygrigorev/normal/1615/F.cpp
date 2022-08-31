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

const int N = 2007;
pair<int, int> dp[N][2*N];

void transform(string &s) {
  for (int i = 0; i < s.size(); i += 2) {
    if (s[i] == '0') s[i] = '1';
    else if (s[i] == '1') s[i] = '0';
  }
}

void solve() {
  int n;
  cin >> n;

  string s, t;
  cin >> s >> t;

  transform(s);
  transform(t);

  for (int i = 0; i <= n; ++i) for (int j = -n; j <= n; ++j) dp[i][j + n] = mp(0, 0);
  dp[0][0 + n] = mp(1, 0);

  for (int i = 0; i < n; ++i) {
    for (int j = -i; j <= i; ++j) {
      for (int a = 0; a < 2; ++a) {
        if (s[i] != '?' && s[i] - '0' != a) continue;
        for (int b = 0; b < 2; ++b) {
          if (t[i] != '?' && t[i] - '0' != b) continue;
         // per(i, j, a, b, dp[i][j + n]);
          int cost = 0;
          int balance = j;

          if (a == 1) {
            if (balance >= 0) cost -= i;
            else cost += i;
            balance++;
          }
          if (b == 1) {
            if (balance <= 0) cost -= i;
            else cost += i;
            balance--;
          }

          //per(i, j, a, b, cost, dp[i][j + n]);

          if (cost < 0) cost += mod;
          int A = dp[i][j + n].x;
          int B = dp[i][j + n].y;
          add(B, mult(A, cost));

          add(dp[i + 1][balance + n].x, A);
          add(dp[i + 1][balance + n].y, B);
        }
      }
    }
  }

  cout << dp[n][n].y << '\n';

}

int main(){
#ifdef LOCAL
  freopen("F_input.txt", "r", stdin);
  //freopen("F_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}