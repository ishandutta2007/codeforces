#include <cstdio>
#include <map>
#include <algorithm>
#define ll long long
#define N 200005
using std::map;
int n, cur;
ll ans, a[N];
map<ll, int> pos;
int main()
{
	scanf("%d", &n);
	ans=1ll*n*(n+1)/2;
	for(int i=1; i<=n; ++i) scanf("%lld", a+i), a[i]+=a[i-1];
	pos[0]=1;
	for(int i=1; i<=n; ++i)
	{
		cur=std::max(cur, pos[a[i]]), pos[a[i]]=i+1;
		ans-=cur;
	}
	printf("%lld\n", ans);
	return 0;
}