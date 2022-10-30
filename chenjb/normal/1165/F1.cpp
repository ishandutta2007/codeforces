#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
using namespace std;

int n,m,k[210000];
vector<int> a[210000];
vector<pair<int, int>> save;
long long tot;
bool check(int limit)
{
	save.clear();
	rep(i,n)
	{
		auto it=upper_bound(a[i].begin(), a[i].end(), limit);
		if (it==a[i].begin())continue; it--;
		save.pb(mp(*it, k[i]));
	}
	sort(save.begin(), save.end());
	int pre=0;
	int tmp2=0;
	long long sum=0;
	for (auto p:save) 
	{
		tmp2=tmp2+p.first-pre;
		sum=sum+min(p.second,tmp2);
		tmp2=tmp2-min(p.second,tmp2);
		pre=p.first;
	}
	return tot*2-sum<=limit;
}
int main() 
{
	scanf("%d%d", &n, &m);
	tot=0;
	rep(i,n){ scanf("%d",&k[i]); tot+=k[i]; }
	rep(i,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[y].pb(x);
	}
	rep(i,n)sort(a[i].begin(),a[i].end());
	int left=1,right=500000;
	while (left<right) 
	{
		int mid=(left+right)/2;
		if (check(mid))right=mid;
		else left=mid+1;
	}
	cout<<left<<endl;
}