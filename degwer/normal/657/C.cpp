#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
int main()
{
	int num;
	ll gen;
	ll ca, cb;
	scanf("%d%I64d%I64d%I64d", &num, &gen, &ca, &cb);
	vector<ll>vec;
	for (int i = 0; i < num; i++)
	{
		ll z;
		scanf("%I64d", &z);
		z += 1000000000LL;
		vec.push_back(z);
	}
	sort(vec.begin(), vec.end());
	if (ca > cb * 5)ca = cb * 5;
	ll mini = 8000000000000000000LL;
	for (int p = 0; p < 5; p++)
	{
		priority_queue<ll>que;
		ll sum = 0;
		ll mi = 8000000000000000000LL;
		for (int i = 0; i < vec.size(); i++)
		{
			ll x = ((vec[i] + 4) / 5) * 5;
			que.push((x - vec[i]) * cb - ca*x / 5);
			sum += (x - vec[i])*cb - ca*x / 5;
			if (que.size() >= gen)
			{
				mi = min(mi, sum + (ca*x / 5)*gen);
				ll z = que.top();
				que.pop();
				sum -= z;
			}
		}
		mini = min(mini, mi);
		for (int i = 0; i < vec.size(); i++)vec[i]++;
	}
	printf("%I64d\n", mini);
}