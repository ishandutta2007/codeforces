#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int a[1<<21];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	sort(a, a+n);
	int l, r, m;
	l = 0; r = n+1;
	while (l+1 < r)
	{
		m = (l+r)/2;
		if (m-1 >= n-m)
		{
			r = m;
			continue;
		}
		int i;
		for (i = 0; i < m; ++i)
		{
			if (a[i]*2 > a[n-m+i])
			{
				break;
			}
		}
		if (i < m)
			r = m;
		else
			l = m;
	}
	printf("%d\n", n-l);
	return 0;
}