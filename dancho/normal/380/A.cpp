#include <cstdio>
#include <cstring>

int n, m;

int tp[1<<20];
int x[1<<20], l[1<<20], c[1<<20];
long long len[1<<20];

int f[1<<20];

int main()
{
	scanf("%d", &m);
	len[0] = 0;
	f[0] = 0;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &tp[i]);
		if (tp[i] == 1)
		{
			scanf("%d", &x[i]);
			len[i] = len[i-1] + 1;
			if (len[i] < (1<<19))
			{
				f[len[i]] = x[i];
			}
		}
		else
		{
			scanf("%d %d", &l[i], &c[i]);
			len[i] = len[i-1] + (long long) l[i] * c[i];
			for (long long j = len[i-1] + 1; j < (1<<19) && j <= len[i-1] + l[i]*c[i]; ++j)
			{
				f[j] = f[(j - len[i-1] - 1)%l[i] + 1];
				//~ printf("PUTF %lld %d :: %d %d\n", j, f[j], l[i], c[i]);
			}
		}
	}
	
	int cr = 0;
	long long pos = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%I64d", &pos);
		while (pos > len[cr])
		{
			++cr;
		}
		
		if (tp[cr] == 1)
			printf("%d\n", x[cr]);
		else
		{
			printf("%d\n", f[(pos - len[cr-1] - 1)%l[cr] + 1]);
		}
	}
	return 0;
}