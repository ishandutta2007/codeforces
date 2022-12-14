#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register ll
ll n,m,k,a[1000005],ans;
pair<ll,ll>p[1000005];
priority_queue<ll,vector<ll>,greater<ll> >q;
int main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for(re i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(re i=1;i<n;i++)
	{
		p[i].first=a[i+1]-a[i],p[i].second=i;
	}
	sort(p+1,p+n);
	for(re i=n-1;i>=n-(k-1);i--) q.push(p[i].second),q.push(p[i].second+1);
	q.push(1);q.push(n);
	while(!q.empty())
	{
		re i=q.top();q.pop();
		re j=q.top();q.pop();
		ans+=a[j]-a[i]+1;
	}
	cout<<ans;
	return 0;
}