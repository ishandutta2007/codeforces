#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long double db;

#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}

template<typename T> void print(const T& a, ostream& out){	
	for(auto i: a) out << i << ' ';
	out << endl;
}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace IntModulo
{
	const int mod = 1e9 + 7;

	inline int add(int x, int y, int m = mod)
	{
		if (x + y < m)
			return x + y;
		return x + y - m;
	}

	inline int sub(int x, int y, int m = mod)
	{
		if (x >= y)
			return x - y;
		return x - y + m;
	}

	inline int mult(int x, int y, int m = mod)
	{
		return x * (LL) y % m;
	}

	inline int power(int x, LL y, int m = mod)
	{
		int r = 1;
		while(y)
		{
			if (y & 1)
				r = mult(r, x, m);
			x = mult(x, x, m);
			y >>= 1;
		}
		
		return r;
	}
	
	inline int inverse(int x, int m = mod)
	{
		return power(x, m - 2, m);
	}

	inline void ADD(int& x, int y, int m = mod){
		x += y;
		if (x >= m) x -= m;
	}

	inline void SUB(int& x, int y, int m = mod){
		x -= y;
		if (x < 0) x += m;
	}

	inline void MULT(int& x, int y, int m = mod){
		x = (x * (LL) y) % m;
	}
};

using namespace IntModulo;

const int N = 1 << 19;
int n, m, sz, ans[N], p[N], cnt[N];

inline int find(int x){
	return p[x] = (p[x] == x ? x : find(p[x]));
}

inline bool unite(int u, int v){
	u = find(u); v = find(v);
	if (u == v){
		return false;
	}

	if (rng() & 1) swap(u, v);
	p[u] = v;
	cnt[v] += cnt[u];
	return true;
}

int main()
{
    scanf("%d %d", &n, &m);
    FOR(i, 0, m) p[i] = -1;
    
    FOR(it, 0, n){
		int k; scanf("%d", &k);
		vector<int> a(k);
		FOR(j, 0, k){
			scanf("%d", &a[j]);
			--a[j];
		}
		
		if (k == 1){
			int v = a[0];
			if (p[v] == -1){
				p[v] = v;
				cnt[v] = 1;
				ans[sz++] = it;				
			}else{
				int batya = find(v);
				if (cnt[batya] == 0){
					ans[sz++] = it;
				}
				cnt[batya]++;
			}
		}else{
			int u = a[0], v = a[1];
			if (p[u] == -1 || p[v] == -1){
				ans[sz++] = it;
				if (p[u] == -1){
					p[u] = u;
				}
				if (p[v] == -1){
					p[v] = v;
				}

				unite(u, v);
			}else{
				if (find(u) != find(v)){
					if (cnt[find(u)] < 1 || cnt[find(v)] < 1){
						ans[sz++] = it;
						unite(u, v);
					}
				}
			}
		}
	}

	cout << power(2, sz) << ' ' << sz << endl;
	FOR(i, 0, sz){
		cout << ans[i] + 1 << ' ';
	}
	cout << endl;		
	
	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;
}