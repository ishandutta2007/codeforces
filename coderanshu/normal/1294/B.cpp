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

ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,(e-1)/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,(e-1)/2);
	return power(b*b,e/2);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll t,n;
	cin>>t;
	string str;
	ll i,j;
	bool check;
	while(t--)
	{
		cin>>n;
		check=true;
		str.clear();
		vector<pair<ll,ll>> v(n);
		for(i=0;i<n;i++)
			cin>>v[i].F>>v[i].S;
		sort(all(v));
		for(i=0;i<v[0].F;i++)str+="R";
			for(i=0;i<v[0].S;i++)str+="U";
		for(i=1;i<n;i++)
		{
			if(v[i].F<v[i-1].F || v[i].S<v[i-1].S)
			{
				check=false;break;
			}
			for(j=0;j<v[i].F-v[i-1].F;j++)str+="R";
			for(j=0;j<v[i].S-v[i-1].S;j++)str+="U";
		}
		if(check)cout<<"YES"<<endl<<str<<endl;
		else cout<<"NO\n";
	}
	return 0;
}