#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
ll d[100000];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%I64d", &d[i]);
	for (int i = 0; i < num - 1; i++)d[i] = abs(d[i] - d[i + 1]);
	num--;
	ll maxi = -1000000000000000000LL;
	ll n1 = 0, n2 = -1000000000000000000LL;
	for (int i = 0; i < num; i++)
	{
		if (i % 2 == 0)
		{
			n1 = max(n1, 0LL);
			n1 += d[i];
			n2 -= d[i];
		}
		else
		{
			n2 = max(n2, 0LL);
			n1 -= d[i];
			n2 += d[i];
		}
		maxi = max(maxi, max(n1, n2));
	}
	printf("%I64d\n", maxi);
}