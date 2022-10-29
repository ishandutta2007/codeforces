#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll get(ll a, ll b)
{
	a /= b;
	if (b % 2 == 1)
	{
		return a % 2;
	}
	int t = a % (b + 1);
	return t % 2;
}
int main()
{
	int data;
	scanf("%d", &data);
	for (int p = 0; p < data; p++)
	{
		ll a, b;
		scanf("%I64d%I64d", &a, &b);
		vector<ll>vec;
		for (;;)
		{
			if (a < b)swap(a, b);
			if (b == 0)break;
			vec.push_back(get(a, b));
			a %= b;
		}
		reverse(vec.begin(), vec.end());
		int now = 0;
		for (int i = 0; i < vec.size(); i++)
		{
			if (now == 0)now = 1;
			else
			{
				if (vec[i] % 2 == 0)now = 1;
				else now = 0;
			}
		}
		if (now == 0)printf("Second\n");
		else printf("First\n");
	}
}