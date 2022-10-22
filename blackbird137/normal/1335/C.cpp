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
int t,n,a[N],vis[N],mmax,sum,ans;

int main()
{
	t=read();
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		n=read();
		mmax=0;sum=0;
		for(int i=1;i<=n;++i)
		{
			a[i]=read();
			if(!vis[a[i]])
				sum++;
			vis[a[i]]++;
			mmax=max(mmax,vis[a[i]]);
		}
		if(mmax>sum)
			ans=sum;
		else if(mmax==sum)
			ans=sum-1;
		else
			ans=mmax;
		printf("%d\n",ans);
	}
	return 0;
}