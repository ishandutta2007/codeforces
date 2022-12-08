#include <bits/stdc++.h>
#define lli long long
#define MAXN 300005
using namespace std;

struct hp {
	int to,nxt,w;
} e[2*MAXN];

int n;
int a[MAXN];
lli ans;
lli dp[MAXN][2];
int tot;
int head[MAXN];

void add(int u,int v,int w) {
	tot++;
	e[tot].to=v;
	e[tot].w=w;
	e[tot].nxt=head[u];
	head[u]=tot;
}

void dfs(int u,int fa) {
	lli max1=0,max2=0;
	for(int i=head[u]; i; i=e[i].nxt) {
		int v=e[i].to;
		if(v==fa) continue;
		dfs(v,u);
		if(dp[v][0]-e[i].w>=max1) {
			max2=max1;
			max1=dp[v][0]-e[i].w;
		} else if(dp[v][0]-e[i].w>max2)
			max2=dp[v][0]-e[i].w;
	}
	dp[u][1]=max1+max2+a[u];
	dp[u][0]=max1+a[u];
	ans=max(ans,max(dp[u][0],dp[u][1]));
}
int kkkkk;
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",a+i);
	for(int i=1; i<n; i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w),add(v,u,w);
	}
	dfs(1,0);
	printf("%lld\n",ans);
}