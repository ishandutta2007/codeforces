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

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		vector<int> to(n << 1, -1);
		
		vector<PII> h;
		FOR(i, 0, k){
			int x, y; cin >> x >> y;
			--x; --y;
			if (x > y) swap(x, y);
			h.PB({x, y});
			to[x] = y;
			to[y] = x;
		}
				
		vector<int> f;
		FOR(i, 0, n << 1) if (to[i] == -1) f.PB(i);
	
		FOR(i, 0, SZ(f) / 2){
			int x = f[i];
			int y = f[i + SZ(f) / 2];
			if (x > y) swap(x, y);
			h.PB({x, y});
			to[x] = y;
			to[y] = x;
		}
		
		//for(auto i: h) cout << i.X << ' ' << i.Y << endl;
		
		int ans = 0;
		FOR(I, 0, SZ(h)) FOR(J, 0, I){
			PII a = h[I];
			PII b = h[J];
			
			bool Ha = b.X <= a.X && a.X <= b.Y;
			bool Hb = b.X <= a.Y && a.Y <= b.Y;
			if (Ha && !Hb) ans++;
			if (Hb && !Ha) ans++;
		}
		
		cout << ans << endl;
	}
		
	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;
}