#include <cstdio>
#include <algorithm>
#define N 105
int T, n, k, h[N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &k);
		for(int i=1; i<=n; ++i) scanf("%d", h+i);
		h[n+1]=0;
		bool ok=1;
		int i;
		while(k&&ok)
		{
			ok=0;
			for(i=1; i<=n&&h[i]>=h[i+1]; ++i);
			if(i!=n+1) ++h[i], --k, ok=1;
		}
		if(k) puts("-1");
		else printf("%d\n", i);
	}
	return 0;
}