#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long double ld;
int main()
{
	int num;
	scanf("%d", &num);
	vector<ld>v;
	for (int i = 0; i < num; i++)
	{
		ld z;
		scanf("%Lf", &z);
		v.push_back(z);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	ld maxi = 0.0;
	ld n1 = 0.0, n0 = 1.0;
	for (int i = 0; i < num; i++)
	{
		n1 = n1*((ld)1.0 - v[i]) + n0*v[i];
		n0 *= ((ld)1.0 - v[i]);
		maxi = max(maxi, n1);
	}
	printf("%.20Lf\n", maxi);
}