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

LL t,a,b,c,d,ans;

int main()
{
	t=read();
	while(t--)
	{
		a=read();b=read();c=read();d=read();
		if(a<=b)
		{
			printf("%lld\n",b);
			continue;
		}
		else if(c-d<=0)
		{
			printf("-1\n");
			continue;
		}
		ans=b,a-=b;
		ans+=(ceil(a/(c-d+0.0)))*c;
		printf("%lld\n",ans);
	}
	return 0;
}