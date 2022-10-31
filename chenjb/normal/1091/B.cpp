#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <cassert>
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n;
pair<int,int> poi[1100],a[1100];
map<pair<int,int>,vector<int> >dic;
int ansx,ansy;
int v[1100];
int main()
{
	cin>>n;
	rep(i,n)scanf("%d%d",&poi[i].first,&poi[i].second);
	rep(i,n)scanf("%d%d",&a[i].first,&a[i].second);
	dic.clear();
	rep(i,n)rep(j,n)
	{
		pair<int,int> t=mp(poi[i].first+a[j].first,poi[i].second+a[j].second);
		dic[t].pb(i);
	}
	for(auto p:dic)
	{
		if (p.second.size()<n)continue;
		rep(i,n)v[i]=0;
		for(auto q:p.second)v[q]=1;
		int t=0; rep(i,n)t+=v[i];
		if (t!=n)continue;
		cout<<p.first.first<<" "<<p.first.second<<endl;
		return 0;
	}
	assert(0);
	return 0;
}