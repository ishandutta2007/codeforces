#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	int num;
	scanf("%d", &num);
	vector<ll>v;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		v.push_back(z);
	}
	sort(v.begin(), v.end());
	ll ans = 0;
	for (int i = 0; i < num; i++)ans += v[i] * (i + 2);
	printf("%I64d\n", ans - v[v.size() - 1]);
}