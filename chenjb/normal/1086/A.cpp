#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
pair<int,int> a[4];
set<pair<int,int> >ans[4];
void insert(int ti,pair<int,int> x,pair<int,int> y)
{
	while (x.first<y.first)ans[ti].insert(mp(x.first++,x.second));
	while (x.first>y.first)ans[ti].insert(mp(x.first--,x.second));
	while (x.second<y.second)ans[ti].insert(mp(x.first,x.second++));
	while (x.second>y.second)ans[ti].insert(mp(x.first,x.second--));
	ans[ti].insert(x);
	ans[ti].insert(y);
}
int main()
{
	rep(i,3)scanf("%d%d",&a[i].first,&a[i].second);
	rep(i,3)
	{
		ans[i].clear();
		rep(j,3)insert(i,a[j],a[i]);
	}
	int minp=1;
	rep(i,3)if (ans[i].size()<ans[minp].size())minp=i;
	cout<<ans[minp].size()<<endl;
	for(auto p:ans[minp])printf("%d %d\n",p.first,p.second);
	return 0;
}