#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 100005
using std::vector;
int T, n, m, a[N], b[N], cnt[N], id[N], c[N], ans[N];
vector<int> v[N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; ++i) v[i].clear();
		std::fill(cnt+1, cnt+n+1, 0);
		std::fill(id+1, id+n+1, 0);
		std::fill(ans+1, ans+m+1, 0);
		for(int i=1; i<=n; ++i) scanf("%d", a+i);
		for(int i=1; i<=n; ++i) scanf("%d", b+i), id[b[i]]=i;
		for(int i=1, x; i<=m; ++i)
		{
			scanf("%d", &x);
			c[i]=x;
			v[x].push_back(i);
			++cnt[x];
		}
		for(int i=1; i<=n; ++i)
		{
			if(a[i]!=b[i])
			{
				if(!cnt[b[i]]) { puts("NO"); goto out; }
				--cnt[b[i]];
				ans[*(v[b[i]].rbegin())]=i;
				v[b[i]].pop_back();
			}
		}
		if(!ans[m]) ans[m]=id[c[m]];
		for(int i=1; i<=m; ++i) if(!ans[i])
		{
			if(i==m) { puts("NO"); goto out; }
			ans[i]=ans[m];
		}
		puts("YES");
		for(int i=1; i<=m; ++i) printf("%d ", ans[i]);
		puts("");
		out:;
	}
	return 0;
}