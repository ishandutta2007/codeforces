#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
typedef long double ld;
typedef pair<ld, int>pdi;
typedef pair<int, int>pii;
typedef pair<pii, int>pi3;
vector<pii>dat[100000];
int beg[100000];
int maxi[100000];
int frm[100000];
ld rui[100001];
int main()
{
	int num, query, gen;
	scanf("%d%d%d", &num, &query, &gen);
	for (int i = 0; i < num; i++)scanf("%d", &beg[i]);
	vector<int>typ;
	vector<pii>tim;
	for (int i = 0; i < query; i++)
	{
		int za, zb, zc;
		scanf("%d%d%d", &za, &zb, &zc);
		zb--;
		typ.push_back(za);
		if (za == 1)
		{
			if (maxi[zb] < zc - beg[zb])
			{
				maxi[zb] = zc - beg[zb];
				frm[zb] = i;
			}
		}
		if (za == 2)
		{
			dat[zb].push_back(make_pair(zc, i));
		}
		if (za == 3)
		{
			if (zc != 1)tim.push_back(make_pair(zc, i));
		}
	}
	sort(tim.begin(), tim.end());
	reverse(tim.begin(), tim.end());
	for (int i = 0; i < tim.size(); i++)rui[i + 1] = rui[i] + log(tim[i].first);
	for (int i = 0; i < num; i++)
	{
		if (maxi[i] > 0)
		{
			dat[i].push_back(make_pair(maxi[i], frm[i]));
		}
	}
	vector<pdi>add;
	for (int i = 0; i < num; i++)
	{
		sort(dat[i].begin(), dat[i].end());
		reverse(dat[i].begin(), dat[i].end());
		ld now = beg[i];
		for (int j = 0; j < dat[i].size(); j++)
		{
			add.push_back(make_pair(log((now + dat[i][j].first) / (now)), dat[i][j].second));
			now += dat[i][j].first;
		}
	}
	sort(add.begin(), add.end());
	reverse(add.begin(), add.end());
	if (gen > add.size() + tim.size())gen = add.size() + tim.size();
	ld mx = -1.0;
	int rr = -1;
	ld now = 0.0;
	for (int i = 0; i <= min(gen, int(add.size())); i++)
	{
		if (mx < now + rui[gen - i])
		{
			mx = now + rui[gen - i];
			rr = i;
		}
		if (i == add.size())break;
		now += add[i].first;
	}
	vector<pii>ans;
	for (int i = 0; i < rr; i++)ans.push_back(make_pair(typ[add[i].second], add[i].second));
	for (int i = 0; i < gen - rr; i++)ans.push_back(make_pair(typ[tim[i].second], tim[i].second));
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
	{
		if (i != 0)printf(" ");
		printf("%d", ans[i].second + 1);
	}
	printf("\n");
}