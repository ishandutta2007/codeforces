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

string a[100007];


int fac[300007];
int ifac[300007];


int cnk(int n, int k) {
  return mult(fac[n], mult(ifac[k], ifac[n - k]));
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  fac[0] = 1;
  for (int i = 1; i < 300007; ++i) fac[i] = mult(fac[i - 1], i);
  for (int i = 0; i < 300007; ++i) ifac[i] = bp(fac[i], mod - 2);

  int n;
  cin >> n;
  readArr(a, a + n);

  int c0 = 0, c1 = 0;
  int emp = 0;

  int res = 0;

  for (int i = 0; i < n; ++i) {
    if (a[i][0] == 'W') ++c0;
    if (a[i][1] == 'W') ++c0;
    if (a[i][0] == 'B') ++c1;
    if (a[i][1] == 'B') ++c1;
    if (a[i][0] == '?') ++emp;
    if (a[i][1] == '?') ++emp;
  }

  int delt = abs(c0 - c1);
  if (delt > emp) {
    cout << 0, exit(0);
  }

  int ost = (emp - delt);
  if (ost % 2 != 0) {
    cout << 0, exit(0);
  }

  res = cnk(emp, ost >> 1);

  int to_dec = 1;
  int was10 = 1, was01 = 1;

  for (int i = 0; i < n; ++i) {
    if (a[i] == "WW" || a[i] == "BB") {
      to_dec = 0;
      break;
    }
    int cc = 0;
    if (a[i][0] == '?') ++cc;
    if (a[i][1] == '?') ++cc;
    if (cc == 2) {
      to_dec = mult(to_dec, 2);
    }

  }
  for (int i = 0; i < n; ++i) {
    if ((a[i][0] == 'W' || a[i][0] == '?') && (a[i][1] == 'B' || a[i][1] == '?')) {} else was10 = 0;
    if ((a[i][0] == 'B' || a[i][0] == '?') && (a[i][1] == 'W' || a[i][1] == '?')) {} else was01 = 0;


  }

  dec(res, to_dec);
  add(res, was10);
  add(res, was01);

  cout << res;
}