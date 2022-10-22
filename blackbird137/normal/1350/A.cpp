#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<bitset>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
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

LL t,n,k,now;

int main()
{
	t=read();
	while(t--)
	{
		n=read();k=read()-1;
		now=n;
		for(LL i=2;i<=sqrt(n);++i)
			if(n%i==0)
			{
				now=i;
				break;
			}
		printf("%lld\n",n+now+2*k);
	}
	return 0;
}