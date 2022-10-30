#include <cstdio>
#include <algorithm>
#define N 100005
int T, n, a[N], b[N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d", a+i);
		for(int i=1; i<=n; ++i) scanf("%d", b+i);
		int neg=0, pos=0;
		for(int i=1; i<=n; ++i)
		{
			if((a[i]<b[i]&&!pos)||(a[i]>b[i]&&!neg)) { puts("NO"); goto out; }
			if(a[i]<0) neg=1;
			if(a[i]>0) pos=1;
		}
		puts("YES");
		out:;
	}
	return 0;
}