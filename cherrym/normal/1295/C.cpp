#include <bits/stdc++.h>

const int N = 1e5 + 5;

int n, m, nxt[N][26], at[26];
char s[N], t[N];

void work()
{
	int ans = 0;
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1); m = strlen(t + 1);
	memset(at, 0, sizeof(at));
	for (int i = n; i >= 1; i--)
	{
		for (int c = 0; c < 26; c++) nxt[i][c] = at[c];
		at[s[i] - 'a'] = i;
	}
	for (int i = 1, j = 0; i <= m; i++)
	{
		int c = t[i] - 'a';
		if (!j || !nxt[j][c])
		{
			ans++; j = at[c];
			if (!j) return (void) puts("-1");
		}
		else j = nxt[j][c];
	}
	printf("%d\n", ans);
}

int main()
{
	int T; std::cin >> T;
	while (T--) work();
	return 0;
}