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

const int N = 305;

int n;
char s[N][N], f[N][N];

void work()
{
	int cnt = 0;
	read(n);
	for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		cnt += s[i][j] != '.';
	for (int t = 0; t < 3; t++)
	{
		int cc = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				char c;
				if (s[i][j] == '.') c = '.';
				else if (s[i][j] == 'X') c = (i + j + t) % 3 ? 'X' : 'O';
				else c = (i + j + t + 1) % 3 ? 'O' : 'X';
				if (c != s[i][j]) cc++; f[i][j] = c;
			}
		if (cc <= cnt / 3)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++) putchar(f[i][j]);
				puts("");
			}
			return;
		}
	}
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}