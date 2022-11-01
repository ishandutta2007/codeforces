#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int maxn=505,mod=998244353;
int l,ans[maxn],G[maxn],g[maxn],S[maxn][maxn],fac[maxn],C[maxn][maxn],n,rd[maxn][2],p[maxn][2],q[maxn];
int cnt[10];
bool vis[maxn][2];
inline void prprpr(){
	rep(i,0,500){
		C[i][0]=1;
		rep(j,1,i)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}S[0][0]=1;
	rep(i,1,500)rep(j,1,i)S[i][j]=(S[i-1][j-1]+1ll*S[i-1][j]*(i-1))%mod;
	fac[0]=1;
	rep(i,1,500)fac[i]=1ll*fac[i-1]*i%mod;
}
inline void dfs(int x,int now,int st){
	assert(!vis[x][now]);
	vis[x][now]=1;
//	fprintf(stderr,"%d %d %d\n",x,now,st);
	if(!p[x][now]){
//		fprintf(stderr,"!%d %d %d\n",x,now,st);
		cnt[(st<<1)|now]++;return;
	}
	if(vis[p[x][now]][now^1])cnt[4]++;
	else dfs(p[x][now],now^1,st);
}
inline void read(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
int main(){
//	judge();
	read(n);prprpr();
	rep(i,1,n){
		read(q[i]);p[q[i]][0]=i;
		if(q[i])rd[i][1]++;
	}
	rep(i,1,n)read(p[i][1]),rd[p[i][1]][0]++;
	rep(i,1,n)rep(j,0,1)if(!vis[i][j]&&!rd[i][j])dfs(i,j,j);
	rep(i,1,n)rep(j,0,1)if(!vis[i][j])dfs(i,j,j);
	l=cnt[0];
//	fprintf(stderr,"%d %d %d %d\n",cnt[0],cnt[1],cnt[2],cnt[3]);
//	assert(cnt[0]==cnt[3]);
//	fprintf(stderr,"%d\n",fac[100]);
//	fprintf(stderr,"%d\n",C[100][50]);
	rep(i,0,n)g[i]=1ll*fac[l]*fac[i]%mod*((l==0)?((i==0)?(1):(0)):C[i+l-1][l-1])%mod;
//	fprintf(stderr,"%d\n",g[n]);
	int l2=cnt[2],l1=cnt[1];
	rep(t,0,n){
		G[t]=0;
		rep(k,0,l2)G[t]=(G[t]+g[k]*1ll*S[l2-k][t]%mod*C[l2][k])%mod; 
	}
	rep(i,0,n)rep(t,0,i)ans[i]=(ans[i]+1ll*S[l1+l][i-t]*G[t]%mod)%mod;
	per(i,n,1)if(i>=cnt[4])ans[i]=ans[i-cnt[4]];else ans[i]=0;
	rep(i,1,n)printf("%d ",ans[n-i+1]);
	printf("\n");
	return 0;
}