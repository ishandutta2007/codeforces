#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define int long long

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=50,M=20,mod=2520;
int t,n,m,a[M],dp[M][N][mod],mp[mod+5],tot;

inline int lcm(int a,int b);
int DP(int x,int y,int p,int is); 
inline int work(int n);

signed main()
{
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=mod;++i)
		if(mod%i==0)
			mp[i]=++tot;
	t=read();
	while(t--) 
	{
		n=read();m=read();
		printf("%lld\n",work(m)-work(n-1));
	}
	return 0;
}

inline int lcm(int a,int b)
{
	return a*b/__gcd(a,b);
}

int DP(int x,int y,int p,int is)
{
	if(!x) return p%y==0;
	if(!is&&dp[x][mp[y]][p]!=-1)
		return dp[x][mp[y]][p];
	int mmax=9,res=0;
	if(is) mmax=a[x-1];
	for(int i=0;i<=mmax;++i)
		if(i==0)
			res+=DP(x-1,y,(p*10+i)%mod,is&&i==mmax);
		else
			res+=DP(x-1,lcm(y,i),(p*10+i)%mod,is&&i==mmax);
	if(!is)
		dp[x][mp[y]][p]=res;
	return res;
}

inline int work(int n)
{
	int x=0;
	while(n)
	{
		a[x++]=n%10;
		n/=10;
	}
	return DP(x,1,0,1);
}