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

int t,n,a,flag;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		flag=1;
		a=read();
		for(int i=2;i<=n;++i)
		{
			int b=read();
			if(a!=b) flag=0;
			a=b;
		}
		if(flag) printf("%lld\n",n);
		else printf("1\n");
	}
	return 0;
}