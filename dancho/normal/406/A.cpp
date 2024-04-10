#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[1024][1024];

int cnt[1024][4][4];

int ans = 0;
int d = 0;

int lo;
char out[1<<20];

int main()
{
	int n, q;
	scanf("%d", &n);
	memset(cnt, 0, sizeof(cnt));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; ++j)
		{
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i != j)
			{
				++cnt[i][ a[i][j] ][ a[j][i] ];
			}
		}
		d += a[i][i];
	}

	d = d & 1;

	for (int i = 1; i <= n; ++i)
	{
		ans += cnt[i][1][1];
		//~ printf("CNT %d %d\n", i, cnt[i][1][1]);
	}

	scanf("%d", &q);
	for (int i = 1; i <= q; ++i)
	{
		int tp;
		scanf("%d", &tp);
		if (tp == 1)
		{
			// flip row
			int r;
			scanf("%d", &r);
			d = 1 - d;

			swap(cnt[r][0][0], cnt[r][1][0]);
			ans -= cnt[r][1][1];
			swap(cnt[r][0][1], cnt[r][1][1]);
			ans += cnt[r][1][1];
		}
		else if (tp == 2)
		{
			// flip col
			int c;
			scanf("%d", &c);
			d = 1 - d;

			swap(cnt[c][0][0], cnt[c][0][1]);
			ans -= cnt[c][1][1];
			swap(cnt[c][1][0], cnt[c][1][1]);
			ans += cnt[c][1][1];
		}
		else if (tp == 3)
		{
			ans = 0;
			//~ printf("AA %d %d\n", d, ans);
			if ((ans + d) & 1)
				out[lo++] = '1';
			else
				out[lo++] = '0';
		}
	}
	out[lo] = '\0';
	printf("%s\n", out);

	return 0;
}