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

int n, s;
pair<int, int> a[70007];

int dp[70007];
bitset<70007> b[2];

int used[70007];

int ans[70007];
vector<int> q[70007];

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x; a[i].y = i;
  }
  sort(a, a + n);
  reverse(a, a + n);

  if (s < a[0].x) {
    cout << -1, exit(0);
  }

  s -= a[0].x;

  fill(dp, dp + 70007, -1);
  dp[0] = 1;

  int uk = 0;
  b[uk][0] = 1;
  for (int i = 1; i < n; ++i) {
    b[uk ^ 1] = b[uk] | (b[uk] << a[i].x);
    b[uk] ^= b[uk ^ 1];

    for (int v = b[uk]._Find_first(); v <= s; v = b[uk]._Find_next(v)) {
      dp[v] = i;
    }

    uk ^= 1;
  }

  if (dp[s] == -1) {
    cout << -1; exit(0);
  }

  while (s > 0) { 
    int v = dp[s];
    s -= a[v].x;
    used[v] = 1;
  }

  vector<int> g;

  for (int i = 0; i < n; ++i) {
    if (used[i]) {
      ans[a[i].y] = a[i].x;
    } else g.pb(i);
  }

  ans[a[g.back()].y] = a[g.back()].x;
  for (int i = (int)g.size() - 2; i >= 0; --i) {
    ans[a[g[i]].y] = a[g[i]].x - a[g[i + 1]].x;
    q[a[g[i]].y].pb(a[g[i + 1]].y);
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << ' ' << q[i].size() << ' ';
    for (int v : q[i]) cout << v + 1 << ' ';
    cout << "\n";
  }

}