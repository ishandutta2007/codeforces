#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e18
#define endl "\n"

ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n,k,i;
	cin>>n>>k;
	vector<pair<int,int>> v(n);
	for(i=0;i<n;++i)
	{
		cin>>v[i].F;
		v[i].F*=-1;
		v[i].S=i+1;
	}
	sort(all(v));
	int sum=0;
	vector<int> ans;
	for(i=0;i<k;++i)
	{
		sum-=v[i].F;
		ans.pb(v[i].S);
	}
	sort(all(ans));
	ans.pop_back();
	ans.push_back(n);
	cout<<sum<<endl;
	cout<<ans[0]<<" ";
	for(i=1;i<k;++i)
		cout<<ans[i]-ans[i-1]<<" ";
	return 0;
}