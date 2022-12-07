#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()

#define negative return puts("impossible"), 0
#define positive return puts("possible"), 0

using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> pii;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}

const int MaxN = 301234;

int n, m, K, used, vs[MaxN], cho[MaxN]; VI e[MaxN];
 
VI ans;

void dfs(int x) {
	if(vs[x]) return; ++used; vs[x] = 1;
	VI u, v; int i = 0;
	for (auto y : ans) {
		while(i < SZ(e[x]) && e[x][i] < y) ++i;
		if(i < SZ(e[x]) && e[x][i] == y)
			u.pb(y);
		else
			v.pb(y);
	}
	ans = u; for (auto y : v) dfs(y);
}

int main() {
	scanf("%d%d%d", &n, &m, &K); int fb = 0;
	for (int i = 1; i <= m; i++) {
		int u, v; scanf("%d%d", &u, &v); if(u > v) swap(u, v);
		if(u == 1) fb += (cho[v] = 1);
		else {
			e[u].pb(v); e[v].pb(u);
		}
 	}
 	if(fb + K >= n) negative;
 	
 	for (int i = 1; i <= n; i++) 
 		sort(ALL(e[i]));
	
	for (int i = 2; i <= n; i++)
		ans.pb(i);
	int cnt = 0;
	for (int i = 2; i <= n; i++)
		if (!cho[i] && !vs[i]) {
			++cnt; dfs(i);
		}
		
	if(cnt > K) negative; 
	if(used == n - 1) 
		positive;
	negative;
	return 0;
}