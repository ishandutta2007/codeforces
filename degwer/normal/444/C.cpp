#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
#define B 320
#define NB 320
ll dat[120000];
bool flag[NB];
ll ans[120000];
ll ba[NB];
ll sa[NB];
ll now[NB];
void resolve(int s)
{
	if (!flag[s])return;
	flag[s] = false;
	for (int i = 0; i < B; i++)
	{
		ans[s*B + i] += ba[s];
		dat[s*B + i] = now[s];
	}
	ba[s] = 0;
}
void solve(int s, ll x)
{
	flag[s] = true;
	for (int i = 0; i < B; i++)
	{
		ans[s*B + i] += abs(x - dat[s*B + i]);
		sa[s] += abs(x - dat[s*B + i]);
		dat[s*B + i] = x;
	}
	now[s] = x;
}
void update(int lb, int ub, ll x)
{
	if (lb / B == ub / B)
	{
		resolve(lb / B);
		for (int i = lb; i <= ub; i++)ans[i] += abs(x - dat[i]), sa[i / B] += abs(x - dat[i]), dat[i] = x;
	}
	else
	{
		resolve(lb / B);
		for (int i = lb; i < (lb / B)*B + B; i++)ans[i] += abs(x - dat[i]), sa[i / B] += abs(x - dat[i]), dat[i] = x;
		for (int i = lb / B + 1; i <= ub / B - 1; i++)
		{
			if (!flag[i])solve(i, x);
			else ba[i] += abs(now[i] - x), sa[i] += abs(now[i] - x)*B, now[i] = x;
		}
		resolve(ub / B);
		for (int i = ub / B*B; i <= ub; i++)ans[i] += abs(x - dat[i]), sa[i / B] += abs(x - dat[i]), dat[i] = x;
	}
}
ll get(int lb, int ub)
{
	ll ret = 0;
	if (lb / B == ub / B)
	{
		resolve(lb / B);
		for (int i = lb; i <= ub; i++)ret += ans[i];
	}
	else
	{
		resolve(lb / B);
		for (int i = lb; i < (lb / B)*B + B; i++)ret += ans[i];
		for (int i = lb / B + 1; i <= ub / B - 1; i++)ret += sa[i];
		resolve(ub / B);
		for (int i = ub / B*B; i <= ub; i++)ret += ans[i];
	}
	return ret;
}
int main()
{
	int num, query;
	scanf("%d%d", &num, &query);
	for (int i = 1; i <= num; i++)dat[i] = i;
	for (int i = 0; i < query; i++)
	{
		int za, zb, zc;
		scanf("%d%d%d", &za, &zb, &zc);
		if (za == 1)
		{
			int zd;
			scanf("%d", &zd);
			update(zb, zc, zd);
		}
		else
		{
			printf("%I64d\n", get(zb, zc));
		}
		/*for (int j = 0; j <= num; j++)
		{
			if (!flag[j / B])printf("%I64d ", dat[j]);
			else printf("%I64d ", now[j / B]);
		}
		printf("\n");
		for (int j = 0; j <= num; j++)
		{
			if (!flag[j / B])printf("%I64d ", ans[j]);
			else printf("%I64d ", ans[j] + ba[j / B]);
		}
		printf("\n");
		for (int j = 0; j < 4; j++)printf("%I64d ", sa[j]); printf("\n");*/
	}
}