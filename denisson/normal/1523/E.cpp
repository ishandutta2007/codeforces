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

int fac[300007];
int ifac[300007];

int cnk(int n, int k) {
  return mult(fac[n], mult(ifac[k], ifac[n - k]));
}

int pr[100007];

void solve() {

  cin >> n >> k;

  int res = 0;

  pr[1] = bp(n, mod - 2);
  for (int i = 2; i <= n; ++i) {
    pr[i] = mult(pr[i - 1], bp(n - i + 1, mod - 2));
  }

  for (int cnt = 1; cnt < n; ++cnt) {
    ll ost = n - cnt - (k - 1) * (ll)(cnt - 1);
    if (ost < 0) break;

    int por = cnk(cnt + 1 + ost - 1, ost);

    add(res, mult(mult(pr[cnt], fac[cnt]), por)); 
  }


  add(res, 1);
  cout << res << "\n";
}



int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  fac[0] = 1;
  for (int i = 1; i < 300007; ++i) fac[i] = mult(fac[i - 1], i);
  for (int i = 0; i < 300007; i++) ifac[i] = bp(fac[i], mod - 2);

  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

}