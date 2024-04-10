//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
//#define ull unsigned long long
#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) qpow((x),mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define vec vector

const int MAXN = 3e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
const int mod = 998244353;
const int GG = 3;
//const int base = 131;

int n, m, Gi, maxc;
int lim, l, r[MAXN];
int G[MAXN], F[MAXN], S[MAXN], InvS[MAXN];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

int qpow(int x, int b) {
	int res = 1;
	for(; b; b >>= 1, (x *= x) %= mod) if(b & 1) (res *= x) %= mod;
	return res;
}

void Init(int n) {
	lim = 1, l = 0;
	for(; lim <= n; lim <<= 1, ++l);
	for(int i = 0; i < lim; ++i)
		r[i] = ((r[i >> 1] >> 1) | ((i & 1) << (l - 1)));
}

void NTT(int *A, int opt) {
	for(int i = 0; i < lim; ++i)
		if(r[i] > i) swap(A[i], A[r[i]]);
	for(int mid = 1, w, now, x, y; mid < lim; mid <<= 1) {
		w = qpow(opt == 1 ? GG : Gi, (mod - 1) / (mid << 1));
		for(int i = 0; i < lim; i += (mid << 1)) {
			now = 1;
			for(int j = 0; j < mid; ++j, (now *= w) %= mod) {
				x = A[i + j], y = A[i + j + mid] * now % mod;
				A[i + j] = (x + y) % mod;
				A[i + j + mid] = ((x - y) % mod + mod) % mod;
			}
		}
	}
	if(opt == -1) {
		int ilim = inv(lim);
		for(int i = 0; i < lim; ++i) A[i] = A[i] * ilim % mod;
	}
}

void Inv(int *F, int *G, int len) {
	static int Tmp[MAXN];
	if(len == 1) return (void) (G[0] = inv(F[0]));
	Inv(F, G, (len + 1) >> 1);
	Init(len << 1);
	for(int i = 0; i < len; ++i) Tmp[i] = F[i];
	for(int i = len; i < lim; ++i) Tmp[i] = 0;
	NTT(Tmp, 1); NTT(G, 1);
	for(int i = 0; i < lim; ++i) G[i] = ((2 - Tmp[i] * G[i] % mod) % mod * G[i] % mod + mod) % mod;
	NTT(G, -1);
	for(int i = len; i < lim; ++i) G[i] = 0;
	for(int i = 0; i < lim; ++i) Tmp[i] = 0;
}

void Sqrt(int *F, int *G, int len) {
	static int Tmp[MAXN], InvG[MAXN];
	if(len == 1) {
		assert(F[0] == 1);
		G[0] = 1;
		return;
	}
	Sqrt(F, G, (len + 1) >> 1);
	Inv(G, InvG, len);
	Init(len << 1);
	for(int i = 0; i < len; ++i) Tmp[i] = F[i];
	for(int i = len; i < lim; ++i) Tmp[i] = InvG[i] = 0;
	NTT(Tmp, 1); NTT(G, 1); NTT(InvG, 1);
	for(int i = 0; i < lim; ++i) G[i] = ((G[i] * G[i] % mod + Tmp[i] % mod) * InvG[i] % mod * inv(2) % mod) % mod;
	NTT(G, -1);
	for(int i = len; i < lim; ++i) G[i] = 0;
	for(int i = 0; i < lim; ++i) Tmp[i] = InvG[i] = 0; 
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n); read(m);
	Gi = inv(GG);
	G[0] = 1;
	for(int i = 1, c; i <= n; ++i) {
		read(c);
		maxc = max(maxc, c + 1);
		G[c] = -4;
	}
	Sqrt(G, S, max(maxc, m + 1));
	S[0]++;
	Inv(S, InvS, max(maxc, m + 1));
	for(int i = 0; i < max(maxc, m + 1); ++i) F[i] = 2 * InvS[i] % mod;
	for(int i = 1; i <= m; ++i)
		printf("%lld\n",F[i]);
	return 0;
}