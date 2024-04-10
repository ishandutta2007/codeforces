#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define rep(i,a,b) for(i=a;i<b;i++)
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e9
#define endl "\n"

ll power(ll b,ll e,ll m)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b%m,(e-1)/2,m)%m;
	else
		return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b,(e-1)/2);
	else
		return power(b*b,e/2);
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll t,n,mi,ans,tc,i,num;
	cin>>t;
	map<ll,ll> m;
	while(t--)
	{
		m.clear();
		cin>>n>>mi;
		for(i=1;i<=n;i++)
		{
			cin>>num;
			m[num]=i;

		}
		cin>>num;
		tc=m[num];
		ans=0;
		ans+=2*(tc-1)+1;
		for(i=1;i<mi;i++)
		{
			cin>>num;
			if(m[num]<tc)
			{
				ans++;
			}
			else
			{
				tc=m[num];
				ans+=2*(tc-i-1)+1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}