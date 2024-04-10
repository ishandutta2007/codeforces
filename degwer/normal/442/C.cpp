#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
int main()
{
	int num;
	scanf("%d", &num);
	vector<int>vec;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		vec.push_back(z);
	}
	set<pii>se;
	for (int i = 0; i < num; i++)se.insert(make_pair(i, vec[i]));
	vector<pii>x;
	for (int i = 1; i < num - 1; i++)if (vec[i - 1] >= vec[i] && vec[i] <= vec[i + 1])x.push_back(make_pair(i, vec[i]));
	ll ans = 0;
	for (;;)
	{
		if (x.empty())break;
		pii z = x[x.size() - 1];
		x.pop_back();
		set<pii>::iterator it = se.find(z);
		if (it == se.end())continue;
		it--;
		pii a = *it;
		it++;
		it++;
		pii b = *it;
		it--;
		if (a.second<z.second || z.second>b.second)continue;
		ans += min(a.second, b.second);
		it--;
		if (it != se.begin())
		{
			it--;
			pii c = *it;
			if (c.second >= a.second&&a.second <= b.second)x.push_back(a);
			it++;
		}
		it++;
		it++;
		it++;
		if (it != se.end())
		{
			pii d = *it;
			if (a.second >= b.second&&b.second <= d.second)x.push_back(b);
		}
		it--;
		it--;
		se.erase(it);
	}
	set<pii>::iterator it = se.begin();
	vector<int>aa;
	int mx = -1, rr = -1;
	for (int i = 0;; i++)
	{
		if (it == se.end())break;
		aa.push_back((*it).second);
		it++;
	}
	for (int i = 0; i<int(aa.size()) - 2; i++)if (aa[i]>aa[i + 1] && aa[i + 1] < aa[i + 2])abort();
	sort(aa.begin(), aa.end());
	for (int i = 0; i < int(aa.size()) - 2; i++)ans += aa[i];
	printf("%I64d\n", ans);
}