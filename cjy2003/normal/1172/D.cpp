#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,r[1010],c[1010],fr[1010],fc[1010],pa[1010],pb[1010],a[1010],b[1010];
int st[1010][4],tp;
int main()
{
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		r[i]=x;fr[x]=i;
	}
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		c[i]=x;fc[x]=i;
	}
	for(int i=1;i<=n;++i)a[i]=b[i]=i,pa[i]=pb[i]=i;
	for(int i=1;i<=n;++i)
	{
		if(pa[fr[i]]==i&&pb[fc[i]]==i)continue;
		x=pa[fr[i]],y=pb[fc[i]];
		st[++tp][0]=i,st[tp][1]=y,st[tp][2]=x,st[tp][3]=i;
		swap(pa[fr[i]],pa[a[i]]);
		swap(pb[fc[i]],pb[b[i]]);
		swap(a[i],a[x]);
		swap(b[i],b[y]);		
	//	swap(b[i],b[r[i]]);
	//	swap()
	}
	printf("%d\n",tp);
	for(int i=1;i<=tp;++i)
		printf("%d %d %d %d\n",st[i][0],st[i][1],st[i][2],st[i][3]);
	return 0;
}