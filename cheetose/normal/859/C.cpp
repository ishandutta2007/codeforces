#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[50], sum[50];
int d[50][2];
int n;
int go(int N, int dec)
{
	if (N == n)return 0;
	int &ret = d[N][dec];
	if (ret != -1)return ret;
	if (dec == 1)
	{
		ret = max(a[N] + go(N + 1, 0), go(N + 1, 1));
	}
	else
	{
		ret = min(sum[n-1]-sum[N]+a[N] - go(N + 1, 1), sum[n - 1] - sum[N] - go(N + 1, 0));
	}
	return ret;
}
int main()
{
	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		sum[i] =sum[i-1]+ a[i];
	}
	printf("%d %d", sum[n-1] - go(0, 1), go(0, 1));
}