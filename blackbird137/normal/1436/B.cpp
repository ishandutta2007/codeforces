#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define int long long

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

int t,n,mmap[105][105];

inline bool check(int x);

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		int sum=997-n+1,num=1;
		while(check(sum)||check(num))
		{
			sum-=n-1;
			num++;
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
				if(i==j) printf("%lld ",sum);
				else printf("%lld ",num);
			printf("\n");
		}
			
	}
	return 0;
}

inline bool check(int x)
{
	if(x==2) return 1;
	for(int i=2;i*i<=x;++i)
		if(x%i==0) return 0;
	return 1;
}