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
pair<int, int> a[111];
int used[222];
 
void solve() {
  cin >> n >> k;
  for (int i = 0; i <= 2 * n; ++i) used[i] = 0;
  vector<pair<int ,int> > d;
  for (int i = 0; i < k; ++i) cin >> a[i].x >> a[i].y, --a[i].x, --a[i].y, d.pb(a[i]), used[a[i].x] = used[a[i].y] = 1;
 
  vector<int> t;
 
  for (int i = 0; i < 2 * n; ++i) if (!used[i]) t.pb(i);
 
  for (int i = 0; i * 2 < t.size(); ++i) {
    d.pb(mp(t[i], t[i + (int)t.size() / 2]));

    per(t[i], t[i + (int)t.size() / 2]);
  }

  pper(t);
 
  int res = 0;
 
  for (int i = 0; i < d.size(); ++i) for (int j = i + 1; j < d.size(); ++j) {
    if (d[i].x > d[i].y) swap(d[i].x, d[i].y);
    if (d[j].x > d[j].y) swap(d[j].x, d[j].y);
    if (d[i].x < d[j].x) {
      if (d[i].y > d[j].x && d[i].y < d[j].y) ++res;
    } else {
      if (d[j].y > d[i].x && d[j].y < d[i].y) ++res;
    }
  }
 
 
  cout << res << "\n";
 
 
}
 
int main(){
#ifdef LOCAL
  freopen("A_input.txt", "r", stdin);
  //freopen("C_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
 
}