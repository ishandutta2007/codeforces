#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=10007;
inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}
inline int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=a*a%mod)
		if(b&1)s=s*a%mod;
	return s;
}
void mul(int a[],int b[],int c[],int f[],int len)
{
	static int X[2020];
//	for(int i=0;i<len;++i)printf("%d ",a[i]);printf("\n");
//	for(int i=0;i<len;++i)printf("%d ",b[i]);printf("\n");
	memset(X,0,sizeof(X));
	for(int i=0;i<len;++i)
		for(int j=0;j<len;++j)
			X[i+j]=(X[i+j]+a[i]*b[j])%mod;
//	for(int i=0;i<2*len;++i)printf("%d ",X[i]);printf("\n");
	for(int i=2*len-2;i>=len;--i)
		if(X[i])
		{
			for(int j=1;j<len;++j)X[i-j]=(X[i-j]+X[i]*f[len-1-j])%mod;
			X[i]=0;
		}
	memcpy(c,X,len<<2);
//	for(int i=0;i<len;++i)printf("%d ",c[i]);printf("\n");
}
int BM(int a[],int lena,int n)
{
	static int f[810],f1[810],nf[810],lenf,lenf1,p,c,d,nlen;
//	for(int i=0;i<=lena;++i)printf("%d ",a[i]);printf("\n");
	memset(f,0,sizeof(f)),memset(f1,0,sizeof(f1));
	f1[0]=mod-1,lenf1=1;
	f[0]=mod-1,lenf=1;
	for(int i=0;i<=lena;++i)
	{
		d=0;
		for(int j=0;j<lenf;++j)d=(d+f[j]*a[i-j])%mod;
		if(!d)continue;
		if(lenf==1)
		{
			lenf=i+2,p=i,c=d;
			continue;
		}
		int res=mod-d*kpow(c,mod-2)%mod;
	//	printf("%d %d\n",d,res);
		memcpy(nf,f,sizeof(f));
		for(int j=0;j<lenf1;++j)nf[j+i-p]=(nf[j+i-p]+res*f1[j])%mod;
		nlen=max(lenf,lenf1+i-p);
		if(nlen>lenf)memcpy(f1,f,sizeof(f)),lenf1=lenf,c=d,p=i;
		lenf=nlen;
		memcpy(f,nf,sizeof(nf));
	//	printf("%d:\n",i);
	//	for(int j=0;j<lenf;++j)printf("%d ",f[j]);printf("\n");
	}
	static int t[810],s[810];
	reverse(f,f+lenf);
//	for(int i=0;i<lenf;++i)printf("%d ",f[i]);printf("\n");
//	printf("%d\n",lenf);
	memset(t,0,sizeof(t));memset(s,0,sizeof(s));
	t[1]=1;s[0]=1;
	for(;n;n>>=1,mul(t,t,t,f,lenf))
		if(n&1)mul(s,t,s,f,lenf);
	int res=0;
	for(int i=0;i<lenf;++i)res=(res+s[i]*a[i])%mod;
	return res;
}
char s[210];
int m,n,dp[2][210][210],a[810];
int main()
{
	scanf("%s %d",s+1,&m);m+=n=strlen(s+1);
	int t=0;
	dp[t][1][n]=1;
	for(int i=1;i<=700;++i)
	{
		t^=1;
		memset(dp[t],0,sizeof(dp[t]));
		for(int j=1;j<=n;++j)
			for(int k=j;k<=n;++k)
				if(dp[t^1][j][k])
				{
					if(s[j]==s[k])
					{
						if(j+1>=k)add(dp[t][0][0],dp[t^1][j][k]);
						else add(dp[t][j+1][k-1],dp[t^1][j][k]);
						dp[t][j][k]=(dp[t][j][k]+25*dp[t^1][j][k])%mod;
					}
					else
					{
						add(dp[t][j+1][k],dp[t^1][j][k]);
						add(dp[t][j][k-1],dp[t^1][j][k]);
						dp[t][j][k]=(dp[t][j][k]+24*dp[t^1][j][k])%mod;
					}
				}
		dp[t][0][0]=(dp[t][0][0]+dp[t^1][0][0]*26)%mod;
		if(m&1)
		{
			a[i]=dp[t^1][0][0]*26%mod;
			for(int j=1;j<=n;++j)add(a[i],dp[t^1][j][j]);
		}
		else a[i]=dp[t][0][0];
	}
	printf("%d",BM(a,700,(m+1)/2));
	return 0;
}