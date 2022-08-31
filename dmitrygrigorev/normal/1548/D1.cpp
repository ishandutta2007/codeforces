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

const int REM = 8;
int pt[REM][REM];

ll gcd(ll x, ll y) {
  if (y==0) return x;
  return gcd(y, x%y);
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    pt[x % REM][y % REM]++;
  }

  ll ans = 0;

  vector<pair<int, int> > allm;
  for (int i = 0; i < REM; ++i) for (int j = 0; j < REM; ++j) allm.pb(mp(i, j));
  for (auto x : allm) for (auto y : allm) for (auto z : allm) {
    if (y < x || z < y) continue;
    ll W = (ll) pt[x.x][x.y] * pt[y.x][y.y] * pt[z.x][z.y];
    if (x == y && x == z) {
      W = (ll) pt[x.x][x.y] * (pt[x.x][x.y] - 1) * (pt[x.x][x.y] - 2) / 6;
    }
    else if (x == y) {
      W = (ll) pt[x.x][x.y] * (pt[x.x][x.y] - 1) * pt[z.x][z.y] / 2;
    }
    else if (y == z) {
      W = (ll) pt[x.x][x.y] * (pt[z.x][z.y] - 1) * pt[z.x][z.y] / 2;
    }

   // if (W != 0) per(x, y, z, W);

    ll dx1 = y.x - x.x;
    ll dx2 = z.x - x.x;
    ll dy1 = y.y - x.y;
    ll dy2 = z.y - x.y;

    ll sq = abs(dy1 * dx2 - dy2 * dx1) / 2;
    sq++;
    sq -= gcd(dx1, dy1) / 2;
    sq -= gcd(dx2, dy2) / 2;
    sq -= gcd(dx1 - dx2, dy1 - dy2) / 2;
    if (sq % 2 != 0) ans += W;

  }

  cout << ans;


}