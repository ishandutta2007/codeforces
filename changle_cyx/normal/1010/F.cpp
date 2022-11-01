#include <bits/stdc++.h>

using namespace std; 

typedef vector<int> vi; 
typedef long long s64; 

template <class T>
inline void read(T &x) {
	static char ch; 
	while (!isdigit(ch = getchar())); 
	x = ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

namespace modulo {
	const int mod = 998244353; 
	const int modroot = 3; 
	
	inline void madd(int &x, const int &y) {
		x = x + y >= mod ? x + y - mod : x + y;
	}
	
	inline void mdec(int &x, const int &y) {
		x = x - y < 0 ? x - y + mod : x - y;
	}
		
	inline int qpow(int x, int y) {
		int res = 1; 
		for (; y; y >>= 1, x = 1LL * x * x % mod)
			if (y & 1) res = 1LL * res * x % mod; 
		return res; 
	}
}
using namespace modulo; 

namespace polynomial {
	const int MaxL = 4e5 + 5; //max(deg) << 1
	const int MaxLog = 19; 
	
	int rev[MaxL], P, L, invL; 
	vi w[MaxLog]; 
	
	void degInit(int deg) {
		for (P = 0, L = 1; L < deg; ++P, L <<= 1); 
		for (int i = 1; i < L; ++i) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (P - 1)); 
		invL = qpow(L, mod - 2); 
	}
	
	void wInit() {
		const int M = MaxLog - 1; 
		for (int i = 1; i <= M; ++i) w[i].resize(1 << (i - 1)); 
		
		int omega = qpow(modroot, (mod - 1) / (1 << M)); 
		
		w[M][0] = 1; 
		for (int i = 1; i < (1 << (M - 1)); ++i) w[M][i] = 1LL * w[M][i - 1] * omega % mod; 
		for (int j = M - 1; j >= 1; --j)
			for (int i = 0; i < (1 << (j - 1)); ++i) w[j][i] = w[j + 1][i << 1]; //NOTICE: out of bound
	}
	struct czkakioi{czkakioi(){wInit();}}czkaknoi2020; 
	
	void DFT(vi &a, int opt) {
		for (int i = 1; i < L; ++i) if (i < rev[i]) swap(a[i], a[rev[i]]); 
		for (int k = 1, kp = 1; k < L; k <<= 1, ++kp)
			for (int i = 0; i < L; i += k << 1)
				for (int j = 0; j < k; ++j) {
					int u = a[i + j], v = 1LL * a[i + j + k] * w[kp][j] % mod; 
					madd(a[i + j] = u, v), mdec(a[i + j + k] = u, v); 
				}
		if (opt == -1) {
			reverse(a.begin() + 1, a.end()); 
			for (int i = 0; i < L; ++i) a[i] = 1LL * a[i] * invL % mod; 
		}
	}
	
	vi lsh(vi a) {
		a.push_back(a.back()); 
		for (int i = a.size() - 1; i >= 1; --i) a[i] = a[i - 1]; 
		return a[0] = 0, a; 
	}
	
	vi operator + (vi a, const vi &b) {
		if (a.size() < b.size()) a.resize(b.size()); 
		for (int i = 0; i < (int)b.size(); ++i) madd(a[i], b[i]); 
		return a; 
	}
	
	vi operator ^ (vi a, const vi &b) { //a.size() = b.size() = L, point multiply
		for (int i = 0; i < L; ++i) a[i] = 1LL * a[i] * b[i] % mod; 
		return a; 
	}
	
	vi operator * (vi a, vi b) {
		int deg = a.size() + b.size() - 1; 
		degInit(deg), a.resize(L), b.resize(L); 
		
		DFT(a, 1), DFT(b, 1), a = a ^ b, DFT(a, -1); 
		return a.resize(deg), a; 
	}
}
using polynomial::operator *; 
using polynomial::operator +; 

const int MaxN = 1e5 + 5; 
vector<int> adj[MaxN]; 

namespace heavyLightDecomposition {
	int fa[MaxN], sze[MaxN], hev[MaxN]; 
	vi f[MaxN]; 

	void dfsInit(int u = 1) {
		sze[u] = 1; 
		for (int v : adj[u]) if (v != fa[u]) {
			fa[v] = u, dfsInit(v); 
			if (sze[u] += sze[v], sze[v] > sze[hev[u]]) hev[u] = v; 
		}
	}

	int segn; 
	vi g[MaxN << 2][2]; 
	#define lcc x << 1, l, mid
	#define rcc x << 1 | 1, mid + 1, r
	void pathSolve(vi &ver, int x = 1, int l = 0, int r = segn - 1) {
		if (l > r) return; 
		if (l == r) return (void)(g[x][0] = g[x][1] = f[ver[l]]); 

		int mid = (l + r) >> 1; 
		pathSolve(ver, lcc), pathSolve(ver, rcc); 
		
		g[x][0] = g[x << 1][0] * g[x << 1 | 1][0]; 
		g[x][1] = g[x << 1][1] + g[x << 1][0] * g[x << 1 | 1][1]; 
	}
	
	void solve(int u = 1) {
		f[u] = {0, 1}; 
		for (int v : adj[u]) if (v != fa[u] && v != hev[u]) {
			solve(v); 
			f[u] = polynomial::lsh(f[v]); // On binary tree, u ONLY has ONE light son
		}
		if (hev[u]) solve(hev[u]); 

		if (!fa[u] || u != hev[fa[u]]) {
			vi ver; 
			for (int x = u; x; x = hev[x]) ver.push_back(x); 
			segn = ver.size(), pathSolve(ver), f[u] = g[1][1] + (vi){1}; 
		}
		
	//	cerr << "solve : " << u << ' ' << hev[u] << " : "; //
	//	for (int x : f[u]) cerr << x << ' '; //
	//	cerr << '\n'; // 
	}
}

s64 X; 
int n, ind[MaxN]; 

int main() {
#ifdef orzczk
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout); 
#endif

	using namespace heavyLightDecomposition; 
//orzczk
	read(n), read(X), X %= mod; // x is too big
	for (int i = 1; i < n; ++i) {
		int u, v; 
		read(u), read(v); 
		adj[u].push_back(v); 
		adj[v].push_back(u); 
	}
	
	dfsInit(); 
	solve(); 
	
	ind[1] = 1; 
	for (int i = 2; i <= n; ++i) ind[i] = 1LL * ind[mod % i] * (mod - mod / i) % mod; 
	
	int prod = 1, ans = 0; 
	for (int i = 1; i <= n; ++i) {
	//	cerr << i << ':' << f[1][i] << ' ' << prod << '\n'; //
		
		ans = (ans + 1LL * prod * f[1][i]) % mod; 
		prod = 1LL * prod * (X + i) % mod * ind[i] % mod; 
	}
	
	cout << ans << '\n'; 
	return 0; 
}