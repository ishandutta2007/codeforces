#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
int n,a,b,ans;
int inv[200010],jc[200010],jcv[200010],s[200020];
void initc()
{
	jc[0]=jc[1]=jcv[0]=jcv[1]=inv[1]=1;
	for(int i=2;i<=n;++i)
	{
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		jc[i]=1ll*jc[i-1]*i%mod;
		jcv[i]=1ll*jcv[i-1]*inv[i]%mod;	
	}
}
int C(int x,int y)
{
	return 1ll*jc[x]*jcv[y]%mod*jcv[x-y]%mod;
}
int kpow(int x,int y)
{
	int s=1;
	while(y)
	{
		if(y&1)s=1ll*s*x%mod;
		y>>=1;
		x=1ll*x*x%mod;	
	}
	return s;
}
void ntt(int f[],int opt,int lim)
{
	static int r[524288],li=0;
	if(li!=lim)
	{
		for(int i=1;i<lim;++i)
			r[i]=(r[i>>1]>>1)|(i&1?lim>>1:0);
		li=lim;	
	}
	for(int i=1;i<lim;++i)
		if(i<r[i])swap(f[i],f[r[i]]);
	for(int len=1;len<lim;len<<=1)
	{
		int tmp=kpow(3,(mod-1)/len/2);
		for(int j=0;j<lim;j+=len<<1)
		{
			int w=1;
			for(int k=0;k<len;++k)
			{
				int c=f[j+k],d=1ll*f[j+k+len]*w%mod;
				(f[j+k]=c+d)>=mod?f[j+k]-=mod:0;
				(f[j+k+len]=c+mod-d)>=mod?f[j+k+len]-=mod:0;
				w=1ll*w*tmp%mod;
			}
		}
	}
	if(opt==-1)
	{
		reverse(f+1,f+lim);
		int iv=kpow(lim,mod-2);
		for(int i=0;i<lim;++i)
			f[i]=1ll*f[i]*iv%mod;
	}
}
void mul(int a[],int b[],int c[],int lim)
{
	static int X[524288],Y[524288];
	int limit=1;
	while(limit<lim)limit<<=1;
	memset(X,0,limit<<2);
	memset(Y,0,limit<<2);
	for(int i=0;i<lim;++i)
		X[i]=a[i],Y[i]=b[i];
	ntt(X,1,limit);
	ntt(Y,1,limit);
	for(int i=0;i<limit;++i)
		X[i]=1ll*X[i]*Y[i]%mod;
	ntt(X,-1,limit);
	for(int i=0;i<lim;++i)
		c[i]=X[i];
}
void solve(int l,int r,int f[])
{
	if(l==r)
	{
		f[0]=l;f[1]=1;
		return ;
	}
	int len=r-l+2;
	int a[len],b[len];
	memset(a,0,len<<2);
	memset(b,0,len<<2);
	solve(l,l+r>>1,a),solve((l+r>>1)+1,r,b);
//	printf("%d %d\n",l,r);
//	for(int i=0;i<len;++i)
//		printf("%d ",a[i]);
//	printf("\n");
//	for(int i=0;i<len;++i)
//		printf("%d ",b[i]);
//	printf("\n");
	mul(a,b,f,len);
//	for(int i=0;i<len;++i)
//		printf("%d ",f[i]);
//	printf("\n");
}
int main()
{
//	freopen("permutation.in","r",stdin);
//	freopen("permutation.out","w",stdout);217724756
	scanf("%d %d %d",&n,&a,&b);
	if(!a||!b||a+b>n+1)
	{
		printf("0");
		return 0;
	}
	if(a==1&&b==1)
	{
		printf("%d",n==1);
		return 0;	
	}
	if(a+b==n+1)
	{
		initc();
		ans=C(n-1,a-1);
		printf("%d",ans);
		return 0;
	}
	initc();
	solve(0,n-2,s);
//	for(int i=0;i<=n;++i)
//		printf("%d ",s[i]);
//	printf("\n");
	printf("%d",1ll*s[a+b-2]*C(a+b-2,a-1)%mod);
	return 0;
}