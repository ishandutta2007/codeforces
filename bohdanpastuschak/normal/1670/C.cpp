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
 	
 	const int mod = 1e9 + 7;
 	int t; cin >> t;
 	while(t--){
		int n; cin >> n;
		vector<int> a(n), b(n), c(n);
		FOR(i, 0, n) cin >> a[i], --a[i];
		FOR(i, 0, n) cin >> b[i], --b[i];
		FOR(i, 0, n) cin >> c[i], --c[i];
		
		vector<int> mp(n);
		FOR(i, 0, n) mp[a[i]] = i;
		FOR(i, 0, n) b[i] = mp[b[i]];
		FOR(i, 0, n) if (c[i] != -1) c[i] = mp[c[i]];
		
		int ans = 1;
		
		vector<int> used(n, 0);
		FOR(i, 0, n) if (!used[i]){
			int fixed = 0;
			
			int now = i;
			while(!used[now]){
				used[now] = 1;
				if (c[now] != -1 || b[now] == now) fixed = 1;
				now = b[now];
			}
			
			if (!fixed){
				ans += ans;
				if (ans >= mod) ans -= mod;
			}			
		}
		
		cout << ans << endl;		
	}
 	
 	
	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;
}