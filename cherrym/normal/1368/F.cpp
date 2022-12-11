#include <bits/stdc++.h>

const int N = 1005;

int n, k, tmp, tot, a[N];
bool cur[N], wxh[N];

int main()
{
	int x;
	std::cin >> n;
	if (n <= 3) return puts("0"), fflush(stdout), 0;
	for (int i = 2; i <= n; i++) if (n - (n + i - 1) / i - (i - 1) > tmp)
		tmp = n - (n + i - 1) / i - (i - 1), k = i;
	for (int i = 1; i <= n; i++) wxh[i] = i % k && i < n;
	while (1)
	{
		tot = 0;
		for (int i = 1; i <= n; i++) if (wxh[i] && !cur[i]) a[++tot] = i;
		int cur_k = std::min(k, tot); printf("%d ", cur_k);
		for (int i = 1; i <= cur_k; i++) printf("%d ", a[i]), cur[a[i]] = 1;
		puts(""); fflush(stdout);
		int cnt = 0;
		for (int i = 1; i <= n; i++) if (wxh[i] && !cur[i]) cnt++;
		scanf("%d", &x);
		for (int i = 0; i < cur_k; i++) cur[(x + i - 1) % n + 1] = 0;
		if (!cnt) return puts("0"), fflush(stdout), 0;
	}
	return 0;
}