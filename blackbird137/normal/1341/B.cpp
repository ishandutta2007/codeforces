#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=2e5+5;
int t,n,k,a[N],b[N],mmax,ans,now;

int main()
{
	t=read();
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		n=read();k=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		for(int i=2;i<=n-1;++i)
			if(a[i]>a[i-1]&&a[i]>a[i+1])
				b[i]=1;
		now=0;
		for(int i=2;i<=k-1;++i)
			now+=b[i];
		mmax=now;
		ans=1;
		for(int i=2;i<=n-k+1;++i)
		{
			now-=b[i];
			now+=b[i+k-2];
			if(now>mmax)
			{
				mmax=now;
				ans=i;
			}
		}
		mmax=mmax+1;
		printf("%d %d\n",mmax,ans);
	}
	return 0;
}