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
	cin.tie(0);
	cout.tie(0);

	ll t,n,mm,km,x,i;
	string s;
	cin>>t;
	vector<ll> v;
	while(t--)
	{
		v.clear();
		cin>>n>>x>>s;
		bool inf=false;
		ll count=0,ans=0;
		for(i=0;i<n;++i)
		{
			if(s[i]=='1')count--;
			else count++;
			v.pb(count);
		}
		//v.pop_back();
		if(count==0)
		{
			if(x==0)ans++;
			for(auto j:v)
			{
				if(j==x)
				{
					inf=true;break;
				}
			}
			if(inf)cout<<-1<<endl;
			else cout<<ans<<endl;
		}
		else
		{
							if(x==0)ans++;

			for(auto j:v)
			{
				if(x-j<0 && count<0)
				{
					mm=j-x;km=-count;
					if(mm%km==0)ans++;
				}
				else if(x-j>0 && count>0)
				{
					mm=x-j;km=count;
					if(mm%km==0)ans++;
				}
				else if(x-j==0)ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}