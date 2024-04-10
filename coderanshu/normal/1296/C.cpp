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

	ll t,i,n,lr,ud;
	string s;
	cin>>t;
	map<pair<ll,ll>,ll> m;
	while(t--)
	{
		m.clear();
		cin>>n>>s;bool found=false;ll ans=s.length()+1,ans1=0,ans2=0;
		m[{0,0}]=-1;
		lr=0;ud=0;
		for(i=0;s[i];++i)
		{
			if(s[i]=='L')lr--;
			else if(s[i]=='R')lr++;
			else if(s[i]=='U')ud++;
			else ud--;
			if(m.count({lr,ud}))
			{
				found=true;
				if(i-m[{lr,ud}]<ans)
				{
					ans=i-m[{lr,ud}];
					ans2=i;ans1=m[{lr,ud}];
				}
				m[{lr,ud}]=i;
			}
			else
			{
				m[{lr,ud}]=i;
			}
		}
		if(found)cout<<ans1+2<<" "<<ans2+1<<endl;
			else cout<<-1<<endl;
	}
	return 0;
}