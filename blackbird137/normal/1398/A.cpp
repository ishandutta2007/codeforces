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

const int N=5e4+5;
int t,n,a[N],flag;

signed main()
{
	t=read();
	while(t--)
	{
		flag=0;
		n=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		if(a[1]+a[2]>a[n])
			printf("-1\n");
		else printf("1 2 %d\n",n);
	}
	return 0;
}