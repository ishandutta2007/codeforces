#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
ll mod;
vector<pii>pat[100000];
vector<pii>ko[100000];
pii par[100000];
map<ll, ll>du[100000];
map<ll, ll>dl[100000];
ll mlu[100000], plu[100000];
ll mld[100000], pld[100000];
bool flag[100000];
void dfs(int node)
{
	if (flag[node])return;
	flag[node] = true;
	for (int i = 0; i < pat[node].size(); i++)
	{
		if (!flag[pat[node][i].first])
		{
			ko[node].push_back(pat[node][i]);
			par[pat[node][i].first] = make_pair(node, pat[node][i].second);
			dfs(pat[node][i].first);
		}
	}
}
ll ans = 0;
ll p10[200001];
ll pv10[200001];
int calc(int node)
{
	du[node][0] = 1;
	dl[node][0] = 1;
	mlu[node] = 0, plu[node] = 0;
	mld[node] = 0, pld[node] = 0;
	int now = node;
	for (int i = 0; i < ko[node].size(); i++)
	{
		int z = calc(ko[node][i].first);
		if (du[now].size() < du[z].size())swap(now, z);
		map<ll, ll>::iterator it = du[z].begin();
		for (;;)
		{
			if (it == du[z].end())break;
			ll x = (*it).first, k = (*it).second;
			ll mok = (mod - (x*p10[mlu[z]] + plu[z]) % mod) % mod;
			mok = (mok + mod - pld[now])*p10[mld[now]] % mod;
			if(dl[now].count(mok))ans += dl[now][mok] * k;
			it++;
		}
		it = dl[z].begin();
		for (;;)
		{
			if (it == dl[z].end())break;
			ll x = (*it).first, k = (*it).second;
			ll mok = (mod - (x*pv10[mld[z]] + pld[z]) % mod) % mod;
			mok = (mok + mod - plu[now])*pv10[mlu[now]] % mod;
			if(du[now].count(mok))ans += du[now][mok] * k;
			it++;
		}
		it = du[z].begin();
		for (;;)
		{
			if (it == du[z].end())break;
			ll x = (*it).first, k = (*it).second;
			x = (x*p10[mlu[z]] + plu[z]) % mod;
			x = (x + mod - plu[now])*pv10[mlu[now]] % mod;
			du[now][x] += k;
			it++;
		}
		it = dl[z].begin();
		for (;;)
		{
			if (it == dl[z].end())break;
			ll x = (*it).first, k = (*it).second;
			x = (x*pv10[mld[z]] + pld[z]) % mod;
			x = (x + mod - pld[now])*p10[mld[now]] % mod;
			dl[now][x] += k;
			it++;
		}
	}
	mlu[now]++;
	plu[now] = (plu[now] * 10 + par[node].second) % mod;
	mld[now]++;
	pld[now] = ((pld[now] + par[node].second)*pv10[1]) % mod;
	return now;
}
int main()
{
	int num;
	scanf("%d%I64d", &num, &mod);
	for (int i = 0; i < num - 1; i++)
	{
		int za, zb, zc;
		scanf("%d%d%d", &za, &zb, &zc);
		pat[za].push_back(make_pair(zb, zc));
		pat[zb].push_back(make_pair(za, zc));
	}
	ll inv;
	for (ll i = 0;; i++)
	{
		if ((mod*i + 1) % 10 == 0)
		{
			inv = (mod*i + 1) / 10;
			break;
		}
	}
	p10[0] = pv10[0] = 1;
	for (int i = 1; i <= 200000; i++)p10[i] = (p10[i - 1]) * 10 % mod, pv10[i] = (pv10[i - 1] * inv) % mod;
	dfs(0);
	calc(0);
	printf("%I64d\n", ans);
}