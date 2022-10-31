#include <cstdio>
#include <algorithm>
#define ll long long
const int N=200005;
int T, n, k, m, tp, tp1, a[N], b[N];
ll ca[N], cb[N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		tp=tp1=0;
		for(int i=1, x; i<=n; ++i)
		{
			scanf("%d", &x);
			int ct=1;
			while(x%m==0) x/=m, ct*=m;
			if(x!=a[tp]) a[++tp]=x, ca[tp]=0;
			ca[tp]+=ct;
		}
		scanf("%d", &k);
		for(int i=1, x; i<=k; ++i)
		{
			scanf("%d", &x);
			int ct=1;
			while(x%m==0) x/=m, ct*=m;
			if(x!=b[tp1]) b[++tp1]=x, cb[tp1]=0;
			cb[tp1]+=ct;
		}
		if(tp!=tp1) { puts("No"); continue; }
		for(int i=1; i<=tp; ++i) if(a[i]!=b[i]||ca[i]!=cb[i])
		{
			puts("No"); goto out;
		}
		puts("Yes");
		out:;
	}
	return 0;
}