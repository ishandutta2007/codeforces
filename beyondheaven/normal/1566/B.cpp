#include <bits/stdc++.h>
const int MaxN = 100123;

int n, f[MaxN];
char s[MaxN];
int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%s", s + 1);
		n = strlen(s + 1);
		
		int l[2] = {0, 0};
		for(int i = 1; i <= n; ++i)
		{
			f[i] = std::min(2, f[l[(s[i] - '0') ^ 1]] + ((s[i] - '0') ^ 1));
			l[s[i] - '0'] = i;
		}
		printf("%d\n", f[n]);
	}
	return 0;
}