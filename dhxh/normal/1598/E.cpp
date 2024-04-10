#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000 + 5;

int n, m, q, t;

long long f[maxn][maxn][2];
long long ans = 0;
bool vis[maxn][maxn];

long long up(int x, int y, int d){
	if(x < 1 or y < 1) return 0;
	if(vis[x][y]) return 0;
	if(d == 0){
		return up(x - 1, y, 1) + 1;
	}else{
		return up(x, y - 1, 0) + 1;
	}
}

long long down(int x, int y, int d){
	if(x > n or y > m) return 0;
	if(vis[x][y]) return 0;
	if(d == 0){
		return down(x + 1, y, 1) + 1;
	}else{
		return down(x, y + 1, 0) + 1;
	}
}

int main() {
	int i, j;

	scanf("%d%d%d", &n, &m, &q);

	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			f[i][j][0] = 1;
			f[i][j][1] = 1;
			f[i][j][1] += f[i][j - 1][0];
			f[i][j][0] += f[i - 1][j][1];
			ans += f[i][j][0] + f[i][j][1] - 1;
		}
	}

	while(q--){
		int x, y;
		scanf("%d%d", &x, &y);
		if(vis[x][y]){
			vis[x][y] = false;
			ans += up(x, y, 0) * down(x, y, 1) + up(x, y, 1) * down(x, y, 0) - 1;
		}else{
			long long a =  +  - 1;
			long long b =  +  - 1;
			ans -= up(x, y, 0) * down(x, y, 1) + up(x, y, 1) * down(x, y, 0) - 1;
			vis[x][y] = true;
		}
		printf("%lld\n", ans);
	}

	return 0;
}