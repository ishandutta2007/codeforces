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

const int mod = 998244353;

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

ll ge(ll v) {
  if (v < 0) return 0;
  return v * (v + 1) / 2;
}

ll sum(ll vl, ll vr) { 
  return ge(vr) - ge(vl - 1);
}

const int N = 300007;
int fact[N];
int rv[N];

int C(int n, int k) {
  if (k < 0 || k > n) return 0;
  return mult(fact[n], mult(rv[k], rv[n - k]));
}


int main(){
#ifdef LOCAL
  freopen("I_input.txt", "r", stdin);
  //freopen("I_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  fact[0] = 1;
  for (int i = 1; i < N; ++i) fact[i] = mult(fact[i - 1], i);
  for (int i = 0; i < N; ++i) rv[i] = bp(fact[i], mod - 2);

  int n, k;
  cin >> n >> k;

  vector<int> v(n);
  for (auto &x : v) {
    cin >> x;
  }

  vector<int> pos(n);
  for (int i = 0; i < n; ++i) pos[v[i]] = i;

  vector<int> nxt(n);
  for (int i = 0; i < n; ++i) {
    if (v[i] == n - 1) nxt[i] = 0;
    else nxt[i] = pos[v[i] + 1] + 1;
  }

 // per(nxt);

  int must = 0;
  for (int i = 0; i + 1 < n; ++i) {
    if (nxt[i] > nxt[i + 1]) must++;
  }

  //k--;

  //per(k, must);

  int ans = 0;
  for (int choose = 0; choose <= n - 1 - must; ++choose) {
    add(ans, mult(C(n - 1 - must, choose), C(k, choose + must + 1)));
  }

  cout << ans;





}