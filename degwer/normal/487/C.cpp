#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod;
#define SIZE 200000
ll inv[SIZE + 1];
ll kai[SIZE + 1];
ll invkai[SIZE + 1];
void invinit()
{
	inv[1] = 1;
	for (int i = 2; i < mod; i++)
	{
		inv[i] = mod - (mod / i)*inv[mod%i] % mod;
	}
	kai[0] = invkai[0] = 1;
	for (int i = 1; i < mod; i++)
	{
		kai[i] = kai[i - 1] * i%mod;
		invkai[i] = invkai[i - 1] * inv[i] % mod;
	}
}
int main()
{
	int num;
	scanf("%d", &num);
	if (num == 1)
	{
		printf("YES\n1\n");
		return 0;
	}
	if (num == 4)
	{
		printf("YES\n1\n3\n2\n4\n");
		return 0;
	}
	for (int i = 2; i < num; i++)
	{
		if (num%i == 0)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	mod = num;
	invinit();
	printf("1\n");
	for (int i = 1; i <= num - 2; i++)
	{
		printf("%lld\n", (i + 1)*inv[i] % mod);
	}
	printf("%d\n", num);
}