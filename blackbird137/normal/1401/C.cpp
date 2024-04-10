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

const int N=1e5+5;
int t,n,a[N],b[N],mmin;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		mmin=1e10;
		for(int i=1;i<=n;++i)
		{
			a[i]=b[i]=read();
			mmin=min(mmin,a[i]);
		}
		sort(b+1,b+1+n);
		int flag=1;
		for(int i=1;i<=n;++i)
			if(a[i]!=b[i]&&a[i]%mmin!=0)
			{
				flag=0;
				break;
			}
		printf("%s\n",flag?"YES":"NO");
	}
	return 0;
}