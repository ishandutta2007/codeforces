#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define LL long long

using namespace std;

LL read()
{
	LL ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

LL t,n,a,ans,now,f;

int main()
{
	t=read();
	while(t--)
	{
		n=read();
		a=read();
		ans=0;now=a;
		f=a<0?-1:1;
		for(LL i=2;i<=n;++i)
		{
			a=read();
			LL tf=a<0?-1:1;
			if(tf!=f)
				ans+=now,now=a;
				
			now=max(now,a);
			f=tf;
		}
		printf("%lld\n",ans+now);
	}
	return 0;
}