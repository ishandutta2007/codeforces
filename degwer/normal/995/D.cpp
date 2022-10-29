#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll dat[1010101];
int main()
{
	int num, query;
	scanf("%d%d", &num, &query);
	ll s = 0;
	for (int i = 0; i < (1 << num); i++)scanf("%I64d", &dat[i]), s += dat[i];
	printf("%lf\n", double(s) / double(1 << num));
	for (int i = 0; i < query; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		s += zb - dat[za], dat[za] = zb;
		printf("%lf\n", double(s) / double(1 << num));
	}
}