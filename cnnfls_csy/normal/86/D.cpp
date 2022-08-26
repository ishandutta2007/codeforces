#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
long long n,m,i,j,l=1,r,ans,num[200005],cnt[1000005];
struct query
{
	long long l,r,ans,id,f;
}qu[200005];
bool cmp(query x,query y)
{
	return x.f<y.f;
}
bool cmp2(query x,query y)
{
	return x.id<y.id;
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for (i=1;i<=n;i++) scanf("%I64d",&num[i]);
	for (i=1;i<=m;i++)
	{
		scanf("%I64d%I64d",&qu[i].l,&qu[i].r);
		qu[i].id=i;
		qu[i].f=qu[i].l/500*500+qu[i].r/500;
	}
	sort(qu+1,qu+m+1,cmp);
	for (i=1;i<=m;i++)
	{
		while (l>qu[i].l)
		{
			l--;
			cnt[num[l]]++;
			ans+=num[l]*(cnt[num[l]]+cnt[num[l]]-1);
		}
		while (r<qu[i].r)
		{
			r++;
			cnt[num[r]]++;
			ans+=num[r]*(cnt[num[r]]+cnt[num[r]]-1);
		}
		while (l<qu[i].l)
		{
			ans-=num[l]*(cnt[num[l]]+cnt[num[l]]-1);
			cnt[num[l]]--;
			l++;
		}
		while (r>qu[i].r)
		{
			ans-=num[r]*(cnt[num[r]]+cnt[num[r]]-1);
			cnt[num[r]]--;
			r--;
		}
		qu[i].ans=ans;
	}
	sort(qu+1,qu+m+1,cmp2);
	for (i=1;i<=m;i++)
	{
		printf("%I64d\n",qu[i].ans);
	}
	return 0;
}