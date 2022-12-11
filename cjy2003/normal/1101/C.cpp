#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct seg
{
	int l,r,id;
}a[100010];
bool cmp1(seg a,seg b)
{
	return a.l<b.l;
}
int t,n,x,p,ans[100010];
bool flag;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d %d",&a[i].l,&a[i].r),a[i].id=i;
		sort(a+1,a+1+n,cmp1);
		p=0;
		flag=0;
		for(int i=1;i<=n;++i)
		{
			if(i!=1&&p<a[i].l)
			{
				flag=1;
				break;
			}
			p=max(p,a[i].r);
		}
		if(!flag)printf("-1\n");
		else
		{
			for(int i=1;i<=n;++i)
				ans[a[i].id]=a[i].r<=p?1:2;
			for(int i=1;i<=n;++i)
				printf("%d ",ans[i]);
			printf("\n");
		}
	}
	return 0;
}