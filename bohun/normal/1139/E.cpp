#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int t[5005];
int d[5005];
bool ok[5005];
vector <pair <int, int> > v[5005];
int ha[5005];
int tim = 1;
int num[5005];
bool go(int node)
{
	num[node] = tim;
	for(auto it: v[node])
	{
		if(ok[it.se] == 1)
			continue;
		if(ha[it.fi] == -1)
		{
			ha[it.fi] = node;
			return 1;
		}
	}
	for(auto it: v[node])
	{
		if(ok[it.se] == 1)
			continue;
		if(num[ha[it.fi]] != tim && go(ha[it.fi]))
		{
			ha[it.fi] = node;
			return 1;
		}
	}
	return 0;
}
int n, m;
int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 1; n >= i; ++i)
		scanf("%d", &t[i]);
	for(int i = 1; n >= i; ++i)
		{
			scanf("%d", &d[i]);
			v[t[i]].pb({d[i], i});
		}
	int q;
	scanf("%d", &q);
	while(q--)
	{
		tim = 1;
		int a;
		scanf("%d", &a);
		ok[a] = 1;
		int ans = 0;
		for(int i = 0; 5000 >= i; ++i)
		{
			num[i] = 0;
			ha[i] = -1;
		}
		for(int i = 0; 5000 >= i; ++i)
		{
			tim++;
			bool c = go(i);
			if(!c)
				break;
			ans++;
		}
		printf("%d\n", ans);
	}
	
	
	return 0;
}