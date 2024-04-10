#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;
int n, m;
int a, b;
const int nax = 2e5 + 5;
vector < int > e[nax];
set < int > s;
int siz[nax], id[nax];
int l;
void dfs(int u)
{
	s.erase(u);
	siz[l]++;
	id[u] = l;
	set < int > :: iterator it = s.upper_bound(0);
	int k = 0;
	while(it != s.end())
	{
		while(*it > e[u][k])
			k++;
		if(*it == e[u][k])
		{
			it = s.upper_bound(*it);
			continue;
		}
		int val = *it;
		dfs(*it);
		it = s.upper_bound(val);
	}
}
		
int main()
{
	cin >> n >> m;
	for(int i = 1; m >= i; ++i)
	{
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for(int i = 1; n >= i; ++i)
		e[i].push_back(n + 1);
	for(int i = 1; n >= i; ++i)
		s.insert(i);
	for(int i = 1; n >= i; ++i)
		sort(e[i].begin(),e[i].end());
	for(int i = 1; n >= i; ++i)
	{
		if(!id[i])
		{
			l++;
			dfs(i);
		}
	}
	cout << l << endl;
	sort(siz + 1,siz + l + 1);
	for(int i = 1; l >= i; ++i)
		cout << siz[i] << " ";
			
	return 0;	
}