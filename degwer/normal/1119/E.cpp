#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll d[301010];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%I64d", &d[i]);
	ll r = 0, s = 0;
	for (int i = 0; i < num; i++)
	{
		ll z = min(d[i] / 2, s);
		s -= z, d[i] -= z * 2, r += z;
		r += d[i] / 3;
		s += d[i] % 3;
	}
	printf("%I64d\n", r);
}