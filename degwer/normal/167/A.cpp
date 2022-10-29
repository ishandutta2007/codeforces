#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
int main()
{
	int num;
	scanf("%d", &num);
	double a, mok;
	scanf("%lf%lf", &a, &mok);
	double bt = 0.0;
	for (int p = 0; p < num; p++)
	{
		double t, v;
		scanf("%lf%lf", &t, &v);
		double zt = v / a;
		double ans;
		if (zt*zt*a / 2.0>mok)
		{
			ans = t + sqrt(mok*2.0 / a);
		}
		else
		{
			ans = t + zt + (mok - zt*zt*a / 2.0) / v;
		}
		bt = max(ans, bt);
		printf("%.10lf\n", bt);
	}
}