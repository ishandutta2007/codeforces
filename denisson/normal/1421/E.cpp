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
ll a[200007];
pair<int, int> b[200007];

int main(){
#ifdef LOCAL
	freopen("N_input.txt", "r", stdin);
	//freopen("N_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  readArr(a, a + n);
  for (int i = 0; i < n; ++i) {
    b[i] = mp(a[i], i);
  }

    if (n == 1) cout << a[0], exit(0);
  sort(b, b + n);

  ll sum = 0;
  for (int i = 0; i < n; ++i) sum += a[i];

  if (n % 2 == 0) {

    ll res = -1e18;

    sort(a, a + n);

    int ost = 0;
    if (n % 6 == 2) ost = 2;
    if (n % 6 == 0) ost = 1;

    for (int i = 0; i <= n; ++i) {
      if (i % 3 == ost) uax(res, sum);
      sum -= 2 * a[i];
    }

    cout << res;

  } else {

    ll saved = sum;

    ll res = -1e18;

    sort(a, a + n);

    int ost = 0;
    if (n % 6 == 3) ost = 1;
    if (n % 6 == 5) ost = 2;

    for (int i = 0; i <= n; ++i) {
      if (i * 2 + 1 != n) if (i % 3 == ost) uax(res, sum);
      sum -= 2 * a[i];
    }

    sum = saved;

    vector<int> t;
    for (int i = 0; i < n / 2; ++i) {
      sum -= 2 * b[i].x;
      t.pb(b[i].y);
    }
    sort(all(t));

    int ok = 0;
    for (int i = 0; i < t.size(); ++i) {
      if (t[i] != i * 2 + 1) ok = 1;
    }

    if (ok) {
      uax(res, sum);
    } else {
      int v = n / 2;
      sum -= 2 * b[v].x;
      sum += 2 * b[v - 1].x;
      uax(res, sum);
    }

    cout << res;

  }


}