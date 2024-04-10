#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mini = 1000000000000000000LL;
typedef pair<ll, ll>pii;
void calc(vector<pii>v)
{
	//for (int i = 0; i < v.size(); i++)printf("%I64d %I64d   ", v[i].first, v[i].second); printf("\n");
	if (v.size() <= 1)return;
	vector<pii>v1, v2;
	ll med = v[v.size() / 2].first;
	for (int i = 0; i < v.size(); i++)
	{
		if (i < v.size() / 2)v1.push_back(v[i]);
		else v2.push_back(v[i]);
	}
	calc(v1), calc(v2);
	vector<pii>x1, x2;
	for (int i = 0; i < v1.size(); i++)if ((med - v1[i].first)*(med - v1[i].first) <= mini)x1.push_back(make_pair(v1[i].second, v1[i].first));
	for (int i = 0; i < v2.size(); i++)if ((med - v2[i].first)*(med - v2[i].first) <= mini)x2.push_back(make_pair(v2[i].second, v2[i].first));
	sort(x1.begin(), x1.end());
	sort(x2.begin(), x2.end());
	ll beg = 0, end = mini;
	for (;;)
	{
		if (beg == end)break;
		ll med = (beg + end + 1) / 2;
		if (med*med > mini)end = med - 1;
		else beg = med;
	}
	for (int i = 0; i < x1.size(); i++)
	{
		int low = lower_bound(x2.begin(), x2.end(), make_pair(x1[i].first - beg, -1000000000000000000LL)) - x2.begin();
		int upp = upper_bound(x2.begin(), x2.end(), make_pair(x1[i].first + beg, 1000000000000000000LL)) - x2.begin();
		for (int j = low; j < upp; j++)mini = min(mini, (x1[i].second - x2[j].second)*(x1[i].second - x2[j].second) + (x1[i].first - x2[j].first)*(x1[i].first - x2[j].first));
	}
}
int main()
{
	int num;
	scanf("%d", &num);
	vector<pii>v;
	ll s = 0;
	for (int i = 0; i < num; i++)
	{
		ll z;
		scanf("%I64d", &z);
		s += z;
		v.push_back(make_pair((ll)i, s));
	}
	calc(v);
	printf("%I64d\n", mini);
}