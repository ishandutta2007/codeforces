#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i ++)
#define rep1(i, n) for(int i = 1; i <= (n); i ++)
#define MP make_pair
typedef long long LL;
typedef pair<int, int> PII;

const int INF = 1e9 + 7;

int n;
bitset<1005> occ[1005];
int cnt[1005][1005];

int vis[1005];
void dfs(int v, int dat)
{
	if(vis[v] != -1) return;
	vis[v] = dat;
	rep1(i, n) if(cnt[v][i] == 1) dfs(i, dat);
	else if(cnt[v][i] == 2) dfs(i, !dat);
}

int main()
{
	scanf("%d", &n);
	rep(i, n) {
		int k, x;
		scanf("%d", &k);
		rep(j, k) {
			scanf("%d", &x);
			occ[x][i] = true;
		}
	}
	
	if(n == 2) {
		printf("1 2\n");
		return 0;
	}
	
	rep1(i, n) rep1(j, i - 1)
	cnt[i][j] = cnt[j][i] = (occ[i] & occ[j]).count();
	
	int maxl = 2;
	rep1(i, n) rep1(j, n) {
		if(cnt[i][j] == 1) maxl = 4;
		else if(cnt[i][j] == 2) maxl = 3;
	}
	if(maxl == 2) {
		rep1(i, n - 1) printf("%d %d\n", i, n);
		return 0;
	}
	
	int beg = 1;
	rep1(i, n) rep1(j, n) if(cnt[i][j] == 2) beg = i;
	rep1(i, n) rep1(j, n) if(cnt[i][j] == 1) beg = i;
	
	rep1(i, n) vis[i] = -1;
	dfs(beg, 0);
	int cur = 1;
	rep1(i, n) if(vis[i] == -1) dfs(i, cur ^= 1);
	
	rep1(i, n) rep1(j, i - 1)
	if(cnt[i][j] > 2 && vis[i] != vis[j]) printf("%d %d\n", j, i);
	return 0;
}