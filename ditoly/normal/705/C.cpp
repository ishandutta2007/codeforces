#include<cstdio>
#define MN 300000
int a[MN+5],b[MN+5],L,R,l[MN+5],r[MN+5];
int main()
{
	int n,q,o,x,ans=0;
	scanf("%d%d",&n,&q);
	while(q--)
	{
		scanf("%d%d",&o,&x);
		if(o==1)a[++R]=x,b[R]=++r[x],++ans;
		if(o==2)ans-=r[x]-l[x],l[x]=r[x];
		if(o==3)while(L<x)++L,b[L]>l[a[L]]?++l[a[L]],--ans:0;
		printf("%d\n",ans);
	}
}