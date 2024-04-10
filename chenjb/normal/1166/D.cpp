#include <cstdio>
#include <iostream>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
long long r[10100],ans[10100];
int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		long long a,b,m; 
		scanf("%lld%lld%lld",&a,&b,&m);
		if (a==b){ printf("1 %lld\n",a); continue; }
		int flag=0;
		for(int k=2;;k++)
		{
			if ((a<<(k-2))>b)break;
			long long x=b-(a<<(k-2));
			if (x<(1ll<<(k-2)))continue; //L
			if ((x+m-1)/m>(1ll<<(k-2)))continue; //R
			for(int i=2;i<k;i++)
			{
				r[i]=min((x-(1ll<<(k-i-1)))>>(k-i-1),m);
				x=x-(r[i]<<(k-i-1));
			}
			if (x<1 || x>m)continue;
			r[k]=x;
			ans[1]=a;
			for(int i=2;i<=k;i++)
			{
				ans[i]=r[i];
				for(int j=1;j<i;j++)ans[i]+=ans[j];
			}
			printf("%d",k);
			rep(i,k)printf(" %lld",ans[i]);
			puts("");
			flag=1;
			break;
		}
		
		if (!flag)puts("-1");
	}
}

//a
//a + r2
//2 * a + r2 + r3
//4 * a + 2 * r2 + r3 + r4