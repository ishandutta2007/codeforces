#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
using namespace std;
pair<int,int> a[310000];
priority_queue<int,vector<int>,greater<int> >Q;
int main()
{
	int n,k;
	cin>>n>>k;
	rep(i,n)
	{
		int x,y;
		scanf("%d%d",&y,&x);
		a[i]=mp(x,y);
	}
	sort(a+1,a+n+1);
	long long ans=0;
	long long sum=0;
	for(int i=n;i>=1;i--)
	{
		Q.push(a[i].second); sum=sum+a[i].second;
		if (Q.size()>k){ sum=sum-Q.top(); Q.pop(); }
		ans=max(ans,1ll*a[i].first*sum);
	}
	cout<<ans<<endl;
	return 0;
}