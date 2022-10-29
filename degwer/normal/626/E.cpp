#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll rui[200001];
int main()
{
	int num;
	scanf("%d", &num);
	vector<ll>vec;
	for (int i = 0; i < num; i++)
	{
		ll z;
		scanf("%I64d", &z);
		vec.push_back(z);
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < num;i++)
	{
		rui[i + 1] = rui[i] + vec[i];
	}
	ll nb = 0, ns = 1;
	ll r = 0, rr = 0;
	for (ll i = 1; i < num-1; i++)
	{
		ll beg = 1, end = min(i, num - i - 1);
		for (;;)
		{
			if (beg == end)break;
			ll med = (beg + end+1) / 2;
			if ((rui[i + 1] - rui[i - med] + rui[num] - rui[num - med])*(2LL)>(vec[i - med] + vec[num - med])*(med + med + 1))end = med-1;
			else beg = med;
		}
		ll b = rui[i + 1] - rui[i - beg] + rui[num] - rui[num - beg], s = beg + beg + 1;
		b -= s*vec[i];
		if (b*ns > nb*s)
		{
			nb = b;
			ns = s;
			r = i;
			rr = beg;
		}
	}
	printf("%I64d\n", rr + rr + 1);
	printf("%I64d", vec[r]);
	for (int i = 1; i <= rr; i++)printf(" %I64d %I64d", vec[num-i], vec[r - i]);
	printf("\n");
}