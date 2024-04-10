#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
using namespace std;
typedef pair<char, string>pcs;
vector<pcs>vec;
set<string>se;
void dfs(string s, int n)
{
	if (s.size() == n)
	{
		se.insert(s);
		return;
	}
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].first == s[s.size() - 1])
		{
			string z;
			for (int j = 0; j < s.size() - 1; j++)z.push_back(s[j]);
			z.push_back(vec[i].second[1]);
			z.push_back(vec[i].second[0]);
			dfs(z, n);
		}
	}
}
int main()
{
	int num, q;
	scanf("%d%d", &num, &q);
	for (int i = 0; i < q; i++)
	{
		string za;
		char zb;
		cin >> za >> zb;
		vec.push_back(make_pair(zb, za));
	}
	string s;
	s.push_back('a');
	dfs(s, num);
	printf("%d\n", se.size());
}