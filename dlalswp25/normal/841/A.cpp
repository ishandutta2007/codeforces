#include <stdio.h>

int cnt[128];
char s[105];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	scanf("%s", s);
	for(int i = 0; i < n; i++)
	{
		cnt[s[i]]++;
	}
	for(int i = 'a'; i <= 'z'; i++)
	{
		if(cnt[i] > k)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}