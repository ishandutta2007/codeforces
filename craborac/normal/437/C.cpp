#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

int mas[1000];
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &mas[i]);
	}
	long long ans = 0;
	for(int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		ans += min(mas[a - 1], mas[b - 1]);
	}
	printf("%I64d", ans);
	return 0;
}