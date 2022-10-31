#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef double DB;

#define pb push_back
#define mset(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#define X first
#define Y second

#define Error(x) cout << #x << " = " << x << endl

template <typename T, typename U>
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}

const int MAXN = 2222;

vector<int> adj[MAXN];
bool vis[MAXN], chk[2], op[2][MAXN];
int ans[MAXN], n;

char f[2][MAXN][33];

bool bfs(int root) {
	queue<int> Q;
	Q.push(root);
	vis[root] = true;
	chk[0] = chk[1] = false;
	vector<int> V;
	while(!Q.empty()) {
		int e = Q.front();
		Q.pop();
		V.push_back(e);
		for(int i = 0; i < 2; i++) if(op[i][e]) chk[i] = true;
		for(int i = 0; i < adj[e].size(); i++) {
			int f = adj[e][i];
			if(vis[f]) continue;
			vis[f] = true;
			Q.push(f);
		}
	}
	if(chk[0] && chk[1]) {
		puts("NO");
		return false;
	}
	for(int i = 0; i < 2; i++) {
		if(!chk[i]) {
			for(int j = 0; j < V.size(); j++) ans[V[j]] = i;
			break;
		}
	}
	return true;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%s%s", f[0][i], f[1][i]), f[1][i][2] = f[1][i][0], f[1][i][0] = f[0][i][0], f[1][i][1] = f[0][i][1], f[0][i][3] = f[1][i][3] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++) {
			for(int k = 0; k < 2; k++) {
				
				if(strcmp(f[k][i], f[k][j]) == 0) op[k][i] = true, op[k][j] = true;
				if(strcmp(f[k][i], f[!k][j]) == 0) adj[i].push_back(j), adj[j].push_back(i);
			}
		}
	for(int i = 1; i <= n; i++)	{
		if(vis[i]) continue;
		if(!bfs(i)) {
			return 0;
		}
	}	
	puts("YES");
	for(int i = 1; i <= n; i++) printf("%s\n", f[ans[i]][i]);
	return 0;
}