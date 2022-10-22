#include <cstdio>
#include <algorithm>
using namespace std;
int n, T, num[100001];
inline int min(int a, int b)
{
	return a < b ? a : b;
}
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
	rd(T);
	while (T > 0)
	{
		--T;
		rd(n);
		for (int i = 1; i <= n; ++i)
		{
			rd(num[i]);
		}
		sort(num + 1, num + 1 + n);
		printf("%d\n", min(num[n - 1] - 1, n - 2));
	}
	return 0;
}