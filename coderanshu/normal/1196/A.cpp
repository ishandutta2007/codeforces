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
	int q;
	ll a,b,c;
	cin>>q;
	while(q--)
	{
		cin>>a>>b>>c;
		ll ans=min(a,b);
		if(c>=max(a,b)-min(a,b))
			ans=max(a,b)+(c-(max(a,b)-min(a,b)))/2;
		else
			ans=min(a,b)+c;
		ll temp;
		swap(a,c);
		if(c>=max(a,b)-min(a,b))
			temp=max(a,b)+(c-(max(a,b)-min(a,b)))/2;
		else
			temp=min(a,b)+c;
		ans=max(ans,temp);
		swap(a,c);
		swap(b,c);
		if(c>=max(a,b)-min(a,b))
			temp=max(a,b)+(c-(max(a,b)-min(a,b)))/2;
		else
			temp=min(a,b)+c;
		ans=max(ans,temp);
		cout<<ans<<endl;
	}
	return 0;
}