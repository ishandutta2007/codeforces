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

const int KEK = 45;

db dp[500007][KEK];
int p[500007];

db saved[KEK];
db now[KEK];
db now2[KEK];

void go(int v) {
  for (int it = 0; it < KEK; ++it) {
    if (v == 1) break;
    
    now[0] = 0.5;
    for (int i = 0; i + 1 < KEK; ++i) now[i + 1] = 0.5 + 0.5 * dp[v][i];
    
    if (it == 0) {
        for (int i = 0; i < KEK; ++i) now2[i] = 1;
    } else {
        now2[0] = 0.5;
        for (int i = 0; i + 1 < KEK; ++i) now2[i + 1] = 0.5 + 0.5 * saved[i];
    }
    
    for (int i = 0; i < KEK; ++i) saved[i] = dp[p[v]][i], dp[p[v]][i] *= now[i] / now2[i];
    
    v = p[v];
  }
}

int main(){
#ifdef LOCAL
  freopen("D_input.txt", "r", stdin);
  //freopen("D_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  for (int i = 0; i < 500007; ++i) for (int j = 0; j < KEK; ++j) dp[i][j] = 1;
  
  int q;
  cin >> q;
  int n = 2;
  while (q--) {
      int ty, v;
      cin >> ty >> v;
      if (ty == 1) {
        p[n++] = v;
        go(n - 1);
      } else {
        db ans = 0;
        
        for (int i = 1; i < KEK; ++i) ans += (dp[v][i] - dp[v][i - 1]) * i;
        
        cout.precision(7);
        cout << fixed << ans << "\n";
      }
      
  }
  
  
}