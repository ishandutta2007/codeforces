#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll get(vector<int>v, int t)
{
	ll ret = 0;
	for (int i = 0; i < v.size(); i++)
	{
		ret *= t;
		ret += v[i];
	}
	return ret;
}
ll solve()
{
	int num, b;
	scanf("%d%d", &num, &b);
	vector<int>v;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		v.push_back(z);
	}
	return get(v, b);
}
int main()
{
	ll a = solve(), b = solve();
	if (a < b)printf("<\n");
	else if (a == b)printf("=\n");
	else printf(">\n");
}