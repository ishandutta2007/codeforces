#include <bits/stdc++.h>

typedef long long ll;

const int N = 1005;
const ll INF = 1e18;

ll K, f[N][12];
int lst[N][12], cnt[12];
char s[] = "codeforces";

int main()
{
	std::cin >> K;
	f[0][0] = 1;
	for (int i = 1; ; i++)
	{
		for (int j = 1; j <= 10 && j <= i; j++)
		{
			ll tmp = 0;
			for (int k = 1; k <= i; k++)
			{
				if (j == 1 && k != i) continue;
				if (j - 1 > i - k) continue;
				ll fs = f[i - k][j - 1] * k;
				if (fs > tmp) tmp = fs, lst[i][j] = k;
			}
			f[i][j] = tmp < INF ? tmp : INF;
		}
		if (i >= 10 && f[i][10] >= K)
		{
			int cur = i, now = 10;
			while (cur) cnt[now] = lst[cur][now], cur -= lst[cur][now], now--;
			for (int j = 1; j <= 10; j++)
				for (int k = 0; k < cnt[j]; k++)
					putchar(s[j - 1]);
			puts("");
			return 0;
		}
	}
	return 0;
}