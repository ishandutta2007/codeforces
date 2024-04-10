#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 200000
using namespace std;
int T,n,a[N+5];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",a+i);
		int d=0;
		for(int w=0;w<30;++w)
		{
			int cnt=0;
			for(int i=1;i<=n;++i)
				cnt+=(a[i]>>w)&1;
			if(cnt) d=__gcd(cnt,d);
		}
		for(int i=1;i<=n;++i)
			if(!(d%i)) printf("%d ",i);
		putchar('\n');
	}
	return 0;
}