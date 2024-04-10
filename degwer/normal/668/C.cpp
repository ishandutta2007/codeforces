#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
typedef long double ld;
typedef pair<ld, ld>pdd;
ld eps = 1e-18;
int main()
{
	int num;
	scanf("%d", &num);
	vector<ld>ma, mi;
	for (int i = 0; i < num; i++)
	{
		double z;
		scanf("%lf", &z);
		ma.push_back(z);
	}
	for (int i = 0; i < num; i++)
	{
		double z;
		scanf("%lf", &z);
		mi.push_back(z);
	}
	for (int i = 1; i < num; i++)ma[i] += ma[i - 1];
	for (int i = num - 2; i >= 0; i--)mi[i] += mi[i + 1];
	vector<pdd>vec;
	vec.push_back(make_pair(0.0, 0.0));
	for (int i = 0; i < num - 1; i++)
	{
		ld p = ma[i], q = mi[i + 1];
		ld root;
		if ((q - p - 1.0)*(q - p - 1.0) - p*4.0 <= eps)root = 0;
		else root = sqrt((q - p - 1.0)*(q - p - 1.0) - p*4.0);
		vec.push_back(make_pair((-(q - p - 1.0) - root) / 2.0, (-(q - p - 1.0) + root) / 2.0));
	}
	vec.push_back(make_pair(1.0, 1.0));
	for (int i = 0; i < num; i++)
	{
		if (i != 0)printf(" ");
		printf("%.20lf", double(vec[i + 1].first - vec[i].first));
	}
	printf("\n");
	vec.push_back(make_pair(1.0, 1.0));
	for (int i = 0; i < num; i++)
	{
		if (i != 0)printf(" ");
		printf("%.20lf", double(vec[i + 1].second - vec[i].second));
	}
	printf("\n");
}