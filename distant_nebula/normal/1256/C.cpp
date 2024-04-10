#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 5000005
#define ll long long
int n, m, d, c[MAXN], p[MAXN], s[MAXN], ans[MAXN], ok;
int main()
{
	scanf("%d%d%d", &n, &m, &d);
	for(int i=1; i<=m; ++i) scanf("%d", c+i);
	for(int i=m; i; --i) s[i]=c[i]+s[i+1];
	for(int i=1, idx=1, pre=0; i<=n; ++i)
	{
		if(n-i+1==s[idx])
		{
			for(; idx<=m; i+=c[idx], ++idx) for(int t=i; t<i+c[idx]; ++t) ans[t]=idx;
			ok=1;
			break;
		}
		if(i==pre+d)
		{
			for(int j=i; j<i+c[idx]; ++j) ans[j]=idx;
			i+=c[idx]-1;
			if(i+d>n) { ok=1; break; }
			if(idx==m) break;
			pre=i;
			++idx;
		}
		if(pre+d>n) ok=1;
	}
	if(!ok) return puts("NO"), 0;
	puts("YES");
	for(int i=1; i<=n; ++i) printf("%d ", ans[i]);
	return 0;
}