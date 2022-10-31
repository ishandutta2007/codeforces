#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f
const int N=250005;
int T, n, p[N], f[N], up[N], dw[N], stk[N], top, rp[N];
inline void gmn(int &x, int a) { x=std::min(x, a); }
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d", p+i), rp[p[i]]=i;
		// mn[n+1]=INF, mx[n+1]=0;
		// for(int i=n; i; --i) mn[i]=std::min(mn[i+1], p[i]), mx[i]=std::max(mx[i+1], p[i]);
		top=0;
		stk[0]=n+1;
		for(int i=n; i; --i)
		{
			while(top&&p[i]<p[stk[top]]) --top;
			dw[i]=stk[top];
			stk[++top]=i;
		}
		top=0;
		for(int i=n; i; --i)
		{
			while(top&&p[i]>p[stk[top]]) --top;
			up[i]=stk[top];
			stk[++top]=i;
		}
		int t=1, ct=0;
		while(t<n)
		{
			if(p[t+1]>p[t])
			{
				int x=dw[t];
				while(up[t]<x) t=up[t];
			}
			else
			{
				int x=up[t];
				while(dw[t]<x) t=dw[t];
			}
			++ct;
		}
		printf("%d\n", ct);
	}
	return 0;
}