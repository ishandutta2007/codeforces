#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
typedef pair<int, int>pii;
typedef pair<int, pii>pi3;
typedef long long ll;
ll mod = 1000000009;
int main()
{
	int num;
	scanf("%d", &num);
	set<pii>se;
	map<pii,int>ma;
	map<pii, int>dat;
	for (int i = 0; i < num; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		se.insert(make_pair(za, zb));
		dat[make_pair(za, zb)] = i;
	}
	set<pii>::iterator it = se.begin();
	for (;;)
	{
		if (it == se.end())break;
		int cnt = 0;
		for (int i = -1; i <= 1; i++)
		{
			if (se.find(make_pair((*it).first + i, (*it).second - 1)) != se.end())cnt++;
		}
		ma[*it] = cnt;
		it++;
	}
	set<pi3>now;
	it = se.begin();
	for (;;)
	{
		if (it == se.end())break;
		int cnt = 0;
		for (int i = -1; i <= 1; i++)
		{
			if (ma[make_pair((*it).first + i, (*it).second + 1)] == 1)cnt++;
		}
		if (cnt == 0)now.insert(make_pair(dat[*it], *it));
		it++;
	}
	ll ans = 0;
	for (int p = 0; p < num; p++)
	{
		ans *= num;
		set<pi3>::iterator it2 = now.begin();
		/*for (;;)
		{
			if (it2 == now.end())break;
			printf("-  %d\n", (*it2).first);
			it2++;
		}*/
		if (p % 2 == 0)
		{
			it2 = now.end();
			it2--;
		}
		else it2 = now.begin();
		//printf("%d %d %d\n", (*it2).first, (*it2).second.first, (*it2).second.second);
		ans += (*it2).first;
		ans %= mod;
		pii z = (*it2).second;
		now.erase(it2);
		se.erase(z);
		ma[z] = 0;
		for (int i = -1; i <= 1; i++)
		{
			if (se.find(make_pair(z.first + i, z.second + 1)) != se.end())ma[make_pair(z.first + i, z.second + 1)]--;
		}
		for (int i = -2; i <= 2;i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				int tx = z.first + i, ty = z.second + j;
				if (se.find(make_pair(tx, ty)) == se.end())continue;
				if (now.find(make_pair(dat[make_pair(tx, ty)], make_pair(tx, ty))) != now.end())
				{
					now.erase(make_pair(dat[make_pair(tx, ty)], make_pair(tx, ty)));
				}
				int cnt = 0;
				for (int k = -1; k <= 1; k++)
				{
					if (ma[make_pair(tx + k, ty + 1)] == 1)cnt++;
				}
				if (cnt == 0)now.insert(make_pair(dat[make_pair(tx, ty)], make_pair(tx, ty)));
			}
		}
	}
	printf("%I64d\n", ans);
}