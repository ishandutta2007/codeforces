#include <cstdio>
#include <algorithm>
#define E 26
#define N 200005
int T, n, k, cnt[E], ans;
char s[N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%s", &n, &k, s+1);
		ans=0;
		for(int i=1; (i<<1)<=k; ++i)
		{
			std::fill(cnt, cnt+E, 0);
			for(int j=i, t=k-i+1; j<=n; j+=k, t+=k) ++cnt[s[j]-'a'], ++cnt[s[t]-'a'];
			int mx=0, tot=0;
			for(int i=0; i<E; ++i) mx=std::max(cnt[i], mx), tot+=cnt[i];
			ans+=tot-mx;
		}
		if(k&1)
		{
			std::fill(cnt, cnt+E, 0);
			for(int j=(k>>1)+1; j<=n; j+=k) ++cnt[s[j]-'a'];
			int mx=0, tot=0;
			for(int i=0; i<E; ++i) mx=std::max(cnt[i], mx), tot+=cnt[i];
			ans+=tot-mx;
		}
		printf("%d\n", ans);
	}
	return 0;
}