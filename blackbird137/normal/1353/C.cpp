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

LL t,n,ans;

int main()
{
	t=read();
	while(t--)
	{
		n=read();
		ans=0;
		for(LL i=n;i>=1;i-=2)
			ans+=(i-1)*4*((i-1)/2);
		printf("%lld\n",ans);
	}
	return 0;
}