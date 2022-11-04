#include <cstdio>

int main()
{
	int n, s;
	scanf("%d%d", &n, &s);
	int maxx = -1;
	for(int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if((b != 0) && (a < s))
			if(100 - b > maxx)
					maxx = 100 - b;
		if((b == 0) && (a <= s) && (maxx == -1))
			maxx = 0;
	}
	printf("%d", maxx);
	return 0;
}