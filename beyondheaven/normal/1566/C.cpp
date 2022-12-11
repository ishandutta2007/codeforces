#include <bits/stdc++.h>
const int MaxN = 100123;

int n, f[MaxN];
char a[MaxN], b[MaxN];

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%s%s", &n, a + 1, b + 1);
		std::fill(f, f + n + 1, 0);
		int l[2] = {0, 0};
		for(int i = 1; i <= n; ++i)
		{
			if(a[i] + b[i] == '0' + '1') f[i] = f[i - 1] + 2;
			else if(a[i] == '0' && b[i] == '0')
			f[i] = std::max(f[i - 1] + 1, (l[1] ? f[l[1] - 1] + 2 : 0));
			else f[i] = std::max(f[i - 1], (l[0] ? f[l[0] - 1] + 2 : 0));
			
			l[a[i] - '0'] = i;
			l[b[i] - '0'] = i;
		}
		printf("%d\n", f[n]);
	}
	return 0;
}