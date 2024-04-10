//  228

#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e4 + 1;
int f[11], a[11], d[11];
char ans[11][N];
int n, k, cnt;
char s[N];

signed main ()
{
	scanf ("%d %d", &n, &k);
	cin >> s;
	for (int i = 0; i <= n; i ++)
		f[s[i] - 48] ++;
	for (int i = 0; i <= 9; i ++)
	{
		int x = k - f[i], y;
		for (int j = 1; x > 0; j ++)
		{
			if (i + j <= 9)
			{
				y = min (x, f[i + j]);
				x -= y;
				a[i + j] = y;
				d[i] += y * j;
			}
			if (i - j >= 0)
			{
				y = min (x, f[i - j]);
				x -= y;
				a[i - j] = y;
				d[i] += y * j; 
			}
		}
		for (int j = 0; j < n; j ++)
		{
			x = s[j] - '0';
			if (x > i && a[x] > 0)
			{
				ans[i][j] = i + '0';
				a[x] --;
			}
		}
		for (int j = n - 1; j >= 0; j --)
		{
			x = s[j] - '0';
			if (x < i && a[x] > 0)
			{
				ans[i][j] = i + '0';
				a[x] --;
			}
		}
		for (int j = 0; j < n; j ++)
			if (!ans[i][j])
				ans[i][j] = s[j];
		if (d[i] < d[cnt])
			cnt = i;
		else if (d[i] == d[cnt] && strcmp (ans[i], ans[cnt]) < 0)
			cnt = i;
	}
	cout << d[cnt] << endl << ans[cnt] << endl;
	return 0;
}