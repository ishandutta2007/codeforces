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
db a[111];
db p[111];

db pref[111];
db suf[111];

int main(){
#ifdef LOCAL
  freopen("D_input.txt", "r", stdin);
  //freopen("D_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      a[i] = x / 100.0;
      p[i] = 1 - a[i];
  }
  
//  exit(0);
  
  db res = 0;
  for (int ii = 1; ii < 500000; ++ii) {
    int v = 0; db best = -1;
    
    db base = 1;
    for (int i = 0; i < n; ++i) {
        base *= 1 - p[i];
        pref[i] = base;
    }
    
    base = 1;
    for (int i = n - 1; i >= 0; --i) {
        base *= 1 - p[i];
        suf[i] = base;
    }
    
    
    for (int i = 0; i < n; ++i) {
        db kek = 1;
        if (i) kek *= pref[i - 1];
        if (i + 1 != n) kek *= suf[i + 1];
        kek *= 1 - p[i] * (1 - a[i]);
        if (kek > best) {
            best = kek;
            v = i;
        }
    }   
    
    p[v] *= 1 - a[v];
    
   // cout << v << ' ' << best << ' ' << base << endl;
    
    // if (best - base < 1e-9) break;
    
    res += ii * (best - base);
  }
  
  cout.precision(10);
  cout << fixed << res + n;

}