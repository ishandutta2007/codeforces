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

	ll t,check,i;
	cin>>t;
	vector<pair<ll,ll>> v;
	while(t--)
	{
		ll n;
		v.clear();
		cin>>n;
		ll count=0;
		for(i=2;i<=sqrt(n);i++)
		{
			if(count<3)
			{
				if(n%i==0)
				{
					check=0;
					while(n%i==0)
					{
						check++;n/=i;
					}
					v.pb({i,check});
					count++;
				}
			}
			else break;
		}
		if(count<3 && n!=1){v.pb({n,1});count++;n=1;}
		if(count==1)
		{
			if(v[0].S<6)cout<<"NO\n";
			else cout<<"YES\n"<<v[0].F<<" "<<v[0].F*v[0].F<<" "<<power(v[0].F,v[0].S-3)<<endl;
		}
		else if(count==2)
			{
				if(v[0].S+v[1].S>=4)
				{
					cout<<"YES\n"<<v[0].F<<" "<<v[1].F<<" "<<power(v[1].F,v[1].S-1)*power(v[0].F,v[0].S-1)<<endl;

				}
				else
				cout<<"NO\n";
		}
		else if(count==3)
		{
			cout<<"YES\n";
			cout<<power(v[0].F,v[0].S)<<" "<<power(v[1].F,v[1].S)<<" "<<power(v[2].F,v[2].S)*n<<endl;
		}
	}
	return 0;
}