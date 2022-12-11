#include<cstdio>
#include<algorithm>
using namespace std;

int n;
int pos[10];
int ans[10];

int main()
{
	scanf("%d",&n);
	for (int i=1,tmp;i<=n;i++)
	{
		printf("? %d %d %d %d\n",1,i,n,i);
		fflush(stdout);
		scanf("%d",&tmp);
		if (tmp&1) pos[++*pos]=i;
	}
	if (*pos)
	{
		int l=1,r=n,mid,tmp;
		while (l<r)
		{
			mid=l+r+1>>1;
			printf("? %d %d %d %d\n",mid,pos[1],n,pos[1]);
			fflush(stdout);
			scanf("%d",&tmp);
			if (tmp&1) l=mid;
			else r=mid-1;
		}
		ans[++*ans]=l,ans[++*ans]=pos[1];
		l=1,r=n;
		while (l<r)
		{
			mid=l+r+1>>1;
			printf("? %d %d %d %d\n",mid,pos[2],n,pos[2]);
			fflush(stdout);
			scanf("%d",&tmp);
			if (tmp&1) l=mid;
			else r=mid-1;
		}
		ans[++*ans]=l,ans[++*ans]=pos[2];
		printf("!");
		for (int i=1;i<=4;i++) printf(" %d",ans[i]);
		puts("");
		return 0;
	}
	for (int i=1,tmp;i<=n;i++)
	{
		printf("? %d %d %d %d\n",i,1,i,n);
		fflush(stdout);
		scanf("%d",&tmp);
		if (tmp&1) pos[++*pos]=i;
	}
	int l=1,r=n,mid,tmp;
	while (l<r)
	{
		mid=l+r+1>>1;
		printf("? %d %d %d %d\n",pos[1],mid,pos[1],n);
		fflush(stdout);
		scanf("%d",&tmp);
		if (tmp&1) l=mid;
		else r=mid-1;
	}
	printf("! %d %d %d %d\n",pos[1],l,pos[2],l);
	return 0;
}