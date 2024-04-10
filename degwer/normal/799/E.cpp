#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
ll dat[200000];
int ty[200000];
vector<ll>ans[4];
typedef pair<ll, ll>pii;
int main()
{
	int num, gen, gp;
	scanf("%d%d%d", &num, &gen, &gp);
	if (gen < gp)
	{
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < num; i++)scanf("%I64d", &dat[i]);
	int na;
	scanf("%d", &na);
	for (int i = 0; i < na; i++)
	{
		int z;
		scanf("%d", &z);
		z--;
		ty[z] |= 1;
	}
	int nb;
	scanf("%d", &nb);
	for (int i = 0; i < nb; i++)
	{
		int z;
		scanf("%d", &z);
		z--;
		ty[z] |= 2;
	}
	for (int i = 0; i < num; i++)ans[ty[i]].push_back(dat[i]);
	for (int i = 0; i < 4; i++)sort(ans[i].begin(), ans[i].end());
	if (ans[3].size()>gp)
	{
		int t = ans[3].size();
		for (int i = gp; i < t; i++)ans[0].push_back(ans[3][i]);
		for (int i = gp; i < t; i++)ans[3].pop_back();
		sort(ans[0].begin(),ans[0].end());
	}
	ll mini = 1000000000000000000LL;
	int beg = max(max(max(0, gp + gp - gen), gen - int(num - ans[3].size())), max(gp - int(ans[1].size()), gp - int(ans[2].size())));
	int pt = 0;
	set<pii>se;
	for (int i = 0; i < ans[0].size(); i++)se.insert(make_pair(ans[0][i], pt++));
	for (int i = gp - beg; i < ans[1].size(); i++)se.insert(make_pair(ans[1][i], pt++));
	for (int i = gp - beg; i < ans[2].size(); i++)se.insert(make_pair(ans[2][i], pt++));
	se.insert(make_pair(1000000000000000000LL, -1));
	set<pii>::iterator it = se.begin();
	ll sum = 0;
	if (beg > ans[3].size())
	{
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < gen - gp - gp + beg; i++)
	{
		sum += (*it).first;
		it++;
	}
	for (int i = 0; i < beg; i++)sum += ans[3][i];
	for (int i = 0; i < gp - beg; i++)sum += ans[1][i];
	for (int i = 0; i < gp - beg; i++)sum += ans[2][i];
	for (int i = beg; i <= ans[3].size(); i++)
	{
		//printf("%d\n", i);
		mini = min(mini, sum);
		if (i == ans[3].size())break;
		int x = gp - i - 1;
		sum -= ans[1][x] + ans[2][x];
		se.insert(make_pair(ans[1][x], pt++));
		if (ans[1][x] < (*it).first)it--, sum += ans[1][x] - (*it).first;
		se.insert(make_pair(ans[2][x], pt++));
		if (ans[2][x] < (*it).first)it--, sum += ans[2][x] - (*it).first;
		sum += ans[3][i] + (*it).first;
		it++;
	}
	if (mini == 1000000000000000000LL)printf("-1\n");
	else printf("%I64d\n", mini);
}