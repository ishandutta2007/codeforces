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

int t,x,n,m;

int main()
{
	t=read();
	while(t--)
	{
		x=read();n=read();m=read();
		while((x/2)+10<x&&n--)
			x=(x/2)+10;
		x-=m*10;
		if(x<=0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}