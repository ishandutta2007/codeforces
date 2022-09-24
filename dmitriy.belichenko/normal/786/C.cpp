#include <bits/stdc++.h>
using namespace std;

int dat[100005];
int ans[100005];
int ttt[100005];
bool yes[100005];
int tt;
int n;

bool check(int group, int color)
{
	int res = 1;
	int now = 0;
	++tt;
	for (int i = 0; i < n; i++)
	{
		int d = dat[i];
		if (ttt[d] != tt)
		{
			ttt[d] = tt;
			yes[d] = false;
		}

		if (yes[d] == false)
		{
			if (now == color)
			{
				if (++res > group) return false;
				ttt[d] = ++tt;
				now = 0;
			}
			++now;
		}

		yes[d] = true;
	}
	return true;
}

void divide_and_conquer(int l, int r, int lo, int hi)
{
	if (l > r) return;

	int mid = (l + r) / 2;
	int ll = lo, hh = min(hi - 1, (n + mid - 1) / mid), res = min(hi, (n + mid - 1) / mid);
	while (ll <= hh)
	{
		int m2 = (ll + hh) / 2;
		if (check(m2, mid))
		{
			res = m2;
			hh = m2 - 1;
		}
		else ll = m2 + 1;
	}
	ans[mid] = res;
	divide_and_conquer(l, mid - 1, res, hi);
	divide_and_conquer(mid + 1, r, lo, res);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &dat[i]);

	divide_and_conquer(1, n, 1, n);

	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	printf("\n");
}