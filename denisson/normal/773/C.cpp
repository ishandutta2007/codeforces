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
ll a[111111];
unordered_map<ll, int> se;



bool can(int cnt) {

  vector<ll> shl;

  vector<ll> last;

  for (int i = cnt + 1; i <= se[1]; ++i) shl.pb(1);

  for (ll v = 2; cnt; v <<= 1) {
    int ost = (int)se[v] - cnt;
    if (ost > 0) while(ost--) shl.pb(v); else {
      for (int i = 0; i < -ost; ++i) last.pb(v >> 1);
        cnt += ost;
    }
  }

  for (auto [x, cc] : se) if (__builtin_popcountll(x) != 1) for (int i = 0; i < cc; ++i) shl.pb(x);

 // pper(last);
 //// pper(shl);

  sort(all(last));
  sort(all(shl));

  if (last.size() < shl.size()) return 0;
  for (int i = 0; i < shl.size(); ++i) {
    ll x = shl[(int)shl.size() - 1 - i];
    ll y = last[(int)last.size() -1  - i];
    if (x > 2 * y) return 0;
  }

  return 1;
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  readArr(a, a + n);


  int le = 0, ri = 0;

  for (int i = 0; i < n; ++i) se[a[i]]++;


  int vr = se[1] + 1; int vl = 0;

  while (vl + 1 < vr) {
    int vm = (vl + vr) >> 1;
    if (can(vm)) vr = vm; else vl = vm;
  }

  if (vl + 1 > se[1]) cout << -1;
  for (int i = vl + 1; i <= se[1]; ++i) cout << i << ' ';
}