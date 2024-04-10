#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
vector<pii>get(ll num)
{
	vector<pii>vec;
	for (ll i = 2;; i++)
	{
		if (i*i > num)break;
		if (num%i != 0)continue;
		vec.push_back(make_pair(i, 0));
		for (;;)
		{
			if (num%i != 0)break;
			vec[vec.size() - 1].second++;
			num /= i;
		}
	}
	if (num != 1)vec.push_back(make_pair(num, 1));
	return vec;
}
int main()
{
	ll num,kai;
	scanf("%I64d%I64d", &num, &kai);
	kai = (kai + 1) / 2;
	for (int i = 0; i < min(kai, 1000LL); i++)
	{
		vector<pii>vec = get(num);
		ll t = 1;
		for (int j = 0; j < vec.size(); j++)
		{
			t *= vec[j].first - 1;
			for (int k = 0; k < vec[j].second - 1; k++)t *= vec[j].first;
		}
		num = t;
	}
	printf("%I64d\n", num % 1000000007);
}