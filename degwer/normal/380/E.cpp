#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
typedef long double ld;
ll ans[300000][35];
int dat[300000];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%d", &dat[i]);
	set<int>se;
	vector<pii>vec;
	for (int i = 0; i < num; i++)se.insert(i), vec.push_back(make_pair(dat[i], i));
	sort(vec.begin(), vec.end());
	for (int i = 0; i < num; i++)
	{
		set<int>::iterator it = se.find(vec[i].second);
		vector<int>va, vb;
		for (int j = 0; j < 35; j++)
		{
			va.push_back(*it);
			it++;
			if (it == se.end())break;
		}
		va.push_back(num);
		it = se.find(vec[i].second);
		for (int j = 0; j < 35; j++)
		{
			vb.push_back(*it);
			if (it == se.begin())break;
			it--;
		}
		vb.push_back(-1);
		//for (int j = 0; j < va.size(); j++)printf("%d ", va[j]); printf("\n");
		//for (int j = 0; j < vb.size(); j++)printf("%d ", vb[j]); printf("\n"); printf("\n");
		for (int j = 0; j < va.size() - 1; j++)
		{
			for (int k = 0; k < vb.size() - 1 && j + k + 1 < 35; k++)
			{
				ans[vec[i].second][j + k + 1] += (ll)(va[j + 1] - va[j])*(ll)(vb[k] - vb[k + 1]);
			}
		}
		se.erase(vec[i].second);
	}
	ld ret = 0;
	for (int i = 0; i < num; i++)
	{
		ld tim = 1.0;
		for (int j = 0; j < 35; j++)
		{
			ret += (ld)ans[i][j] * tim * (ld)dat[i];
			tim *= 0.5;
		}
	}
	ret /= (ld)num*(ld)num;
	printf("%.10lf\n", double(ret));
}