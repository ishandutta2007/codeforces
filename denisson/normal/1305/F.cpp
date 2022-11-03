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

#define pper(a) cout << #a << " = " << a << endl;

void per() { cout << endl; }
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
  ll res = 0;
  
void go(ll x) {
    ll now = 0;
    
    for (int i = 0; i < n; ++i) if (a[i] % x != 0) {
        ll kek = x - (a[i] % x);
        if (a[i] > x) uin(kek, a[i] % x);
        now += kek;
    }
    
    uin(res, now);
}
  
void check(ll x) {
  if (x == 0) return;
  vector<ll> t;
  ll uk = 2;
  while (uk * uk <= x) {
      if (x % uk == 0) t.pb(uk);
      while (x % uk == 0) x /= uk;
      ++uk;
  }
  if (x > 1) t.pb(x);
  for (auto c : t) go(c);
}

int main(){
#ifdef LOCAL
  freopen("D_input.txt", "r", stdin);
  //freopen("D_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  
  
  for (int i = 0; i < n; ++i) res += a[i] % 2;
  
  for (int it = 0; it < 20; ++it) {
      int v = myRand32() % n;
      
      check(a[v]);
      check(a[v] + 1);
      check(a[v] - 1);
      
  }
  
  
  cout << res;
    
}