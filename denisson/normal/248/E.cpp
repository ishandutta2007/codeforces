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
int a[100007];

db dp[100001][102];


struct Tree {
   db t[100008 * 4];
   
   void up(int v, int vl, int vr, int pos, db val) {
       if (vl == vr) {
           t[v] = val;
       } else {
           int vm = (vl + vr) >> 1;
           if (pos <= vm) up(v * 2 + 1, vl, vm, pos, val);
           else up(v * 2 + 2, vm + 1, vr, pos, val);
           t[v] = t[v * 2 + 1] + t[v * 2 + 2];
       }
   }
} tr;

db kek[111];

int main(){
#ifdef LOCAL
  freopen("D_input.txt", "r", stdin);
  //freopen("D_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  readArr(a, a + n);
  
  for (int i = 0; i < n; ++i) dp[i][a[i]] = 1;
  
  for (int i = 0; i < n; ++i) if (a[i] == 0) tr.up(0, 0, n - 1, i, 1);
  
  int q;
  cin >> q;
  while (q--) {
      int w1, w2, w3;
      cin >> w1 >> w2 >> w3;
      --w1; --w2; int ww = w3;
      while (w3--) {
       
        for (int i = 0; i <= 100; ++i) {
          kek[i] = 0;
          if (i <= a[w1])
          kek[i] = dp[w1][i] * (a[w1] - i) / (db)a[w1];
          if (i + 1 <= a[w1])
          kek[i] += dp[w1][i + 1] * (i + 1) / (db)a[w1];
        }
       
        copy(kek, kek + 101, dp[w1]);    
        
        
        a[w1]--; 
      }
      a[w2] += ww;
      
     // cout << w1 << ' ' << w2 << ' ' << dp[w1][0] << ' ' << dp[w1][1] << ' ' << dp[w1][2] << endl;
      
      tr.up(0, 0, n - 1, w1, dp[w1][0]);
      cout.precision(10);
      cout << fixed << tr.t[0] << "\n";
  }
 
}