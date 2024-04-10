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

int n, m, k;
int x[200007];
int y[200007];
pair<int, int> a[300007];

pair<int, int> d[300007];


void solve() {
  cin >> n >> m >> k;
  readArr(x, x + n);
  readArr(y, y + m);
  readArr(a, a + k);

  ll res = 0; 

  sort(a, a + k);

  int uk = 0;
  for (int i = 1; i < n; ++i) {
    while (uk < k && a[uk].x <= x[i - 1]) ++uk;
    if (uk == k) break;
    if (a[uk].x >= x[i]) continue;
    int le = uk;
    while (uk + 1 < k && a[uk + 1].x < x[i]) ++uk;
    int ri = uk;

    int cnt = ri - le + 1;
    ll now = (ri - le + 1) * (ll)(ri - le + 1);

    copy(a + le, a + ri + 1, d);
    sort(d, d + cnt, [](pair<int, int> a, pair<int, int> b) {
      return a.y < b.y;
    });

    int cc = 1;
    for (int j = 1; j < cnt; ++j) {
      if (d[j].y == d[j - 1].y) ++cc; else {
        now -= cc * (ll)cc;
        cc = 1;
      }
    }

    now -= cc * (ll)cc;

    res += now;
  }

  for (int i = 0; i < k; ++i) swap(a[i].x, a[i].y);

  sort(a, a + k);

  uk = 0;
  for (int i = 1; i < m; ++i) {
    while (uk < k && a[uk].x <= y[i - 1]) ++uk;
    if (uk == k) break;
    if (a[uk].x >= y[i]) continue;
    int le = uk;
    while (uk + 1 < k && a[uk + 1].x < y[i]) ++uk;
    int ri = uk;

    int cnt = ri - le + 1;
    ll now = (ri - le + 1) * (ll)(ri - le + 1);

    copy(a + le, a + ri + 1, d);
    sort(d, d + cnt, [](pair<int, int> a, pair<int, int> b) {
      return a.y < b.y;
    });

    int cc = 1;
    for (int j = 1; j < cnt; ++j) {
      if (d[j].y == d[j - 1].y) ++cc; else {
        now -= cc * (ll)cc;
        cc = 1;
      }
    }

    now -= cc * (ll)cc;

    res += now;
  }



  cout << res / 2 << "\n";
}

int main(){
#ifdef LOCAL
	freopen("L_input.txt", "r", stdin);
	//freopen("L_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

}