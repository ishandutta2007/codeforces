#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

const int N = 1e5 + 5;

int n;
char a[N], b[N];
bool is[20][20];

void work()
{
	read(n); scanf("%s%s", a + 1, b + 1);
	memset(is, 0, sizeof(is));
	for (int i = 1; i <= n; i++)
		if (a[i] > b[i]) return (void) puts("-1");
		else if (a[i] < b[i]) is[a[i] - 'a'][b[i] - 'a'] = 1;
	int ans = 0;
	for (int i = 0; i < 20; i++)
	{
		int cnt = 0, fs = -1;
		for (int j = i + 1; j < 20; j++)
		{
			cnt += is[i][j]; bool v = 0;
			for (int k = 0; k < 20; k++) if (is[i][k] && (j == k || is[j][k])) v = 1;
			if (v && fs == -1) fs = j;
		}
		if (fs == -1) ans += cnt;
		else
		{
			ans++;
			for (int j = 0; j < 20; j++)
				if (j > fs) is[fs][j] |= is[i][j];
		}
	}
	printf("%d\n", ans);
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}