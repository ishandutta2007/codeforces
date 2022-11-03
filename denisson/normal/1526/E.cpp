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

int n, m;
int a[200007];

int nxt[200007];
int to[200007];
int can[200007];

int fac[200007];
int ifac[200007];

int cnk(int n, int k) {
  return mult(fac[n], mult(ifac[k], ifac[n - k]));
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  fac[0] = 1;
  for (int i = 1; i < 200007; ++i) fac[i] = mult(fac[i - 1], i);
  for (int i = 0; i < 200007; ++i) ifac[i] = bp(fac[i], mod - 2);

  cin >> n >> m;
  readArr(a, a + n);

  for (int i =0 ; i < n; ++i) to[a[i]] = i;
  to[n] = -1;

  int free = 0;
  int need = 0;

  for (int i = 0; i + 1 < n; ++i) {
    can[i] = to[a[i] + 1] < to[a[i + 1] + 1];
    if (!can[i]) ++need; else ++free;
  }

  int res = 0;

  for (int i = 1; i <= min(n, m); ++i) {
    int coef = cnk(m, i);

    int cc = i - 1;

    if (need > cc) continue;

    add(res, mult(coef, cnk(free, cc - need)));
  }

  cout << res;
}