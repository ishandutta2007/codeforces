#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ll a, b;
	scanf("%I64d%I64d", &a, &b);
	if (a == 0)
	{
		printf("%I64d\n", -b*b);
		for (int i = 0; i < b; i++)printf("x"); printf("\n");
	}
	else
	{
		ll maxi = -1000000000000000000LL;
		int rr = 0;
		for (int i = 1; i <= a; i++)
		{
			ll t = b / (i + 1);
			ll s = (ll)(i - 1) + (a - i + 1)*(a - i + 1) - t*t*(i + 1 - b % (i + 1)) - (t + 1)*(t + 1)*(b % (i + 1));
			if (s > maxi)
			{
				maxi = s;
				rr = i;
			}
		}
		printf("%I64d\n", maxi);
		vector<ll>va, vb;
		va.push_back(a - rr + 1);
		for (int i = 0; i < rr - 1; i++)va.push_back(1);
		for (int i = 0; i < b % (rr + 1); i++)vb.push_back(b / (rr + 1) + 1);
		for (int i = b % (rr + 1); i < rr + 1; i++)vb.push_back(b / (rr + 1));
		for (int i = 0; i < vb[0]; i++)printf("x");
		for (int i = 0; i < rr; i++)
		{
			for (int j = 0; j < va[i]; j++)printf("o");
			for (int j = 0; j < vb[i + 1]; j++)printf("x");
		}
		printf("\n");
	}
}