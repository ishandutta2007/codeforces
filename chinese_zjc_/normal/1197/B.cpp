#include <cstdio>
using namespace std;
int n, m, num[200001];
inline void rd(int &ddd)
{
	char tmp = getchar();
	ddd = 0;
	while ('0' > tmp && tmp < '9')
	{
		tmp = getchar();
	}
	while ('0' <= tmp && tmp <= '9')
	{
		ddd = (ddd << 3) + (ddd << 1) + (tmp ^ 48);
		tmp = getchar();
	}
}
int main()
{
	rd(n);
	for (int i = 1; i <= n; ++i)
	{
		rd(num[i]);
	}
	for (int i = 1; i <= n; ++i)
	{
		if (num[i] == n)
		{
			m = i;
			break;
		}
	}
	for (int i = 1; i < m; ++i)
	{
		if (num[i] > num[i + 1])
		{
			puts("NO");
			return 0;
		}
	}
	for (int i = n; i > m; --i)
	{
		if (num[i] > num[i - 1])
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}