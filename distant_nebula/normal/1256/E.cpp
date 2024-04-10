#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 200005
#define ll long long
int n, a[MAXN], id1[MAXN], f[MAXN], pre[MAXN], mn[3], id[3], ans[MAXN], res;
bool cmp(int x, int y) { return a[x]<a[y]; }
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), id1[i]=i;
	std::sort(id1+1, id1+n+1, cmp);
	mn[0]=mn[1]=mn[2]=-a[id1[1]];
	for(int i=3; i<=n; ++i)
	{
		f[i]=a[id1[i]]+mn[0];
		pre[i]=id[0];
		mn[0]=mn[1];
		id[0]=id[1];
		mn[1]=mn[2];
		id[1]=id[2];
		if(mn[2]>f[i]-a[id1[i+1]]) id[2]=i, mn[2]=f[i]-a[id1[i+1]];
	}
	for(int idx=n; idx; idx=pre[idx])
	{
		++res;
		for(int i=pre[idx]+1; i<=idx; ++i) ans[id1[i]]=res;
	}
	printf("%d %d\n", f[n], res);
	for(int i=1; i<=n; ++i) printf("%d ", ans[i]);
	return 0;
}