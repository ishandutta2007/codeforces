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

const int N=1e3+5;
int t,n,x,a[N];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();x=read();
		int sum=0,flag=1,flag2=0;
		for(int i=1;i<=n;++i)
		{
			a[i]=read(),sum+=a[i];
			if(a[i]!=x)
				flag=0;
			else flag2=1;
		}
		int ans;
		if(flag) ans=0;
		else if(flag2||sum==n*x) ans=1;
		else ans=2;
		printf("%lld\n",ans);
	}
	return 0;
}