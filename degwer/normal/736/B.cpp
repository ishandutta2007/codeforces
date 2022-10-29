#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	scanf("%lld", &n);
	int t = n % 2;
	bool f = true;
	for (ll i = 2;; i++)
	{
		if (i*i > n)break;
		if (n%i == 0)f = false;
	}
	bool f2 = true;
	for (ll i = 2;; i++)
	{
		if (i*i > n - 2)break;
		if ((n - 2)%i == 0)f2 = false;
	}
	if (f)printf("1\n");
	else if (t == 0)printf("2\n");
	else if(f2)printf("2\n");
	else printf("3\n");
}