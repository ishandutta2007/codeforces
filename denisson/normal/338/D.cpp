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

ll n, m;
int k;
ll a[10007];

const ll LINF = 1e18 + 7;

ll mu(ll a, ll b) {
  ll can = LINF / b;
  if (a > can) return LINF;
  return a * b;
}

__int128 gcd (__int128 a, __int128 b, __int128& x, __int128& y) {
  if (a == 0) {
    x = 0; y = 1;
    return b;
  }
  __int128 x1, y1;
  __int128 d = gcd (b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
 
bool find_any_solution (__int128 a, __int128 b, __int128 c, __int128& x0, __int128& y0, __int128& g) {
  g = gcd (a, b, x0, y0);
  if (c % g != 0)
    return false;
  x0 *= c / g;
  y0 *= c / g;
  if (a < 0)   x0 *= -1;
  if (b < 0)   y0 *= -1;
  return true;
}

/* 
 * Implementation for arbitrary p_i
 *   x % p_i = r_i
 *   restores x
 *   returns -1 if no solution
 */  
__int128 restore(vector<__int128> r, vector<__int128> p) {
  __int128 last_p = 1;
  __int128 last_r = 0;

  for (int i = 0; i < p.size(); ++i) {
    __int128 x0, y0, g;
    if (find_any_solution(last_p, p[i], r[i] - last_r, x0, y0, g)) {
      __int128 x = last_p * x0 + last_r;
      __int128 _lcm = last_p * (p[i] / g);
      x %= _lcm;
      if (x < 0) x += _lcm;
      last_r = x;
      last_p *= p[i] / g; 
    } else return -1;
  }

  return last_r;
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> m >> k;
  readArr(a, a + k);

  ll lc = a[0];
  for (int i = 1; i < k; ++i) {
    ll gc = __gcd(lc, a[i]);
    if (mu(lc, a[i] / gc) > n) cout << "NO", exit(0);
    lc *= a[i] / gc;
  } 

  if (lc > n) cout << "NO", exit(0);

  vector<__int128> r, p;
  for (int i = 0; i < k; ++i) {
    r.pb(((-i % a[i]) + a[i]) % a[i]);
    p.pb(a[i]);
  }

  //pper(r);
  //pper(p);

  ll x = restore(r, p);

  //pper(x);
  if (x == 0) x += lc;

  if (x == -1) cout << "NO", exit(0);

  if (x + k - 1 > m) cout << "NO", exit(0);

  for (int i = 0; i < k; ++i) {
    if (a[i] != __gcd(lc, x + i)) cout << "NO", exit(0);
  }

  cout << "YES";

}