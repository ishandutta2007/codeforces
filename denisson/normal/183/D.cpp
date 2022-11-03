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

int n, m;
db a[3003][303];
db last[303][3003];
db val[3003];
int cnt[3003];

db f[3003];

void recalc(int v) {
  fill(f, f + n + 1, 0);
  for (int i = cnt[v]; i < n; ++i) {
    if (i) f[i] += f[i - 1] * (1 - a[i][v]);
    if (i) {
        f[i] += last[v][i - 1] * a[i][v];
    } else {
        f[i] += a[i][v];
    }
  }
  copy(f, f + n + 1, last[v]);
  
  ++cnt[v];
  
  val[v] += last[v][n - 1];
}

int main(){
#ifdef LOCAL
  freopen("D_input.txt", "r", stdin);
  //freopen("D_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    int x;
    cin >> x;
    a[i][j] = x / 1000.0;
    //   cin >> a[i][j];
  }
  
  db res = 0;
  
  for (int i = 0; i < m; ++i) {
    val[i] = 1;
    for (int j = 0; j < n; ++j) {
      val[i] *= 1 - a[j][i];
      last[i][j] = val[i];
    }
   // recalc(i);
  }
    
  for (int it = 0; it < n; ++it) {
    int v = -1;
    db now = -1;
    
    for (int i = 0; i < m; ++i) if (1 - val[i] > now) {
        now = 1 - val[i];
        v = i;
    }
    
 //   pper(now);
    
    res += now;
    recalc(v);
  }
  
  cout.precision(10);
  cout << fixed << res;
}