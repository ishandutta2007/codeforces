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
int t,n,a[N][4],last,fir;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;++i)
			a[i][0]=read();
		for(int i=1;i<=n;++i)
			a[i][1]=read();
		for(int i=1;i<=n;++i)
			a[i][2]=read();
		last=-1;fir=-1;
		for(int i=1;i<=n-1;++i)
		{
			int tt=0;
			for(int j=0;j<=2;++j)
				if(a[i][j]!=last)
					tt=a[i][j];
			last=tt;
			if(fir==-1) fir=tt;
			printf("%lld ",tt);
		}
		int tt=0;
		for(int j=0;j<=2;++j)
			if(a[n][j]!=last&&a[n][j]!=fir)
				tt=a[n][j];
		last=tt;
		printf("%lld\n",tt);
	}
	return 0;
}