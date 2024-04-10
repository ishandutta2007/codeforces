#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1000000007;
inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}
inline int pl(int x,int y){return (x+=y)>=mod?x-mod:x;}
inline int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
char s[510];
int ch[510][2],tot,n,a[16],b[16],c[16],d[16],e[16],dp[510][1<<16];
char op[510];
int work(int l,int r)
{
	int c=0,p=++tot;
//	printf("%d %d %d\n",l,r,p);
	if(l==r)return op[p]=s[l],p;
	for(int i=l;i<=r;++i)
	{
		if(s[i]=='(')++c;
		else if(s[i]==')')--c;
		if(!c)
		{
		//	printf("%d %d %d\n",l,r,i+1);
			ch[p][0]=work(l+1,i-1);
			ch[p][1]=work(i+3,r-1);
			op[p]=s[i+1];
			return p;
		}
	}
}
void print(int v)
{
	printf("%d %d %c\n",ch[v][0],ch[v][1],op[v]);
	if(ch[v][0])print(ch[v][0]),print(ch[v][1]);
}
void fwt_and(int f[],int opt)
{
	if(opt==1)
	{
		for(int len=1;len<1<<n;len<<=1)
			for(int j=0;j<1<<n;j+=len<<1)
				for(int k=0;k<len;++k)add(f[j+k],f[j+k+len]);
	}
	else
	{
		for(int len=1;len<1<<n;len<<=1)
			for(int j=0;j<1<<n;j+=len<<1)
				for(int k=0;k<len;++k)add(f[j+k],mod-f[j+k+len]);
	}
}
void fwt_or(int f[],int opt)
{
	if(opt==1)
	{
		for(int len=1;len<1<<n;len<<=1)
			for(int j=0;j<1<<n;j+=len<<1)
				for(int k=0;k<len;++k)add(f[j+k+len],f[j+k]);
	}
	else
	{
		for(int len=1;len<1<<n;len<<=1)
			for(int j=0;j<1<<n;j+=len<<1)
				for(int k=0;k<len;++k)add(f[j+k+len],mod-f[j+k]);
	}
}
void mul_and(int f[],int g[],int h[])
{
	static int X[65536],Y[65536];
	memcpy(X,f,4<<n);
	memcpy(Y,g,4<<n);
	fwt_and(X,1);fwt_and(Y,1);
	for(int i=0;i<1<<n;++i)X[i]=1ll*X[i]*Y[i]%mod;
	fwt_and(X,-1);
	for(int i=0;i<1<<n;++i)add(h[i],X[i]);
}
void mul_or(int f[],int g[],int h[])
{
	static int X[65536],Y[65536];
	memcpy(X,f,4<<n);
	memcpy(Y,g,4<<n);
	fwt_or(X,1);fwt_or(Y,1);
	for(int i=0;i<1<<n;++i)X[i]=1ll*X[i]*Y[i]%mod;
	fwt_or(X,-1);
	for(int i=0;i<1<<n;++i)add(h[i],X[i]);
}
void solve(int v)
{
	if(!ch[v][0])
	{
		int now;
		if(op[v]=='A'||op[v]=='?'){now=0;for(int i=0;i<n;++i)now|=a[i]<<i;++dp[v][now];}
		if(op[v]=='B'||op[v]=='?'){now=0;for(int i=0;i<n;++i)now|=b[i]<<i;++dp[v][now];}
		if(op[v]=='C'||op[v]=='?'){now=0;for(int i=0;i<n;++i)now|=c[i]<<i;++dp[v][now];}
		if(op[v]=='D'||op[v]=='?'){now=0;for(int i=0;i<n;++i)now|=d[i]<<i;++dp[v][now];}
		if(op[v]=='a'||op[v]=='?'){now=0;for(int i=0;i<n;++i)now|=(!a[i])<<i;++dp[v][now];}
		if(op[v]=='b'||op[v]=='?'){now=0;for(int i=0;i<n;++i)now|=(!b[i])<<i;++dp[v][now];}
		if(op[v]=='c'||op[v]=='?'){now=0;for(int i=0;i<n;++i)now|=(!c[i])<<i;++dp[v][now];}
		if(op[v]=='d'||op[v]=='?'){now=0;for(int i=0;i<n;++i)now|=(!d[i])<<i;++dp[v][now];}
		return ;
	}
	solve(ch[v][0]);
	solve(ch[v][1]);
	if(op[v]!='|')mul_and(dp[ch[v][0]],dp[ch[v][1]],dp[v]);
	if(op[v]!='&')mul_or(dp[ch[v][0]],dp[ch[v][1]],dp[v]);
}
int main()
{
	scanf("%s",s+1);
	work(1,strlen(s+1));
//	print(1);
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d %d %d %d %d",&a[i],&b[i],&c[i],&d[i],&e[i]);
	solve(1);
	int now=0;
	for(int i=0;i<n;++i)now|=e[i]<<i;
	printf("%d",dp[1][now]);
	return 0;
}