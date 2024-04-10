#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
ll coo[100000], cst[100000];
#define INF 3000000000000000000LL
ll mini[10000];
bool flag[10000];
int main()
{
	ll gen;
	int num, query;
	ll mod;
	scanf("%I64d%d%d%I64d", &gen, &num, &query, &mod);
	gen--;
	for (int i = 0; i < num; i++)scanf("%I64d%I64d", &coo[i], &cst[i]), coo[i]--;
	for (int i = 0; i < mod; i++)mini[i] = INF;
	mini[0] = 0;
	set<pii>se;
	for (int i = 0; i < num; i++)if (coo[i] % mod == 0)se.insert(make_pair(cst[i], -i));
	for (int p = 0; p < query; p++)
	{
		int za;
		scanf("%d", &za);
		if (za == 2)
		{
			int zb;
			ll zc;
			scanf("%d%I64d", &zb, &zc);
			zb--;
			if (se.find(make_pair(cst[zb], -zb)) != se.end())
			{
				se.erase(make_pair(cst[zb], -zb));
				se.insert(make_pair(cst[zb] - zc, -zb));
			}
			cst[zb] -= zc;
		}
		else if (za == 3)
		{
			if (se.empty())printf("0\n");
			else
			{
				set<pii>::iterator it = se.end();
				it--;
				pii z = *it;
				printf("%I64d\n", (*it).first);
				cst[-(*it).second] = -1;
				se.erase(it);
			}
		}
		else
		{
			ll zb;
			scanf("%I64d", &zb);
			priority_queue<pii>que;
			for (int i = 0; i < mod; i++)que.push(make_pair(-mini[i], i));
			fill(flag, flag + mod, false);
			for (;;)
			{
				if (que.empty())break;
				pii z = que.top();
				que.pop();
				if (flag[z.second])continue;
				flag[z.second] = true;
				if (mini[(z.second + zb) % mod]>mini[z.second] + zb)
				{
					mini[(z.second + zb) % mod] = mini[z.second] + zb;
					que.push(make_pair(z.first - zb, (z.second + zb) % mod));
				}
			}
			for (int i = 0; i < num; i++)
			{
				if (mini[coo[i] % mod] <= coo[i] && cst[i] != -1)se.insert(make_pair(cst[i], -i));
			}
		}
	}
}