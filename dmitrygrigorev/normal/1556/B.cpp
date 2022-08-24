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

void solve() {

  ll ans = 1e18;

  int n;
  cin >> n;

  vector<int> v(n);
  for (auto &x : v) cin >> x;

  int need = 0;
  int bad = 0;
  ll tut = 0;

  for (int i = 0; i < n; ++i) {
    if (v[i] % 2 != need % 2) {
      bad++;
    }
    else {
      if (bad == 0) {
        need ^= 1;
      }
      else {
        tut += bad;
        bad--;
      }
    }
  }

  if (bad == 0) ans = min(ans, tut);

  need = 1;
  bad = 0;
  tut = 0;

  for (int i = 0; i < n; ++i) {
    if (v[i] % 2 != need % 2) {
      bad++;
    }
    else {
      if (bad == 0) {
        need ^= 1;
      }
      else {
        tut += bad;
        bad--;
      }
    }
  }

  if (bad == 0) ans = min(ans, tut);

  if (ans == 1e18) cout << "-1\n";
  else cout << ans << '\n';

}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}