#include<bits/stdc++.h>
#define MaxN 1123
int a[MaxN][MaxN];

int prime[MaxN*100],cnt=0;
bool vis[MaxN*100];
inline void Sieve()
{
	for(int i=2;i<=100000;++i)
	{
		if(!vis[i])
		{
			prime[++cnt]=i;
		}
		for(int j=1;j<=cnt&&i*prime[j]<=100000;++j)
		{
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
} 

int main()
{
	Sieve();
	int T,n;std::cin>>T;
	while(T--)
	{
		std::cin>>n;
		for(int k=2;k<=100000;++k)
		if(vis[k]&&(!vis[k*(n-1)+1]))
		{
			for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
			printf("%d%c",(i==j?1:k)," \n"[j==n]);
			break;
		}
	}
	return 0;
}