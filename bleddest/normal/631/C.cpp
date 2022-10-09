#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;



int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	set<pair<int, int> > qs;
	for(int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &y, &x);
		while(!qs.empty() && qs.begin()->first <= x)
		{
			qs.erase(qs.begin());
		}
		qs.insert(make_pair(x, y));
	}
	multiset<int> s;
	int rg = qs.rbegin()->first;
	for(int i = 0; i < rg; i++)
		s.insert(a[i]);
	while(!qs.empty())
	{
		int r = qs.rbegin()->first;
		int f = qs.rbegin()->second;
		qs.erase(*qs.rbegin());
		int l = 0;
		if(!qs.empty())
			l = qs.rbegin()->first;
		for(int i = r - 1; i >= l; i--)
		{
			if(f == 1)
				a[i] = *s.rbegin();
			if(f == 2)
				a[i] = *s.begin();
			s.erase(s.find(a[i]));
		}
	}
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	puts("");
}