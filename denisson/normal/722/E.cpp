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

int n, m, k, s;
pair<int, int> a[2007];

int fac[200007];
int ifac[200007];

int dp[2007][24];

int cnk(int n, int k) {
 //  per("cnk", n, k);
  return mult(fac[n], mult(ifac[k], ifac[n - k]));
}

int path(int dx, int dy) {
  // per("path", dx, dy);
  if (min(dx, dy) < 0) return 0;
  return cnk(dx + dy, dx);
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  fac[0] = 1;
  for (int i = 1; i < 200007; ++i) fac[i] = mult(fac[i - 1], i);
  for (int i = 0; i < 200007; ++i) ifac[i] = bp(fac[i], mod - 2);

  cin >> n >> m >> k >> s;
  readArr(a, a + k);

  int need = 1;
  for (int i = 0; i < k; ++i) if (a[i] == mp(1, 1)) need = 0;
  if (need) a[k++] = mp(1, 1), s <<= 1;

  need = 1;
  for (int i = 0; i < k; ++i) if (a[i] == mp(n, m)) need = 0;
  if (need) a[k++] = mp(n, m), s <<= 1;

  sort(a, a + k, [](pair<int, int> a, pair<int, int> b) {
    return a.x + a.y < b.x + b.y;
  });

  dp[0][1] = 1;

  // for (int i = 0; i < k; ++i) cout << a[i] << endl;

  for (int i = 1; i < k; ++i) {
    for (int j = 2; j < 24; ++j) {
      dp[i][j] = path(a[i].x - 1, a[i].y - 1);
      for (int s = 1; s < j; ++s) dec(dp[i][j], dp[i][s]);

      if (j != 23)
      for (int s = 0; s < i; ++s) {
        dec(dp[i][j], mult( dp[s][j], path(a[i].x - a[s].x, a[i].y - a[s].y) ));
      }

     // if (dp[i][j] != 0)
     // cout << i << ' ' << j << ' ' << dp[i][j] << endl;

    }
  }

  int res = 0;
  int now = (((s + 1) >> 1) + 1) >> 1; 
  for (int i = 2; i < 24; ++i) {
    add(res, mult(now, dp[k - 1][i]));
   // per(now, dp[k - 1][i]);
    now = (now + 1) >> 1;
  }

 // pper(res);

  cout << mult(res, bp(path(n - 1, m - 1), mod - 2));

}