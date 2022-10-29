#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
double eps = 1e-9;
typedef pair<double, double>pdd;
int main()
{
	int num;
	double r;
	scanf("%d%lf", &num, &r);
	vector<pdd>vec;
	for (int i = 0; i < num; i++)
	{
		double x;
		scanf("%lf", &x);
		double maxi = r;
		for (int j = 0; j < i; j++)
		{
			double d = fabs(x - vec[j].first);
			if (d > r*2 + eps)continue;
			maxi = max(maxi, vec[j].second + sqrt(max(0.0, r*r*4 - d*d)));
		}
		printf("%.10lf\n", maxi);
		vec.push_back(make_pair(x, maxi));
	}
}