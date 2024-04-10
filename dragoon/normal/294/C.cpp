#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> V;

typedef __int64 LL;
LL MOD = 1000000007;

LL BIGMOD(LL a, LL b)
{
	if(b==0) return 1;
	LL x = BIGMOD(a, b/2);
	x = (x*x)%MOD;
	if(b&1) x = (x*a)%MOD;
	return x;
}

LL fact[1004];

int main()
{
	LL ans;
	int i, n, m, a, sz;
	LL now;

	fact[0] = 1;
	for(i = 1; i <= 1000; i++)
		fact[i] = (fact[i-1]*i)%MOD;

	scanf("%d%d", &n, &m);
	for(i = 0; i < m; i++)
	{
		scanf("%d", &a);
		V.push_back(a);
	}

	sort(V.begin(), V.end());

	now = 0;
	now += V[0] - 1;
	now += n - V[m-1];
	ans = 1;
	ans = (ans * BIGMOD( fact[V[0]-1] , MOD - 2 ))%MOD;
	ans = (ans * BIGMOD( fact[n-V[m-1]] , MOD - 2 ))%MOD;

	for(i = 1; i < m; i++)
	{
		if(V[i]==V[i-1]+1) continue;

		sz = V[i] - V[i-1] - 1;
		ans = (ans * BIGMOD(fact[sz], MOD-2))%MOD;
		ans = (ans * BIGMOD(2, sz-1))%MOD;
		now += sz;
	}

	ans = (ans * fact[now])%MOD;

	printf("%I64d\n", ans);

	return 0;
}