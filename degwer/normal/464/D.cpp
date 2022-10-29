#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
#define SIZE 262144
#define B 1000
double pr[2][B + 1];
double ex[2][B + 1];
double gv[100001];
double eps = 1e-15;
int main()
{
	int num, kai;
	scanf("%d%d", &num, &kai);
	int cur = 0;
	pr[0][1] = 1.0;
	for (int i = 0; i <= num; i++)
	{
		for (int j = 1; j <= B; j++)
		{
			pr[1 - cur][j] = pr[cur][j - 1] / double(j) + pr[cur][j] * double(j) / double(j + 1);
			ex[1 - cur][j] = ex[cur][j - 1] / double(j) + pr[cur][j - 1] / double(j)*double(j - 1) + ex[cur][j] * double(j) / double(j + 1) + pr[cur][j] * double(j) / 2.0;
			if (pr[1 - cur][j] < eps)pr[1 - cur][j] = 0;
			if (ex[1 - cur][j] < eps)ex[1 - cur][j] = 0;
		}
		for (int j = 0; j <= B; j++)
		{
			gv[i] += ex[cur][j];
			pr[cur][j] = ex[cur][j] = 0;
		}
		cur = 1 - cur;
	}
	if (kai == 1)
	{
		printf("%.20lf\n", gv[num]);
		return 0;
	}
	long double now = (log(kai - 1) - log(kai))*double(num);
	double ans = 0.0;
	for (int i = 0; i <= num; i++)
	{
		ans += exp(now)*double(kai)*gv[i];
		if (i == num)break;
		now -= log(kai - 1);
		now += log(num - i);
		now -= log(i + 1);
	}
	printf("%.20lf\n", ans);
}