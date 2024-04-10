#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
double d[1000];
int main()
{
	int num, way;
	scanf("%d%d", &num, &way);
	for (int i = 0; i < num; i++)scanf("%lf", &d[i]);
	double maxi = 0;
	for (int i = 0; i < way; i++)
	{
		int za, zb, zc;
		scanf("%d%d%d", &za, &zb, &zc);
		za--, zb--;
		maxi = max(maxi, (d[za] + d[zb]) / double(zc));
	}
	printf("%.20lf\n", maxi);
}