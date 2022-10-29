#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 100000
class unionfind
{
public:
	int par[SIZE];
	int ran[SIZE];
	int ren[SIZE];
	void init()
	{
		for (int i = 0; i<SIZE; i++)
		{
			par[i] = i;
			ran[i] = 0;
			ren[i] = 1;
		}
	}
	int find(int a)
	{
		if (a == par[a])return a;
		else return par[a] = find(par[a]);
	}
	void unite(int a, int b)
	{
		a = find(a);
		b = find(b);
		if (a == b)return;
		if (ran[a]>ran[b])
		{
			par[b] = a;
			ren[a] += ren[b];
		}
		else
		{
			par[a] = b;
			ren[b] += ren[a];
		}
		if (ran[a] == ran[b])ran[b]++;
	}
};
unionfind uf;
typedef long long ll;
typedef pair<ll, ll>pii;
vector<pii>pat[100050];
vector<pii>ko[100050];
bool flag[100050];
ll dp1[100050];
ll dp2[100050];
void dfs(int node)
{
	if (flag[node])return;
	flag[node] = true;
	for (int i = 0; i < pat[node].size(); i++)
	{
		if (!flag[pat[node][i].first])
		{
			ko[node].push_back(pat[node][i]);
			dfs(pat[node][i].first);
		}
	}
}
void calc1(int node)
{
	ll maxi = 0;
	for (int i = 0; i < ko[node].size(); i++)calc1(ko[node][i].first);
	for (int i = 0; i < ko[node].size(); i++)maxi = max(maxi, dp1[ko[node][i].first] + ko[node][i].second);
	dp1[node] = maxi;
}
void calc2(int node)
{
	ll mx1 = 0, mx2 = 0;
	ll r1 = -1, r2 = -2;
	for (int i = 0; i < ko[node].size(); i++)
	{
		if (mx1 < dp1[ko[node][i].first] + ko[node][i].second)
		{
			mx2 = mx1;
			r2 = r1;
			mx1 = dp1[ko[node][i].first] + ko[node][i].second;
			r1 = i;
		}
		else if (mx2 < dp1[ko[node][i].first] + ko[node][i].second)
		{
			mx2 = dp1[ko[node][i].first] + ko[node][i].second;
			r2 = i;
		}
	}
	for (int i = 0; i < ko[node].size(); i++)
	{
		dp2[ko[node][i].first] = dp2[node] + ko[node][i].second;
		if (i != r1)dp2[ko[node][i].first] = max(dp2[ko[node][i].first], mx1 + ko[node][i].second);
		else dp2[ko[node][i].first] = max(dp2[ko[node][i].first], mx2 + ko[node][i].second);
	}
	for (int i = 0; i < ko[node].size(); i++)calc2(ko[node][i].first);
}
ll dat[100050];
ll now[100051];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num - 1; i++)
	{
		int za, zb;
		ll zc;
		scanf("%d%d%I64d", &za, &zb, &zc);
		za--;
		zb--;
		pat[za].push_back(make_pair(zb, zc));
		pat[zb].push_back(make_pair(za, zc));
	}
	fill(flag, flag + num, false);
	dfs(0);
	calc1(0);
	dp2[0] = 0;
	calc2(0);
	for (int i = 0; i < num; i++)
	{
		dat[i] = max(dp1[i], dp2[i]);
	}
	vector<pii>vec;
	for (int i = 0; i < num; i++)vec.push_back(make_pair(dat[i], i));
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	int query;
	scanf("%d", &query);
	for (int p = 0; p < query; p++)
	{
		ll z;
		scanf("%I64d", &z);
		uf.init();
		int pt = 0;
		ll maxi = 0;
		fill(now, now + num, 0);
		now[1] = num;
		ll nm = 1;
		for (int i = 0; i < num; i++)
		{
			for (;;)
			{
				if (pt == vec.size())break;
				if (vec[i].first + z < vec[pt].first)
				{
					now[uf.ren[uf.find(vec[pt].second)]]--;
					now[uf.ren[uf.find(vec[pt].second)] - 1]++;
					if (now[nm] == 0)nm--;
					uf.ren[uf.find(vec[pt].second)]--;
					pt++;
				}
				else break;
			}
			for (int j = 0; j < pat[vec[i].second].size(); j++)
			{
				int u = vec[i].second, v = pat[vec[i].second][j].first;
				if (dat[u] <= dat[v])
				{
					if (uf.find(u) != uf.find(v))
					{
						now[uf.ren[uf.find(u)]]--;
						now[uf.ren[uf.find(v)]]--;
						uf.unite(u, v);
						now[uf.ren[uf.find(u)]]++;
						nm = max(nm, (ll)uf.ren[uf.find(u)]);
					}
				}
			}
			maxi = max(maxi, nm);
		}
		printf("%I64d\n", maxi);
	}
}