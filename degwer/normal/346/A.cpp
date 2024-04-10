#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int gcd(int a, int b)
{
	if (a == 0)return b;
	if (b == 0)return a;
	for (;;)
	{
		if (a < b)swap(a, b);
		a %= b;
		if (a == 0)return b;
	}
}
int main()
{
	int num;
	scanf("%d", &num);
	int now = 0, maxi = 0;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		now = gcd(now, z);
		maxi = max(maxi, z);
	}
	if ((maxi / now - num) % 2 == 1)printf("Alice\n");
	else printf("Bob\n");
}