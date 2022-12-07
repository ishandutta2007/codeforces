#include <bits/stdc++.h>
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()
 
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long u64;
 
template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
 
int read() {
	int x = 0, f = 1;char ch;
	for (ch = getchar(); !isdigit(ch); ch = getchar())
		if (ch == '-') f = -1;
	for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}
 
using namespace std;
 
const int maxn = 4000010;
const int MaxN = (1 << 21) + 10;
int N = 1 << 21;
 
typedef unsigned int uint32;
typedef long long int64;
typedef unsigned long long uint64;
typedef uint32 word;
typedef uint64 dword;
typedef int sword;
 
word mod, Modinv, r2; 
const int word_bits = sizeof(word) * 8;
struct mint{
  word x;
  mint(): x(0) {}
  mint(word _x): x(init(_x)) {}
 
  mint& operator += (const mint& rhs) {
    if ((x += rhs.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator -= (const mint& rhs) {
    if (sword(x -= rhs.x) < 0) x += mod;
    return *this;
  }
  mint& operator *= (const mint& rhs) {
    x = reduce(dword(x) * rhs.x);
    return *this;
  }
  mint operator + (const mint &rhs) const {
    return mint(*this) += rhs;
  }
  mint operator - (const mint &rhs) const {
    return mint(*this) -= rhs;
  }
  mint operator * (const mint &rhs) const {
    return mint(*this) *= rhs;
  }
  mint pow(uint64 e) const {
    mint ret(1);
    for (mint base = *this; e; e >>= 1, base *= base) {
      if (e & 1) ret *= base;
    }
    return ret;
  }
  word get() const {
    return reduce(x);
  }
  static word modulus() {
    return mod;
  }
  static word init(word w) {
    return reduce(dword(w) * r2);
  }
  static void set_mod(word m) {
    mod = m;
    Modinv = mul_inv(mod);
    r2 = -dword(mod) % mod;
  }
  static word reduce(dword x) {
    word y = word(x >> word_bits) - word((dword(word(x) * Modinv) * mod) >> word_bits);
    return sword(y) < 0 ? y + mod : y;
  }
  static word mul_inv(word n, int e = 6, word x = 1) {
    return !e ? x : mul_inv(n, e - 1, x * (2 - x * n));
  }
};
 
int n, k;
 
mint fac[maxn],Inv[maxn],Ans[maxn];
 
mint A[maxn],B[maxn],Et[maxn];
 
namespace fft {
mint TWO;
 
mint add(mint a, mint b) {
    return a + b;
}
mint mul(mint a, mint b) {
    return a * b;
}
mint sub(mint a, mint b) {
    return a - b;
}
 
const int K = 20;
mint eps[MaxN], ieps[MaxN], g[K + 1], ng[K + 1], gw[MaxN], ngw[MaxN]; int rev[MaxN], lg[MaxN];
inline void init() {
    int i, j;
    g[K] = ((mint)3).pow((mod - 1) / N);
	ng[K] = g[K].pow(mod - 2);
    for(i = K - 1; ~i; i--)
        g[i] = g[i + 1] * g[i + 1], ng[i] = ng[i + 1] * ng[i + 1];
    for(i = 0; i <= K; i++){
        gw[1 << i] = ngw[1 << i] = mint(1);
        for(j = 1; j < 1 << i ;j++){
            gw[(1 << i) + j]=gw[(1 << i) + j - 1] * g[i];
            ngw[(1 << i) + j]=ngw[(1 << i) + j - 1] * ng[i];
        }
    }
}
  
 
inline void trans(int n, mint x[], int op) {
    int nL = 0, tn = 1;
    while(tn < n) {
        nL++; tn <<= 1;
    } 
    for(int i = 1; i < n; i++) {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << nL - 1);        
        if(i < rev[i]) swap(x[i], x[rev[i]]);
    }
    for(int e = 0; (1 << e) < n; e++) {
        int m = 1 << e, m2 = m << 1;
        mint *_w = (op > 0 ? gw : ngw); _w += (1 << e);
        for(int i = 0; i < n; i += m2) {
            mint *w = _w;
            for(int j = 0; j < m; j++, w++) {
                mint &A = x[i + j + m], &B = x[i + j], t = *w * A;
                A = B - t; B += t; 
            }
        } 
         
    }
}
  
inline void dft(int n, mint x[]) {
    trans(n, x, 1);
}
  
inline void idft(int n, mint x[]) {
    trans(n, x, -1); mint in = mint(n).pow(mod - 2);
    for (int i = 0; i < n; i++) x[i] = x[i] * in;
}
  
void conv(int n, mint x[], mint y[], mint z[]) {
    dft(n, x); dft(n, y);
    for(int i = 0; i < n; i++) z[i] = mul(x[i], y[i]);
    idft(n, z);
}
 
}
 
using fft :: dft;
using fft :: idft;
void solve(int n){
	if(n==1){
		Ans[1]=1;
		return;
	}
	int t=n>>1;
	solve(t);
	int k=1;
	for(k=1;k<=n;k<<=1);
	for(int i=0;i<k;i++)A[i]=B[i]=0;
	Et[0]=1;
	for(int i=1;i<=t;i++)Et[i]=Et[i-1]*t;
	for(int i=0;i<=t;i++)A[i]=Ans[t-i]*fac[t-i],B[i]=Et[i]*Inv[i];
	dft(k, A);
	dft(k, B);
	for(int i=0;i<k;i++)A[i]=A[i]*B[i];
	idft(k, A);
	
	//mtt :: conv(k, A, k, B, k, A);
	for(int i=0;i<k;i++)B[i]=i<=t?A[t-i]*Inv[i]:0;
	for(int i=0;i<k;i++)A[i]=i<=t?Ans[i]:0;
	//NTT(A,1,k);NTT(B,1,k);
	dft(k, A);
	dft(k, B);
	for(int i=0;i<k;i++)A[i]=A[i]*B[i];
	idft(k, A);
	//mtt :: conv(k, A, k, B, k, A);
	
	for(int i=0;i<=n;i++)Ans[i]=0;
	if(n&1){
		B[1]=1;B[0]=n-1;
		for(int i=0;i<=n-1;i++)
			for(int j=0;j<=1;j++)Ans[i+j]=(A[i]*B[j]+Ans[i+j]);
	}
	else for(int i=0;i<=n;i++)Ans[i]=A[i];
}
 
mint c(int n, int m) {
	return fac[n] * Inv[m] * Inv[n - m];
}
 
void Work(){
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	if(n==1){
		puts((a==b&&b==1)?"1":"0");
		return;
	} 
	solve(n-1);
	mint ans = c(a+b-2, a-1)*Ans[a+b-2];
	printf("%u\n", ans.get());
}
 
int exp(int a, int n) {
	int res = 1;
	for (; n; n >>= 1) {
		if(n & 1) 
			res = (LL) res * a % mod;
		a = (LL) a * a % mod;
	}
	return res;
}
 
void Init(){
	n=maxn-1;
	mint::set_mod(998244353);
	fft :: init();
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i;
	Inv[n]=fac[n].pow(mod-2);
	for(int i=n-1;i>=0;i--)Inv[i]=Inv[i+1]*(i+1);
}
 
int main(){
	Init(); Work();
	return 0;
}