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

const ll INF = 3e18;

void solve() {
  int n;
  cin >> n;

  ll ans = -INF;

  vector<int> v(n);
  for (auto &x : v) cin >> x;

  for (int e = 0; e < 2; ++e) {

    for (auto &x : v) x *= -1;
    sort(all(v));

    ll best = (ll) v.back() * (n - 1);
    for (int i = 0; i < n-1; ++i) best += v[i];
    if (best < 0) {
      cout << "INF\n";
      return;
    }
  }

  sort(all(v));

  ll b = (ll) v[0] * v.back();
  ll k = (v[0] + v.back());

  for (int i = 1; i < n-1; ++i) {
    b += (ll) v[i] * v[0];
    k += (v[i] + v[0]);
  }

  for (int i = 0; i < n - 1; ++i) {
    ll t1 = v[i], t2 = v[i + 1];
    ll A = b - k*t1, B = b - k*t2;

  //  per(k, b, t1, t2, A, B);

    ans = max({ans, A, B});

    if (i == n - 2) break;
    b += (ll) v[i+1] * v.back();
    k += (v[i+1] + v.back());

    b -= (ll) v[i+1] * v[0];
    k -= (v[i+1] + v[0]);
  }

  cout << ans << '\n';


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