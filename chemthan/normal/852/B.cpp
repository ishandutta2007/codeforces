#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf 1000000005
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define MOD 1000000007
#define sz(a) ((ll)(a).size())

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)

typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
#define eps 1e-12
typedef pair<int, int> II;
typedef pair<ll, ll> LL;
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
#define PI (2 * acos((ld)0))
#define linf (1ll << 60)
#define y1 y32432
#define y0 y435346

#define maxn 400005

int mod;

struct Matrix {
  vector< vector<long long> > x;
  int m, n;

  Matrix(int m = 0, int n = 0) : m(m), n(n) {
    x.resize(m);
    Rep(i,m) {
        x[i].resize(n);
        Rep(j,n) x[i][j] = 0;
    }
  }
  void print() {
    Rep(i,m) {
        Rep(j,n) cout << x[i][j] << ' ';
        cout << endl;
    }
  }
};
Matrix operator * (const Matrix &a, const Matrix &b) {
  Matrix c(a.m, b.n);
  Rep(i,c.m) Rep(j,c.n) {
      Rep(k,a.n)
          c.x[i][j] = (c.x[i][j] + a.x[i][k] * b.x[k][j]) % MOD;
  }
  return c;
}

Matrix identity(int n) {
  Matrix res(n, n);
  Rep(i,n) res.x[i][i] = 1;
  return res;
}

Matrix operator ^(const Matrix &A, int k){
  Matrix res = identity(mod), mul = A;
  while(k){
    if(k & 1) res = res * mul;
    mul = mul * mul;
    k >>= 1;
  }
  return res;  
}

int a[105], b[105], c[105], aa[1000006];
int main()
{
  /* freopen("in.txt", "r", stdin); */
  /* freopen("out.txt", "w", stdout); */
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m >> mod;
  Matrix A(1, mod), B(mod, mod), C(mod, mod);

  Rep(i, n){
    int u;
    cin >> u;
    u %= mod;
    a[u]++;
  }
  Rep(i, n){
    int u;
    cin >> u;
    u %= mod;
    aa[i] = u;
    b[u]++;
  }
  Rep(i, n){
    int u;
    cin >> u;
    u = (u + aa[i]) % mod;
    c[u]++;
  }

  Rep(i, mod){
    A.x[0][i] = a[i];
    Rep(j, mod){
      int jj = j + i;
      if(jj >= mod) jj -= mod;
      B.x[j][jj] = b[i];
      C.x[j][jj] = c[i];
    }
  }

  B = B^(m - 2);
  B = B * C;
  A = A * B;
  cout << A.x[0][0] << endl;

  return 0;
}