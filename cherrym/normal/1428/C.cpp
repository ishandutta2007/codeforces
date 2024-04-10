#include <bits/stdc++.h>

const int N = 2e5 + 5;

int n;
char s[N];

void work()
{
	scanf("%s", s + 1); n = strlen(s + 1);
	int cnta = 0, cntb = 0;
	for (int i = n; i >= 1; i--)
		if (s[i] == 'B') cntb++;
		else if (cntb) cntb--;
		else cnta++;
	printf("%d\n", cnta + cntb % 2);
}

int main()
{
	int T; std::cin >> T;
	while (T--) work();
	return 0;
}