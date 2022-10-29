#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
#define B 400
#define NB 300
int dat[NB][100001];
ll flag[NB];
ll x[100001];
ll now[100000];
ll mx[100000];
ll ver[100000];
ll las[100000];
void init(vector<pii>vec, int tt)
{
	fill(x, x + 100001, 0);
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].second == 0)continue;
		ll t = vec[i].first / vec[i].second, s = vec[i].first - t*vec[i].second;
		x[0] += vec[i].second;
		x[t] -= vec[i].second;
		x[t] += s;
		x[t + 1] -= s;
	}
	for (int i = 1; i <= 100000; i++)x[i] += x[i - 1];
	for (int i = 1; i <= 100000; i++)dat[tt][i] = dat[tt][i - 1] + x[i - 1];
}
void resolve(int b)
{
	if (flag[b] == -1)return;
	for (int i = b*B; i < (b + 1)*B; i++)
	{
		now[i] = 0;
		las[i] = flag[b];
	}
	flag[b] = -1;
}
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%I64d%I64d%I64d", &now[i], &mx[i], &ver[i]);
	for (int i = 0; i < num; i += B)
	{
		vector<pii>z;
		for (int j = i; j < i + B; j++)z.push_back(make_pair(mx[j], ver[j]));
		init(z, i / B);
		//for (int j = 0; j < 20; j++)printf("%d ", dat[i / B][j]); printf("\n");
	}
	fill(flag, flag + NB, -1);
	fill(las, las + 100000, 0);
	int query;
	scanf("%d", &query);
	for (int p = 0; p < query; p++)
	{
		ll zt;
		int zb, zc;
		scanf("%I64d%d%d", &zt, &zb, &zc);
		zb--;
		zc--;
		int a = zb / B, b = zc / B;
		resolve(a);
		resolve(b);
		ll ret = 0;
		if (a == b)
		{
			for (int i = zb; i <= zc; i++)
			{
				ret += min(mx[i], now[i] + ver[i] * (zt - las[i]));
				now[i] = 0;
				las[i] = zt;
			}
		}
		else
		{
			for (int i = zb; i < (a + 1)*B; i++)
			{
				ret += min(mx[i], now[i] + ver[i] * (zt - las[i]));
				now[i] = 0;
				las[i] = zt;
			}
			for (int i = a + 1; i <= b - 1; i++)
			{
				if (flag[i] == -1)
				{
					for (int j = i*B; j < (i + 1)*B; j++)
					{
						ret += min(mx[j], now[j] + ver[j] * (zt - las[j]));
						now[j] = 0;
					}
				}
				else
				{
					ret += dat[i][min(100000LL, zt - flag[i])];
				}
				flag[i] = zt;
			}
			for (int i = b*B; i <= zc; i++)
			{
				ret += min(mx[i], now[i] + ver[i] * (zt - las[i]));
				now[i] = 0;
				las[i] = zt;
			}
		}
		printf("%I64d\n", ret);
	}
}