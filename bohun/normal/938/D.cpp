#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;
const int nax = 2e5 + 9;
int n, m;
vector < pair < int, ll > > e[nax];
ll res[nax];
ll wynik[nax];
priority_queue < pair < ll , int > > q;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; m >= i; ++i)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		e[a].push_back({b, c});
		e[b].push_back({a, c});
	}
	for(int i = 1; n >= i; ++i)
		cin >> res[i];
	for(int i = 1; n >=i; ++i)
	{
		for(auto it: e[i])
			q.push({-res[i] - it.second * 2, it.first});
	}
	while(!q.empty())
	{
		pair < ll , int > node = q.top();
		q.pop();
		node.first *= -1;
		if(wynik[node.second] != 0)
			continue;
		wynik[node.second] = node.first;
		for(auto it: e[node.second])
		{
			if(!wynik[it.first])
				q.push({-wynik[node.second] - 2 * it.second, it.first});
		}
	}
	for(int i = 1; n >= i; ++i)
		if(wynik[i] == 0)
			wynik[i] = 1e18;
	for(int i = 1; n >= i; ++i)
		cout << min(res[i] , wynik[i]) << " ";
	
}