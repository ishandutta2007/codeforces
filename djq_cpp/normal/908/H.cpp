#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;

int n, cnt;
int ans;
bool del[55];
char grid[55][55];
int grp[55];
int ban[23];
int col[1 << 23], rcol[1 << 23];

void dfs(int v, int id)
{
	if(grp[v] != -1) return;
	grp[v] = id;
	rep(i, n) if(grid[v][i] == 'A')
	dfs(i, id);
}

int main()
{
	
	scanf("%d", &n);
	rep(i, n) scanf("%s", grid[i]);
	rep(i, n) {
		bool ok = false;
		rep(j, n) if(grid[i][j] == 'A') ok = true;
		if(!ok) del[i] = true;
	}
	ans = n - 1;
	
	rep(i, n) grp[i] = -1;
	rep(i, n) if(!del[i] && grp[i] == -1) dfs(i, cnt ++);
	
	rep(i, n) rep(j, n)
	if(!del[i] && !del[j] && grid[i][j] == 'X') {
		if(grp[i] == grp[j]) {
			printf("-1\n");
			return 0;
		} else ban[grp[i]] |= 1 << grp[j];
	}
	
	rep(i, 1 << cnt) {
		bool ok = true;
		rep(j, cnt) if((i >> j & 1) && (ban[j] & i) != 0) ok = false;
		if(ok) col[i] = 1;
	}
	
	rep(i, cnt) rep(j, 1 << cnt)
	if(j >> i & 1) col[j] += col[j ^ 1 << i];
	
	rep(i, 1 << cnt) rcol[i] = 1;
	rep(i, cnt + 1) {
		LL tot = 0;
		rep(j, 1 << cnt) if(cnt - __builtin_popcount(j) & 1) tot -= rcol[j];
		else tot += rcol[j];
		if(tot % MOD != 0) {
			ans += i;
			break;
		}
		rep(j, 1 << cnt) rcol[j] = 1LL * rcol[j] * col[j] % MOD;
	}
	printf("%d\n", ans);
	return 0;
}