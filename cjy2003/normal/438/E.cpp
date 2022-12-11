#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353,inv2=499122177;
int kpow(int a,int b)
{
	int s=1;
	while(b)
	{
		if(b&1)s=1ll*s*a%mod;
		b>>=1;
		a=1ll*a*a%mod;
	}
	return s;
}
int inv[262145],w[18][131072];
void init()
{
	inv[1]=1;
	for(int i=2;i<=262144;++i)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	int tmp;
	for(int len=1,i=0;len<262144;len<<=1,++i)
	{
		tmp=kpow(3,(mod-1)/len/2);w[i][0]=1;
		for(int j=1;j<len;++j)w[i][j]=1ll*w[i][j-1]*tmp%mod;
	}
//	for(int len=1,i=0;i<=2;len<<=1,++i)
//	{
//		for(int j=0;j<len;++j)
//			printf("%d ",w[i][j]);
//		printf("\n");
//	}
}
void ntt(int f[],int opt,int lim)
{
	static int r[262144],now=0;
	if(now!=lim)
	{
		now=lim;
		for(int i=1;i<lim;++i)r[i]=(r[i>>1]>>1)|(i&1?lim>>1:0);
	}
	for(int i=1;i<lim;++i)if(i<r[i])swap(f[i],f[r[i]]);
	for(int len=1,i=0;len<lim;len<<=1,++i)
		for(int j=0;j<lim;j+=len<<1)
			for(int k=0;k<len;++k)
			{
				int x=f[j+k],y=1ll*f[j+k+len]*w[i][k]%mod;
				(f[j+k]=x+y)>=mod?f[j+k]-=mod:0;
				(f[j+k+len]=x+mod-y)>=mod?f[j+k+len]-=mod:0;
			}
	if(opt==-1)
	{
		reverse(f+1,f+lim);
		for(int i=0;i<lim;++i)f[i]=1ll*f[i]*inv[lim]%mod;
	}
}
void mul(int A[],int B[],int C[],int n)
{
	static int X[262144],Y[262144],lim;
	lim=1;
	while(lim<n)lim<<=1;lim<<=1;
//	printf("%d\n",lim);
	memset(X,0,lim<<2);
	memset(Y,0,lim<<2);
	for(int i=0;i<n;++i)X[i]=A[i],Y[i]=B[i];
//	for(int i=0;i<lim;++i)printf("%d ",X[i]);printf("\n");
//	for(int i=0;i<lim;++i)printf("%d ",Y[i]);printf("\n");
	ntt(X,1,lim);ntt(Y,1,lim);
	for(int i=0;i<lim;++i)X[i]=1ll*X[i]*Y[i]%mod;
	ntt(X,-1,lim);
//	for(int i=0;i<lim;++i)printf("%d ",X[i]);printf("\n");
	for(int i=0;i<n;++i)C[i]=X[i];
}
void getinv(int f[],int g[],int n)
{
	static int B[2][262144],now,lim,t,A[262144];
	memset(A,0,sizeof(A));
	memset(B,0,sizeof(B));t=0;
	now=1,lim=2;B[0][0]=kpow(f[0],mod-2);A[0]=f[0];
//	printf("%d %d\n",f[0],B[0][0]);
	while(now<n)
	{
		now<<=1,lim<<=1,t^=1;
		for(int i=0;i<now>>1;++i)(B[t][i]=B[t^1][i]<<1)>=mod?B[t][i]-=mod:0;
		mul(B[t^1],B[t^1],B[t^1],now);
		for(int i=now>>1;i<now;++i)A[i]=f[i];
		mul(B[t^1],A,B[t^1],now);
		for(int i=0;i<now;++i)(B[t][i]+=mod-B[t^1][i])>=mod?B[t][i]-=mod:0;
	}
	for(int i=0;i<n;++i)g[i]=B[t][i];
}
void getln(int f[],int g[],int n)
{
	static int A[262144],B[262144];
	memset(A,0,sizeof(A));memset(B,0,sizeof(B));
	for(int i=0;i<n;++i)A[i]=f[i];
	for(int i=1;i<n;++i)B[i-1]=1ll*f[i]*i%mod;
	getinv(A,A,n);
//	for(int i=0;i<n;++i)printf("%d ",A[i]);printf("\n");
	mul(A,B,B,n);
	for(int i=n-1;i>0;--i)
		g[i]=1ll*B[i-1]*inv[i]%mod;
	g[0]=0;
}
void getexp(int f[],int n)
{
	static int B[2][262144],now,lim,t;
	memset(B,0,sizeof(B));t=0;B[0][0]=1;
	now=1,lim=2;
	while(now<n)
	{
		now<<=1,lim<<=1,t^=1;
		getln(B[t^1],B[t],now);
		for(int i=0;i<now;++i)(B[t][i]=f[i]+mod-B[t][i])>=mod?B[t][i]-=mod:0;
		(++B[t][0])>=mod?B[t][0]-=mod:0;
		mul(B[t],B[t^1],B[t],now);
	//	for(int i=0;i<now;++i)printf("%d ",B[t][i]);printf("\n");
	}
	for(int i=0;i<n;++i)f[i]=B[t][i];
}
int n,m,G[100010],F[100010];
int main()
{
	init();
	scanf("%d %d",&n,&m);
	int x;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		G[x]=mod-4;
	}
	G[0]=1;
//	for(int i=0;i<=m;++i)
//		printf("%d ",G[i]);
//	printf("\n"); 
	getln(G,G,m+1);
//	for(int i=0;i<=m;++i)
//		printf("%d ",G[i]);
//	printf("\n");
	for(int i=0;i<=m;++i)
		G[i]=1ll*G[i]*inv2%mod;
//	for(int i=0;i<=m;++i)printf("%d ",G[i]);printf("\n");
	getexp(G,m+1);
	(++G[0])>=mod?G[0]-=mod:0;
//	for(int i=0;i<=m;++i)printf("%d ",G[i]);printf("\n");
	getinv(G,G,m+1);
//	for(int i=0;i<=m;++i)printf("%d ",G[i]);printf("\n");
	for(int i=0;i<=m;++i)(G[i]<<=1)>=mod?G[i]-=mod:0;
	for(int i=1;i<=m;++i)printf("%d\n",G[i]);
	return 0;
}