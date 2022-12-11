#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1100,mod=2520;
int n, k[N], m[N], q, ans[N][mod], vx[N * mod], vy[N * mod], p[N][mod]; bool vis[N];
vector<int>v[N];
int ask(int x, int y) {
	if (ans[x][y])return ans[x][y];
	vx[1] = x; vy[1] = y;
	p[x][y] = 1;int i;
	for (i = 2;; i++) {
		int xx = v[vx[i - 1]][vy[i - 1]%m[vx[i-1]]],yy=((vy[i-1]+k[xx])%mod+mod)%mod;
		vx[i] = xx, vy[i] = yy;
		if (p[xx][yy]||ans[xx][yy])break;
		p[xx][yy] = i;
	}
	int xx = vx[i], yy = vy[i],ret=0;
	if (ans[xx][yy])ret = ans[xx][yy];
	else {
		for (int j = p[xx][yy]; j < i; j++)if (!vis[vx[j]])vis[vx[j]] = 1, ret++;
		for (int j = p[xx][yy]; j < i; j++)vis[vx[j]] = 0;
	}
	for (int j = 1; j < i; j++)ans[vx[j]][vy[j]] = ret,p[vx[j]][vy[j]]=0;
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", &k[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &m[i]);
		for (int j = 1,x; j <= m[i]; j++) {
			scanf("%d", &x);
			v[i].push_back(x);
		}
	}
	scanf("%d", &q);
	for (int i = 1,x,y; i <= q; i++) {
		scanf("%d%d", &x, &y);
		printf("%d\n", ask(x, ((y+k[x])%mod+mod)%mod));
	}
	return 0;
}