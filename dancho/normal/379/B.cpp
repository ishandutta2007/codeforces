#include <cstdio>
#include <cstring>

int n, a[512];
char op[1<<20];
int l;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	l = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < a[i]; ++j)
		{
			if (i+1 < n)
			{
				op[l++] = 'R';
				op[l++] = 'L';
			}
			else
			{
				op[l++] = 'L';
				op[l++] = 'R';
			}
			op[l++] = 'P';
		}
		if (i+1 < n)
			op[l++] = 'R';
	}
	op[l] = '\0';
	printf("%s\n", op);
	return 0;
}