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

const int N=105;
int t,n,a[N];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		for(int i=1;i<=n;++i)
			if((a[i]>0&&i%2==0)||(a[i]<0&&i%2==1))
				a[i]=-a[i];
		for(int i=1;i<=n;++i)
			printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}