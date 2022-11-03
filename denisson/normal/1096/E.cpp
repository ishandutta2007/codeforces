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

int n, s, r;

int res = 0;

int cnk[111][111];

int fac[100007];
int ifac[100007];

int get_kek(int n, int k) {
  return mult(fac[n], mult(ifac[k], ifac[n - k]));
}

int calc(int s, int n, int x) {
  if (n == 0) return s == 0;

  int res = 0;

  for (int k = 0; k <= n; ++k) {
    if (k * x > s) break;
    
    int now = mult(cnk[n][k],  get_kek( n + s - k * x - 1 , s - k * x ) );

    if (k % 2 == 0)
    add(res, now); else dec(res, now);
  }

  return res;
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  fac[0] = 1;
  for (int i = 1; i < 100007; ++i) fac[i] = mult(fac[i - 1], i);
  for (int i = 0; i < 100007; ++i) ifac[i] = bp(fac[i], mod - 2);

  cin >> n >> s >> r;
  --n;

  for (int i = 0; i < 111; ++i) {
    cnk[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      add(cnk[i][j], cnk[i - 1][j]);
      add(cnk[i][j], cnk[i - 1][j - 1]);
    }
  }

  for (int x = r; x <= s; ++x) {

    for (int extra = 0; extra <= n; ++extra) {
      if ((extra + 1) * x > s) break;

    //  per(x, extra, calc(s - (extra + 1) * x, n - extra, x));

      add(res, mult(mult(cnk[n][extra], calc(s - (extra + 1) * x, n - extra, x)) , bp(extra + 1, mod - 2) ));
    }

  }

  int coef = get_kek( n + 1 + s - r - 1 , s - r );

  cout << mult(res, bp(coef, mod - 2));

}