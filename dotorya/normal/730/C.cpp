//*
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <string.h>

using namespace std;

#define mp make_pair
#define MAX 0x3f3f3f3f
#define MAX2 0x3f3f3f3f3f3f3f3f

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m, p, Q;
vector<int> edge[10000];
vector<int> shops[10000];

pair<int, pll> sdat[10000];

int S;

pll it[100000];

int dis[10000], check[10000];

pll operator+(pll x, pll y)
{
	return mp(x.first+y.first, x.second+y.second);
}

void update(int x)
{
	for(x/=2;x>0;x/=2) it[x]=it[x*2]+it[x*2+1];
}

pll getsum(int x, int y)
{
	pll res(0, 0);
	while(x <= y)
	{
		if(x%2 == 1) res=res+it[x++];
		if(y%2 == 0) res=res+it[y--];
		x/=2, y/=2;
	}
	return res;
}

ll getget(int now, ll v)
{
    if(it[now].first < v) return MAX2;
    if(v == 0) return 0;
    if(now >= S)
	{
        return it[now].second/it[now].first*v;
	}
	if(it[now*2].first >= v) return getget(now*2, v);
	else return it[now*2].second+getget(now*2+1, v-it[now*2].first);
}

int main()
{
	int i, j, k, l;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		int x, y;
		scanf("%d%d", &x, &y), x--, y--;
		edge[x].push_back(y), edge[y].push_back(x);
	}
	cin>>p;
	for(i=0;i<p;i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z), x--;
		sdat[i]=mp(x, mp(y, z));
	}
	sort(sdat, sdat+p, [](pair<int, pii> p, pair<int, pii> q)
	{
		return p.second.second < q.second.second;
	});
	for(i=0;i<p;i++)
	{
		shops[sdat[i].first].push_back(i);
	}
	cin>>Q;
	for(S=1;S<p;S*=2);
	for(i=0;i<Q;i++)
	{
		ll x, y, z;
		scanf("%lld%lld%lld", &x, &y, &z), x--;
        vector<int> q;
        for(j=0;j<n;j++) dis[j]=MAX, check[j]=0;
        for(j=0;j<S*2;j++) it[j]=mp(0, 0);
        dis[x]=0;
        check[x]=1;
        q.push_back(x);
        for(j=0;j<q.size();j++)
		{
			int now=q[j];
			for(auto e : edge[now])
			{
				if(check[e]) continue;
				check[e]=1;
				dis[e]=dis[now]+1;
				q.push_back(e);
			}
		}
		int ans=-1;
		for(auto e : q)
		{
            for(auto f : shops[e])
			{
				it[S+f]=mp(sdat[f].second.first, sdat[f].second.first*sdat[f].second.second);
				update(S+f);
			}
			ll res=getget(1, y);
			if(res <= z)
			{
				ans=dis[e];
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
//*/