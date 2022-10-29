#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
const int N=5005;

int ADD(int &x,int y)
{
	x+=y;
	if(x>=MOD) x%=MOD;
}

int DEC(int &x,int y)
{
	x=x+MOD-y;
	if(x>=MOD) x-=MOD; 
}

int n,p[N],q[N];
int dp[N][N],C[N][N],base[N];
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<=n;i++) scanf("%d",&q[i]);
	dp[0][0]=1;//i??,j???????(first stirling)
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n;j++) dp[i][j]=(1LL*dp[i-1][j]*(i-1)+dp[i-1][j-1])%MOD;
	C[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=n;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	}
	base[0]=1;
	for(int i=1;i<=n;i++) base[i]=1LL*base[i-1]*i%MOD;
}

void run(int *a,int *b,int *c)
{
	int ret[N*2];
	memset(ret,0,sizeof(ret));// 
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++) ret[i+j]=(ret[i+j]+1LL*a[i]*b[j]%MOD)%MOD;
	for(int i=0;i<=n;i++) c[i]=ret[i];
}

//p->q
int va=0,vb=0,vc=0,vd=0;//0-0  0-x  x-0  x-x
int bln[N],blp[N];//nxt/pre
int pre[N],nxt[N],vis[N];
int F[N*3],G[N*3],H[N*3];
void ready()
{
	for(int i=1;i<=n;i++)
	{
		if(p[i]&&q[i]) nxt[p[i]]=q[i],pre[q[i]]=p[i];
		else if(p[i]) bln[p[i]]=1; 
		else if(q[i]) blp[q[i]]=1;
		else va++;
	}
	for(int i=1;i<=n;i++)//value 
	{
		if(vis[i]) continue;
		vis[i]=1;
		int l=i,r=i;
		while(!vis[pre[l]]&&pre[l]) l=pre[l],vis[l]=1;
		while(!vis[nxt[r]]&&nxt[r]) r=nxt[r],vis[r]=1;
		if(nxt[r]==l) vd++;
		else if(blp[l]&&!bln[r]) vb++;
		else if(!blp[l]&&bln[r]) vc++;
		else if(blp[l]&&bln[r]) va++; 
	}
	//cout<<va<<" "<<vb<<" "<<vc<<" "<<vd<<endl;
}

int ans[N];
void solve()
{
	int tmp;
	for(int i=0;i<=vb;i++)
		for(int j=i;j<=vb;j++) 
		{
			if(j==vb) tmp=1;
			else tmp=C[va+vb-j-1][va-1];//va=0 -1 
			ADD(G[i],1LL*dp[j][i]*C[vb][j]%MOD*tmp%MOD*base[vb-j]%MOD);
		}
	for(int i=0;i<=vc;i++)
		for(int j=i;j<=vc;j++) 
		{
			if(j==vc) tmp=1;
			else tmp=C[va+vc-j-1][va-1];
			ADD(H[i],1LL*dp[j][i]*C[vc][j]%MOD*tmp%MOD*base[vc-j]%MOD);
		}
	//0-x x-00-0 
	for(int i=0;i<=va;i++) ADD(F[i],1LL*dp[va][i]*base[va]%MOD);
	run(F,G,F);
	run(F,H,F);
	for(int i=0;i<=va+vb+vc;i++) ans[n-i-vd]=F[i];
	for(int i=0;i<n;i++) printf("%d ",ans[i]);
}

int main()
{
	init();
	ready();
	solve();
	return 0;
}