#include <bits/stdc++.h>

using namespace std; 

#define range(x) x.begin(), x.end()
typedef long long s64; 

template <class T>
inline void read(T &x) {
	static char ch; 
	while (!isdigit(ch = getchar())); 
	x = ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

template <class T>
inline bool tense(T &x, const T &y) {
	return x > y ? x = y, true : false; 
}

template <class T>
inline bool relax(T &x, const T &y) {
	return x < y ? x = y, true : false; 
}	

const int MaxN = 1.5e5 + 5; 

int n, a[MaxN]; 
vector<int> adj[MaxN]; 

s64 ans; 

namespace convexHull {
	struct point {
		s64 x, y; 
		inline point operator - (const point &rhs) const {
			return {x - rhs.x, y - rhs.y}; 
		}
		inline s64 operator * (const point &rhs) const {
			return x * rhs.y - y * rhs.x; 
		}
		inline bool operator < (const point &rhs) const {
			return x < rhs.x || (x == rhs.x && y < rhs.y); 
		}
	}; 
	
	struct request {
		s64 k, b; 
		inline bool operator < (const request &rhs) const {
			return k < rhs.k; 
		}
	}; 
	
	void updateAns(vector<request> R, vector<point> P) {
		// cerr << " :::: " << R.size() << ' ' << P.size() << '\n'; //
		
		static point que[MaxN]; 
		int ql = 1, qr = 0; 
		
		for (int i = 0; i < (int)P.size(); ++i) {
			while (ql < qr && (P[i] - que[qr]) * (que[qr - 1] - que[qr]) >= 0) --qr; 
			que[++qr] = P[i]; 
		}
		
		for (int i = 0; i < (int)R.size(); ++i) {
			while (ql < qr && (point){1, R[i].k} * (que[ql + 1] - que[ql]) >= 0) ++ql; 
			if (ql <= qr) relax(ans, que[ql].y - R[i].k * que[ql].x - R[i].b); 
		}
	}
}

namespace treeDivision {
	bool vis[MaxN]; 
	
	int findG(int src) {
		static int que[MaxN], qr; 
		static int pre[MaxN], sze[MaxN]; 
		
		pre[que[qr = 1] = src] = 0; 
		for (int i = 1, u; i <= qr; ++i) {
			u = que[i]; 
			for (int v : adj[u]) if (!vis[v] && v != pre[u])
				pre[que[++qr] = v] = u; 
		}
		
		int mins = MaxN, res = 0; 
		for (int i = qr, u, maxs; i >= 1; --i) {
			sze[u = que[i]] = 1, maxs = 0; 
			for (int v : adj[u]) if (!vis[v] && v != pre[u])
				sze[u] += sze[v], relax(maxs, sze[v]); 
			if (tense(mins, max(maxs, qr - sze[u]))) res = u; 
		}
		
	//	cerr << mins << '\n'; 
		return res; 
	}
	
	int G, pre[MaxN], dep[MaxN]; 
	s64 s[MaxN], f[MaxN], g[MaxN]; 
	
	using namespace convexHull; 
	void dfsGet(int u, vector<point> &sp, vector<request> &sr) {
		relax(ans, g[u] + 1LL * a[G] * (dep[u] + 1)); 
		relax(ans, f[u] + s[u]); 

		bool flg = true; 
		for (int v : adj[u]) if (!vis[v] && v != pre[u]) {
			pre[v] = u, dep[v] = dep[u] + 1; 
			s[v] = s[u] + a[v]; 
			f[v] = f[u] + 1LL * a[v] * dep[v]; 
			g[v] = g[u] + (s[u] - a[G]) + a[v]; 
			
			dfsGet(v, sp, sr); 
			
			flg = false; 
		}
		
		// cerr << u << ' ' << flg << '\n'; 
		if (flg) {
			// cerr << u << ':' << dep[u] + 1 << ' ' << g[u] << ':' << s[u] << ' ' << f[u] << '\n';//
			
			sp.push_back({(s64)dep[u] + 1, g[u]}); 
			sr.push_back({-s[u], -f[u]}); 
		}
	}
	
	namespace segmentSolve {
		#define lcc x << 1, l, mid
		#define rcc x << 1 | 1, mid + 1, r
	
		const int MaxS = MaxN << 2; 
		vector<point> spoint[MaxS]; 
		vector<request> sreq[MaxS]; 
	
		void solve(vector<int> &ver, int x, int l, int r) {
			if (l > r) return; 
					
			spoint[x].clear(), sreq[x].clear(); 
		
			if (l == r) {
				dfsGet(ver[l], spoint[x], sreq[x]); 
				sort(range(sreq[x])), sort(range(spoint[x])); 

				return; 
			}
		
			int mid = (l + r) >> 1, lc = x << 1, rc = x << 1 | 1; 
			solve(ver, lcc), solve(ver, rcc); 
		
			updateAns(sreq[lc], spoint[rc]); 
			updateAns(sreq[rc], spoint[lc]); 
		
			sreq[x].resize(sreq[lc].size() + sreq[rc].size()); 
			spoint[x].resize(spoint[lc].size() + spoint[rc].size()); 
		
			merge(range(sreq[lc]), range(sreq[rc]), sreq[x].begin()); 
			merge(range(spoint[lc]), range(spoint[rc]), spoint[x].begin()); 
		}
	}
	
	void solve(int u) {
		G = u = findG(u); 
		
		pre[u] = 0, s[u] = a[u], f[u] = 0; 
		
		vector<int> ver; 
		for (int v : adj[u]) if (!vis[v]) {
			ver.push_back(v); 
			dep[v] = 1, pre[v] = u; 
			s[v] = s[u] + a[v]; 
			f[v] = g[v] = a[v]; 
		}
		
		segmentSolve::solve(ver, 1, 0, ver.size() - 1); 
		
		vis[u] = true; 
		for (int v : adj[u]) if (!vis[v]) solve(v); 
	}
}

int main() {
#ifdef orzczk
	freopen("tree.in", "r", stdin); 
	freopen("tree.out", "w", stdout); 
#endif
//orzczk
	read(n); 
	for (int i = 1; i < n; ++i) {
		int u, v; 
		read(u), read(v); 
		adj[u].push_back(v); 
		adj[v].push_back(u); 
	}
	for (int i = 1; i <= n; ++i) read(a[i]), relax(ans, (s64)a[i]); 
	
	treeDivision::solve(1); 
	cout << ans << '\n'; 
	
	return 0; 
}