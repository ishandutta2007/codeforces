#include <bits/stdc++.h>

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()
#define debug(x) cerr << #x" = " << x << endl

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long u64;
typedef vector<int> VI;

template <typename T, typename TT> ostream & operator << (ostream &out, pair<T, TT> t) { return out << "(" << t.X << "," << t.Y << ")";}
template <typename T> ostream & operator << (ostream &out,vector<T> t) { out << "["; for (auto x:t) out << x << " "; out << "]"; return out;}
template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
template <typename T> void read(T & x) {
	int f = 1; char ch; x = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar(); x *= f;
}

const int mod = 998244353;
const int NX = 1001234;
 
int n, fac[NX], rfac[NX]; 

int exp(int a, LL n) {
	int res = 1;
	for (; n; n >>= 1) {
		if(n & 1)
			res = (LL) res * a % mod;
		a = (LL) a * a % mod;
	}
	return res;
}

void preprocess() {
  int n = NX - 1;
  for (int i = fac[0] = 1; i <= n; i++)
    fac[i] = (LL) fac[i - 1] * i % mod;
  rfac[n] = exp(fac[n], mod - 2);
  for (int i = n; i; i--)
    rfac[i - 1] = (LL) rfac[i] * i % mod;
}

int C(int n, int m) {
  if(m < 0 || n < m)
    return 0;
  return (LL) fac[n] * rfac[m] % mod * rfac[n - m] % mod;
}

int g(LL n) {
  return exp(3, n);
}

int cal(int k) {
  if (!k) {
    return exp((g(n) + mod - 3) % mod, n);
  }
  
  int p = (LL) (g(k) - 3) * g((LL) n * (n - k)) % mod;
  int q = (g(n - k) - 1) % mod;
  p = (p % mod + mod) % mod;
  q = (q % mod + mod) % mod;
  q = exp(q, n);
  q = q * 3LL % mod;
  return (p + q) % mod;
}

int main() {
  read(n);
  preprocess();
  int ans = g((LL) n * n), mi = 0;
  for (int k = 0; k <= n; k++) {
    int cur = cal(k);
    cur = (LL) cur * C(n, k) % mod;
    if (k & 1)
      mi = (mi + cur) % mod;
    else
      mi = (mi + mod - cur) % mod;
  }
  ans = (ans + mi) % mod;
  cout << ans << "\n";
	return 0;
}