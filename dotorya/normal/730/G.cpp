//*
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define mp make_pair

typedef long long ll;
typedef pair<ll, ll> pll;

int n;
pll a[300];

vector<pll> ans;
set<pll> s;

int dodo(pll x)
{
	int i, j;
	for(auto e : ans)
	{
        if(max(x.first, e.first) <= min(x.second, e.second)) return 0;
	}
	return 1;
}

int main()
{
	int i, j, k, l;
	cin>>n;
	for(i=0;i<n;i++) cin>>a[i].first>>a[i].second;
	for(i=0;i<n;i++)
	{
		pll tar=mp(a[i].first, a[i].first+a[i].second-1);
		if(dodo(tar))
		{
			ans.push_back(tar);
			s.insert(tar);
		}
		else
		{
			if(dodo(mp(1, a[i].second)))
			{
				ans.push_back(mp(1, a[i].second));
				s.insert(mp(1, a[i].second));
			}
			else
			{
				for(auto e : s)
				{
					if(dodo(mp(e.second+1, e.second+a[i].second)))
					{
						ans.push_back(mp(e.second+1, e.second+a[i].second));
						s.insert(mp(e.second+1, e.second+a[i].second));
						break;
					}
				}
			}
		}
	}
	for(auto e : ans) printf("%lld %lld\n", e.first, e.second);
	return 0;
}
//*/