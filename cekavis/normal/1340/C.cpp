#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 10005, M = 1005;
int n, m, t, G, R, ans, d[N], q[N], w[M*M*2], r[M*M*2], f[N][M];
int main() {
	scanf("%d%d", &n, &m);
	for(int i=1; i<=m; ++i) scanf("%d", d+i);
	scanf("%d%d", &G, &R);
	sort(d+1, d+m+1);
	ans=1e9, memset(f, 0x3f, sizeof f);
	f[q[t=1]=1][0]=0;
	for(int i=1; i<=t; ++i){
		int x=f[q[i]][0], cnt=1;
		w[cnt]=q[i], r[cnt]=0;
		for(int j=1; j<=cnt; ++j){
			int u=w[j];
			// printf(">> %d %d %d\n", x, w[j], r[j]);
			if(u>1){
				int v=r[j]+d[u]-d[u-1];
				if(v<G && x<f[u-1][v]) f[u-1][v]=x, w[++cnt]=u-1, r[cnt]=v;
				if(v==G && x+1<f[u-1][0]) f[u-1][0]=x+1, q[++t]=u-1;
			}
			if(u<m){
				int v=r[j]+d[u+1]-d[u];
				if(v<=G && u+1==m) ans=min(ans, x*(R+G)+v);
				if(v<G && x<f[u+1][v]) f[u+1][v]=x, w[++cnt]=u+1, r[cnt]=v;
				if(v==G && x+1<f[u+1][0]) f[u+1][0]=x+1, q[++t]=u+1;
			}
		}
	}
	printf("%d\n", ans==1e9?-1:ans);
	return 0;
}