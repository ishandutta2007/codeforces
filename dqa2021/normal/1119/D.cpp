#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;  //I64d!!!

int n,q;
ll w[100010],ww[100010],www[100010];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%I64d",w+i);
	sort(w+1,w+n+1);
	for (int i=1;i<n;i++) ww[i]=w[i+1]-w[i];
	sort(ww+1,ww+n);
	for (int i=1;i<n;i++) www[i]=www[i-1]+ww[i]/*,printf("www %d = %I64d\n",i,www[i])*/;
	scanf("%d",&q);
	while (q--)
	{
		ll l,r;
		scanf("%I64d%I64d",&l,&r);
		r=r-l+1;
		if (n==1){printf("%I64d ",r);continue;}
		if (ww[1]>r){printf("%I64d ",r*n);continue;}
		int lll=1,rrr=n-1,mid;
		while (lll<rrr)
		{
			mid=lll+rrr+1>>1;
			if (ww[mid]<=r) lll=mid;
			else rrr=mid-1;
		}
		printf("%I64d ",r*n-r*lll+www[lll]);
	}
	putchar('\n');
	return 0;
}