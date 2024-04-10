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

int t,x[2],y[2],z[2],ans;

signed main()
{
	t=read();
	while(t--)
	{
		x[0]=read();y[0]=read();z[0]=read();
		x[1]=read();y[1]=read();z[1]=read();
		ans=0;
		int tmp=min(z[0],y[1]);
		ans+=tmp*2;
		z[0]-=tmp;
		y[1]-=tmp;
		tmp=min(z[0],z[1]);
		z[0]-=tmp;z[1]-=tmp;
		tmp=min(z[1],x[0]);
		z[1]-=tmp;x[0]-=tmp;
		ans-=z[1]*2;
		printf("%lld\n",ans);
	}
	return 0;
}