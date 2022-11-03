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

int n;
int a[300007];

int ma[300007];
int ma2[300007];


int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  readArr(a, a + n);

  for (int i = 0; i < n; ++i) {

    uax(ma[1], a[i]);

    if (i > 0 && i + 1 < n) {

      int le = 1 + 2 * min(i, n - i - 1);
      uax(ma[le], max(min(a[i - 1], a[i]), min(a[i], a[i + 1])));      

    }

    if (i + 1 < n) {
      int le2 = 2 * (1 + min(i, n - i - 2));

      // per(i, le2);

      uax(ma2[le2], max(a[i], a[i + 1]));
    }

  }

  int val = 0;
  for (int i = n - (n % 2 == 0); i >= 1; --i) {
    uax(val, ma[i]);
    uax(ma[i], val);
  }

  val = 0;
  for (int i = n - (n % 2 == 1); i >= 1; --i) {
    uax(val, ma2[i]);
    uax(ma2[i], val);
  }

  vector<int> t;

  for (int i = 1; i <= n; ++i) {
    if (i % 2 == 1) t.pb(ma[i]); else t.pb(ma2[i]);
  }

  reverse(all(t));
  for (int x : t) cout << x << ' ';

}