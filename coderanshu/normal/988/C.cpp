#pragma GCC optimize("Ofast")

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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll k,test,sum,i,n;
	cin>>k;
	map<ll,vector<pair<ll,ll>>> m;
	for(test=1;test<=k;test++)
	{
		cin>>n;
		vector<ll> v(n);
		sum=0;
		map<ll,ll> markSum;
		for(i=0;i<n;i++)
		{
			cin>>v[i];sum+=v[i];
		}
		for(i=0;i<n;i++)
		{
			if(markSum[sum-v[i]]==0)
			{
				markSum[sum-v[i]]=1;
				m[sum-v[i]].pb({test,i+1});
			}
		}
		markSum.clear();
	}
	for(auto j:m)
	{
		if(j.S.size()>1)
		{
			cout<<"YES\n";
			cout<<j.S[0].F<<" "<<j.S[0].S<<endl;
			cout<<j.S[1].F<<" "<<j.S[1].S<<endl;
			return 0;
		}
	}
	cout<<"NO";

	return 0;

}