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
	int n, m; cin >> n >> m;
	vector<set<int>> s(n);
	int ans = 0;
	while(m--){
		int u, v; cin >> u >> v;
		--u; --v;
		s[u].insert(v);
		s[v].insert(u);
	}
	
	FOR(i, 0, n){
		if (SZ(s[i]) == 0 || *s[i].rbegin() < i) ans++;
	}
	
	cin >> m;
	while(m--){
		int t, u, v; cin >> t;
		if (t == 1){
			cin >> u >> v; 
			--u; --v;
			for(int i: {u, v}){
				ans -= SZ(s[i]) == 0 || *s[i].rbegin() < i;
			}
			s[u].insert(v);
			s[v].insert(u);
			
			for(int i: {u, v}){
				ans += SZ(s[i]) == 0 || *s[i].rbegin() < i;
			}
		}else if (t == 2){			
			cin >> u >> v; 
			--u; --v;
			for(int i: {u, v}){
				ans -= SZ(s[i]) == 0 || *s[i].rbegin() < i;
			}
			s[u].erase(v);
			s[v].erase(u);
			
			for(int i: {u, v}){
				ans += SZ(s[i]) == 0 || *s[i].rbegin() < i;
			}
		}else if (t == 3){
			cout << ans << '\n';
		}
	}
	
	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;
}