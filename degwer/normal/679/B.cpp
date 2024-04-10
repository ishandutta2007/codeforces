#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll get(ll a)
{
	ll beg = 0, end = 1000000;
	for (;;)
	{
		if (beg == end)return beg;
		ll med = (beg + end + 1) / 2;
		if (med*med*med > a)end = med - 1;
		else beg = med;
	}
}
typedef pair<ll, ll>pii;
pii memo[100000];
pii dfs(ll now)
{
	if (now == 0)return make_pair(0, 0);
	if (now < 100000)
	{
		if (memo[now] != make_pair(0LL, 0LL))return memo[now];
	}
	ll t = get(now);
	pii r1 = dfs(now - t*t*t);
	r1.second += t*t*t;
	r1.first++;
	pii r2 = dfs(t*t*t - 1 - (t - 1)*(t - 1)*(t - 1));
	r2.second += (t - 1)*(t - 1)*(t - 1);
	r2.first++;
	pii ret = max(r1, r2);
	if (now < 100000)memo[now] = ret;
	return ret;
}
int main()
{
	ll a;
	scanf("%I64d", &a);
	pii r = dfs(a);
	printf("%I64d %I64d\n", r.first, r.second);
}