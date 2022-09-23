#include <stdio.h>

char s[1000005];
int st[1000005], ed[1000005];

int main()
{
	int n, k;	scanf("%d %d", &n, &k);

	scanf("%s", s);

	for(int i = 0; i < 26; i++)
	{
		int start = -1, end = -1;
		for(int j = 0; j < n; j++)
		{
			if(s[j] != i + 'A')	continue;
			if(start == -1)	start = j;
			end = j;
		}
		st[start]++;	ed[end]--;
	}

	int opened = 0;
	for(int i = 0; i < n; i++)
	{
		opened += st[i];
		if(opened > k)
		{
			puts("YES");
			return 0;
		}
		opened += ed[i];
	}
	puts("NO");

	return 0;
}