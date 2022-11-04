#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

long long c[(int)1e5];
int main()
{
	int n, x;
	scanf("%d %d", &n, &x);
	for(int i = 0; i < n; i++)
		scanf("%I64d", &c[i]);
	sort(c, c + n);
	long long ans = 0;
	for(int i = 0; i < n; i++)
	{
		ans += c[i] * x;
		x = max(x - 1, 1);
	}
	printf("%I64d", ans);
	return 0;
}