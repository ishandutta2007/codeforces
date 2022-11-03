#include <bits/stdc++.h>
#define ll long long
#define db double
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
int a[500007];


bool isPrime(int x) {
    for (int i = 2; i * i <= x; ++i) if (x % i == 0) return 0;
    return x > 1;
}

int cnt[10000007];
int func[10000007];
int sum[10000007];
int step[500007];

int main(){
#ifdef LOCAL
  freopen("D_input.txt", "r", stdin);
  //freopen("D_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  step[0] = 1;
  for (int i = 1; i < 500007; ++i) step[i] = mult(step[i - 1], 2);
  
  cin >> n;
  readArr(a, a + n);
  for (int i = 0; i < n; ++i) ++cnt[a[i]];
    
  int base = 0;

  for (int v = (int)1e7; v >= 1; --v) {
      int cc = 0;
      for (int i = v; i <= (int)1e7; i += v) cc += cnt[i], dec(sum[v], sum[i]);
      add(func[v], step[cc]);
      dec(func[v], 1);
      add(sum[v], func[v]);
      if (v > 1) add(base, sum[v]);
  }
  
  vector<int> t;
  for (int x = 2; x * x <= (int)1e7; ++x) if (isPrime(x)) t.pb(x);
  
  int ans = 0;
    
  for (int i = 0; i < n; ++i) {
    vector<int> d;
    int x = a[i];
    for (int y : t) {
        if (y * y > x) break;
        if (x % y == 0) d.pb(y);
        while (x % y == 0) x /= y;
    }
    if (x > 1) d.pb(x);
    int now = base;
//    pper(base);
   // pper(d);
    for (int mask = 1; mask < (1 << d.size()); ++mask) {
        int pr = 1;
        int cnt = 0;
        for (int j = 0; j < d.size(); ++j) if ((mask >> j) & 1) pr *= d[j], ++cnt;
        if (cnt & 1) dec(now, func[pr]); else add(now, func[pr]);
    }
    
   // pper(now);
    
    add(ans, now);
  }
  
  cout << ans;
}