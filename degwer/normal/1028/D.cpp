#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
int main()
{
	int num;
	scanf("%d", &num);
	priority_queue<int>q1, q2;
	q1.push(-2020202020), q2.push(-2020202020);
	vector<int>v;
	ll ans = 1;
	for (int i = 0; i < num; i++)
	{
		char za[10];
		int val;
		scanf("%s%d", za, &val);
		if (za[1] == 'D')
		{
			if (q1.top() >= val)q1.push(val);
			else if (-q2.top() <= val)q2.push(-val);
			else v.push_back(val);
		}
		else
		{
			if (q1.top() >= val)
			{
				if (q1.top() == val)q1.pop();
				else ans = 0;
			}
			else if (-q2.top() <= val)
			{
				if (-q2.top() == val)q2.pop();
				else ans = 0;
			}
			else
			{
				ans = ans * 2 % mod;
			}
			for (int t = 0; t < v.size(); t++)
			{
				if (v[t] < val)q1.push(v[t]);
				else if (v[t]>val)q2.push(-v[t]);
			}
			v.clear();
		}
	}
	printf("%I64d\n", ans*(v.size() + 1) % mod);
}