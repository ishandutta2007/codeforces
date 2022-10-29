#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll rrrui[200000];
ll dp[101][100001];
vector<ll>cat;
ll rui[100001];
ll get(ll a, ll b)
{
	if (a > b)return 1000000000000000000LL;
	return cat[b - 1] * (b - a) - (rui[b] - rui[a]);
}
void calc(int beg, int end, int k, int lb, int ub)
{
	if (beg > end)return;
	int med = (beg + end) / 2;
	ll mini = 1000000000000000000LL;
	int rr = -1;
	for (int i = lb; i <= ub; i++)
	{
		if (mini > dp[k][i] + get(i, med))
		{
			mini = dp[k][i] + get(i, med);
			rr = i;
		}
	}
	dp[k + 1][med] = mini;
	calc(beg, med - 1, k, lb, rr);
	calc(med + 1, end, k, rr, ub);
}
int main()
{
	int len, num, gen;
	scanf("%d%d%d", &len, &num, &gen);
	for (int i = 1; i < len; i++)scanf("%I64d", &rrrui[i]), rrrui[i] += rrrui[i - 1];
	for (int i = 0; i < num; i++)
	{
		ll za, zb;
		scanf("%I64d%I64d", &za, &zb);
		za--;
		cat.push_back(zb - rrrui[za]);
	}
	sort(cat.begin(), cat.end());
	for (int i = 0; i < num; i++)rui[i + 1] = rui[i] + cat[i];
	for (int i = 0; i <= num; i++)dp[0][i] = 1000000000000000000LL;
	dp[0][0] = 0;
	for (int i = 0; i < gen; i++)calc(1, num, i, 0, num);
	printf("%I64d\n", dp[gen][num]);
}