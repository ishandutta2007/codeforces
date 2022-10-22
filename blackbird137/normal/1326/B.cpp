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

const int N=2e5+5;
int n,b[N],x;

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
		b[i]=read();
	x=0;
	for(int i=1;i<=n;++i)
	{
		printf("%lld ",b[i]+x);
		x=max(x,max(0ll,b[i]+x));
	}
	return 0;
}