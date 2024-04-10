#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,k,a[200020],cnt[200020],p[200020],c[200020];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			++cnt[a[i]];
			if(cnt[a[i]]>k)a[i]=n+1;
		}
		int tot=0;
		for(int i=1;i<=n;++i)tot+=min(cnt[i],k);
		tot=tot/k*k;
		for(int i=1;i<=n;++i)p[i]=i;
		sort(p+1,p+1+n,[&](int x,int y){return a[x]!=a[y]?a[x]<a[y]:x<y;});
		for(int i=1;i<=tot;++i)c[p[i]]=(i-1)%k+1;
		for(int i=1;i<=n;++i)printf("%d ",c[i]);printf("\n");
		memset(cnt+1,0,n<<2);
		memset(c+1,0,n<<2);
	}
	return 0;
}