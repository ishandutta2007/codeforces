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
pair<int,int> p[200005];
int k;
vector<int> checking,ans;
bool check(ll m)
{
	int i,j;
	checking.clear();
	for(i=0;i<k;++i)
	{
		for(j=0;j<p[i].F/m;++j)
		{
			checking.pb(p[i].S);
			if(checking.size()==k)
				return true;
		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n>>k;
	int i,num;
	for(i=0;i<200001;++i)
	{
		p[i].F=0;
		p[i].S=i;
	}
	for(i=0;i<n;++i)
	{
		cin>>num;
		--p[num].F;
	}
	sort(p,p+200001);
	for(i=0;i<k;++i)p[i].F*=-1;
	int st=p[k-1].F,en=p[0].F;
	while(st<=en)
	{
		int mid=(st+en)>>1;
		if(check(mid))
		{
			st=mid+1;
			ans.clear();ans=checking;
		}
		else en=mid-1;
	}
	for(auto j:ans)cout<<j<<" ";
	return 0;
}