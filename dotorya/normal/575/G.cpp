//*
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <functional>
#define MOD 1000000007
#define MAX ((1<<30)-1)
#define MAX2 ((1ll<<62)-1)
#define mp make_pair
#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int n, m;
vector<pii> edge[200000];
int check[200000];
vector<int> q;
int zero[200000];
int zeroback[200000];
int dis[200000];
vector<pii> edge2[200000];
vector<int> dab;
set<pii> edge3[200000];
int good[200000];

int back(int now)
{
	check[now]=1;
	if(now == 0)
	{
		good[now]=1;
		return 1;
	}
	for(auto e : edge3[now])
	{
		if(check[e.first] == 0)
		{
			good[now]|=back(e.first);
		}
		else good[now]|=good[e.first];
	}
	return good[now];
}

int main()
{
	int i, j, k;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		edge[x].push_back(pii(y, z));
		edge[y].push_back(pii(x, z));
	}
	check[n-1]=1;
	q.push_back(n-1);
	for(i=0;i<q.size();i++)
	{
		int now=q[i];
		for(auto e : edge[now])
		{
			if(e.second == 0 && check[e.first] == 0)
			{
				check[e.first]=1;
				zero[e.first]=zero[now]+1;
				zeroback[e.first]=now;
				q.push_back(e.first);
			}
		}
	}
	for(i=0;i<q.size();i++)
	{
		edge[n].push_back(pii(q[i], 0));
		edge[q[i]].push_back(pii(n, 0));
	}
	n++;
	q.clear();
	fill(check, check+n, 0);
	q.push_back(0);
	check[0]=1;
	for(i=0;i<q.size();i++)
	{
		int now=q[i];
		for(auto e : edge[now])
		{
			if(check[e.first] == 0)
			{
				check[e.first]=1;
				dis[e.first]=dis[now]+1;
				q.push_back(e.first);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(auto e : edge[i])
		{
			if(dis[i] == dis[e.first]+1)
			{
				edge2[i].push_back(pii(e.first, e.second));
			}
		}
	}
	q.clear();
	vector<int> live;
	live.push_back(n-1);
	for(i=0;i<dis[n-1];i++)
	{
		sort(live.begin(), live.end());
		live.erase(unique(live.begin(), live.end()), live.end());
		int mi=MAX;
		for(auto x : live)
		{
			for(auto e : edge2[x])
			{
				mi=min(mi, e.second);
			}
		}
		vector<int> nex;
		for(auto x : live)
		{
			for(auto e : edge2[x])
			{
				if(e.second == mi)
				{
					nex.push_back(e.first);
				}
			}
		}
		live=nex;
		dab.push_back(mi);
	}
	for(i=0;i<n;i++)
	{
		for(auto e : edge2[i])
		{
			if(dis[i] == dis[e.first]+1 && dis[n-1] >= dis[i] && e.second == dab[dis[n-1]-dis[i]])
			{
				edge3[i].insert(pii(e.first, e.second));
			}
		}
	}
	fill(check, check+n, 0);
	back(n-1);
	vector<int> path;
	vector<int> path2;
	int mi=MAX, mii;
	for(auto e : edge3[n-1])
	{
		if(good[e.first] && mi > zero[e.first])
		{
			mi=zero[e.first];
			mii=e.first;
		}
	}
	path.push_back(mii);
	int now=mii;
	while(now != 0)
	{
		for(auto e : edge3[now])
		{
			if(good[e.first])
			{
				path.push_back(e.first);
				now=e.first;
				break;
			}
		}
	}
	now=mii;
	while(now != n-2)
	{
		now=zeroback[now];
		path2.push_back(now);
	}
	if(dab.size() == 1) printf("0");
	for(i=1;i<dis[n-1];i++) printf("%d", dab[i]);
	printf("\n%d\n", path.size()+path2.size());
	for(i=path.size()-1;i>=0;i--) printf("%d ", path[i]);
	for(auto e : path2) printf("%d ", e);
	return 0;
}
//*/