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

LL t,n,m;

int main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();
		if(n==1||m==1||(n==2&&m==2))
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}