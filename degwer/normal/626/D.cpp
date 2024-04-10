#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll dat[10001];
ll ans[10001];
int main()
{
	int num;
	scanf("%d", &num);
	vector<int>v;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		v.push_back(z);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			dat[v[j] - v[i]]++;
		}
	}
	for (int i = 0; i <= 5000; i++)
	{
		for (int j = 0; j <= 5000; j++)
		{
			ans[i + j] += dat[i] * dat[j];
		}
	}
	ll r = 0;
	ll now = 0;
	for (int i = 0; i <= 10000; i++)
	{
		r += dat[i] * now;
		now += ans[i];
	}
	ll t = (num*(num - 1)) / 2;
	printf("%.15lf\n", double(r) / double(t*t*t));
}