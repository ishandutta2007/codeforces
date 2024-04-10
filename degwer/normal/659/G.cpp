#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
int main()
{
	int num;
	scanf("%d", &num);
	vector<ll>vec;
	vec.push_back(1);
	for (int i = 0; i < num; i++)
	{
		ll z;
		scanf("%I64d", &z);
		vec.push_back(z);
	}
	vec.push_back(1);
	ll ans = 0, c = 0;
	for (int i = 1; i <= num; i++)
	{
		ans += c*(min(vec[i - 1], vec[i]) - 1);
		ans += vec[i] - 1;
		ans %= mod;
		c *= min(vec[i - 1], min(vec[i], vec[i + 1])) - 1;
		c += min(vec[i], vec[i + 1]) - 1;
		c %= mod;
	}
	printf("%I64d\n", ans);
}