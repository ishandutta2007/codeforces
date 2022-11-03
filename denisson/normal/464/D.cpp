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

  const int KEK = 800;
int n, k;
db f[2][KEK];

//db dp[111][111];
//db coef[111][111];

int main(){
#ifdef LOCAL
  freopen("D_input.txt", "r", stdin);
  //freopen("D_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  db ans = 0;
  
  cin >> n >> k;
  
  int uk = 0;
  
  for (int cnt = 0; cnt < n; ++cnt) {
      for (int lvl = 1; lvl < KEK; ++lvl) {
  
          f[uk ^ 1][lvl] += (lvl / 2.0 + f[uk][lvl] * lvl / (db)(lvl + 1)) / k;
          if (lvl + 1 < KEK)
          f[uk ^ 1][lvl] += (lvl + f[uk][lvl + 1]) / (db)(lvl + 1) / (db)k;
          f[uk ^ 1][lvl] += f[uk][lvl] * (k - 1) / (db)k;
  
          /*
          for (int nxt = 1; nxt <= lvl + 1; ++nxt) {
              if (nxt == lvl + 1) {
                  f[cnt][lvl] += f[cnt - 1][lvl + 1] + lvl;
              } else {
                  f[cnt][lvl] += nxt + f[cnt - 1][lvl];
              }
          }
          f[cnt][lvl] /= lvl + 1;
          
          */
  
      }
      fill(f[uk], f[uk] + KEK, 0);
      uk ^= 1;
      
 // pper(f[uk][1]);
 /// pper(f[uk][2]);
 //pper(f[uk][3]);
//  pper(f[uk][4]);
 // pper(f[uk][5]);
  }
  
  ans = f[uk][1];
//  for (int lvl = 1; lvl < KEK; ++lvl) ans += f[uk][lvl];
  
  
  
  
  cout.precision(10);
  cout << fixed << ans * k;

}