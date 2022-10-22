#include<cstdio>
#include<algorithm>
#define mid ((l+r)>>1)
using namespace std;
int qry(int w)
{
	printf("? %d\n",w);
	fflush(stdout);
	scanf("%d",&w);
	return w;
}
int n,ans,a;
int main()
{
	scanf("%d",&n);
	int l=1,r=n*2001;
	while(l<r)
		if(qry(mid)==1) r=mid;
		else l=mid+1;
	ans=l;
	for(int i=2;i<=n;i++)
	{
		a=qry(l/i);
		if(a==0) break;
		if(1ll*(l/i)*a>=ans) continue;
		ans=(l/i)*a;
	}
	printf("! %d\n",ans);
	fflush(stdout);
}