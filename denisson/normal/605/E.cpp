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
db a[1111][1111];
bool used[1111];
db dp[1111];
db base[1111];


int main(){
#ifdef LOCAL
  freopen("D_input.txt", "r", stdin);
  //freopen("D_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;// n = 1000;
  for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        //  a[i][j] = myRand32() % 100;
        int x; cin >> x;
          //  a[i][j] = j == (i + 1);
           a[i][j] = x / (db)100;
         
      }
      base[i] = 1 - a[i][n - 1];
  }
  
  // vector<int> ord;
  // ord.pb()
 
  used[n - 1] = 1;
  for (int it = 0; it + 1 < n; ++it) {
    int v = -1;
    db best = 1e38;
    for (int i = 0; i + 1 < n; ++i) if (!used[i]) {
        if (base[i] > 0.99999999) continue;
        db now = (dp[i] + 1) / (1 - base[i]);
        if (v == -1 || now < best) {
            best = now; v = i;
        }
    }
    assert(v != -1);
    used[v] = 1;
    
    dp[v] = best;
    
    for (int i = 0; i < n; ++i) if (!used[i]) {
        dp[i] += base[i] * a[i][v] * dp[v];
        base[i] *= 1 - a[i][v];
    }
    
    if (v == 0) break;
  }
 
 cout.precision(10);
 cout << fixed << dp[0];
}