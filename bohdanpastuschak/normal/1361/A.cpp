#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
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

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void no(){
	cout << -1 << endl;
	exit(0);
}

const int N = 1 << 19;
int n, m;
VI g[N];
int t[N];
vector<int> by_t[N];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	while(m--){
		int x, y;
		cin >> x >> y;
		--x; --y;
		g[x].PB(y);
		g[y].PB(x);
	}
	
	FOR(i, 0, n) {
		cin >> t[i];
		by_t[t[i]].PB(i);
	}
	
	vector<int> p;
	p.reserve(n);
	
	FOR(i, 1, n + 1){
		for(auto j: by_t[i]){
			p.PB(j);
			vector<int> lol(SZ(g[j]));
			FOR(x, 0, SZ(g[j])){
				lol[x] = t[g[j][x]];
			}
			
			sort(ALL(lol));
			lol.resize(unique(ALL(lol)) - lol.begin());
			
			if (SZ(lol) < i - 1) no();
			FOR(x, 1, i) if (lol[x - 1] != x){
				no();
			}
			
			if (SZ(lol) >= i && lol[i - 1] == i) no();
		}
	}
	
	FOR(i, 0, n) cout << p[i] + 1 << ' ';
	cout << endl;
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}