#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef pair<int, int>pii;
int main()
{
	int num;
	scanf("%d", &num);
	multiset<int>se;
	vector<int>vec;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		se.insert(z);
		vec.push_back(z);
	}
	set<pii>s;
	int maxi = 1;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (i == j)continue;
			if (s.find(make_pair(vec[i], vec[j])) != s.end())continue;
			vector<int>z;
			z.push_back(vec[i]);
			z.push_back(vec[j]);
			multiset<int>::iterator it = se.find(vec[i]);
			se.erase(it);
			it = se.find(vec[j]);
			se.erase(it);
			for (int p = 2;; p++)
			{
				it = se.find(z[p - 1] + z[p - 2]);
				if (it == se.end())break;
				se.erase(it);
				z.push_back(z[p - 1] + z[p - 2]);
			}
			maxi = max(maxi, int(z.size()));
			for (int i = 0; i < z.size(); i++)se.insert(z[i]);
			for (int i = 0; i < z.size() - 1; i++)s.insert(make_pair(z[i], z[i + 1]));
		}
	}
	printf("%d\n", maxi);
}