#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
vector<int>pat[100000];
vector<int>ko[100000];
bool flag[100000];
void dfs(int node)
{
	flag[node] = true;
	for (int i = 0; i < pat[node].size(); i++)
	{
		if (!flag[pat[node][i]])
		{
			ko[node].push_back(pat[node][i]);
			dfs(pat[node][i]);
		}
	}
}
ll dat[100000];
typedef pair<ll, ll>pii;
ll gcd(ll a, ll b)
{
	if (a == 0)return b;
	if (b == 0)return a;
	for (;;)
	{
		if (a < b)swap(a, b);
		a %= b;
		if (a == 0)return b;
	}
}
pii calc(int node)
{
	if (ko[node].empty())return make_pair(1LL, dat[node]);
	ll lcm = 1, mini = 2000000000000000000LL;
	for (int i = 0; i < ko[node].size(); i++)
	{
		pii z = calc(ko[node][i]);
		mini = min(mini, z.second);
		ll g = gcd(lcm, z.first);
		if (g > 0)lcm = lcm / g*z.first;
		else lcm = 0;
		if (lcm > 10000000000000LL)lcm = 0;
	}
	if (lcm*ko[node].size() > 10000000000000LL)lcm = 0;
	//printf("%d %d\n", node + 1, lcm);
	if (lcm > 0)return make_pair(lcm*ko[node].size(), mini / lcm*lcm*ko[node].size());
	else return make_pair(0LL, 0LL);
}
int main()
{
	int num;
	scanf("%d", &num);
	ll sum = 0;
	for (int i = 0; i < num; i++)scanf("%I64d", &dat[i]), sum += dat[i];
	for (int i = 0; i < num - 1; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
	}
	dfs(0);
	printf("%I64d\n", sum - calc(0).second);
}