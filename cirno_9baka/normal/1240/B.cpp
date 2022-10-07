#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
const int M=1000000007;
#define ri register int 
int n,i,a[300005],q,mx[300005],mn[300005],ans,k,j;
struct str{
	int l,r;
}p[300005];
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			mx[i]=0;
			mn[i]=1<<30;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			mn[a[i]]=min(mn[a[i]],i);
			mx[a[i]]=max(mx[a[i]],i);
		}
		ans=0;
		k=0;
		for(i=1;i<=n;i++)
			if(mx[i]!=0)
			{
				p[++k].l=mn[i];
				p[k].r=mx[i];
			}
		for(i=1;i<=k;)
		{
			for(j=i+1;j<=k&&p[j].l>p[j-1].r;j++);
			ans=max(ans,j-i);
			i=j;
		}
		printf("%d\n",k-ans);
	}
}