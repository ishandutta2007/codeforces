#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
inline void rd(int &ddd)
{
	char tmp=getchar();
	int xxx=1;
	ddd=0;
	while(('0'>tmp||tmp>'9')&&tmp!='-')
	{
		tmp=getchar();
	}
	if(tmp=='-')
	{
		xxx=-1;
		tmp=getchar();
	}
	while('0'<=tmp&&tmp<='9')
	{
		ddd=(ddd<<3)+(ddd<<1)+(tmp^48);
		tmp=getchar();
	}
	ddd*=xxx;
}
int n,a[4],A,B,ans;
signed main()
{
	rd(n);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=3;++j)
		{
			rd(a[j]);
		}
		printf("%lld\n",(a[1]+a[2]+a[3])>>1);
	}
	return 0;
}