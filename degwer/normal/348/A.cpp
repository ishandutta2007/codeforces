#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	int num;
	scanf("%d", &num);
	ll sum = 0, maxi = 0;
	for (int i = 0; i < num; i++)
	{
		ll z;
		scanf("%I64d", &z);
		sum += z, maxi = max(maxi, z);
	}
	printf("%I64d\n", max(maxi, (sum + num - 2) / (num - 1)));
}