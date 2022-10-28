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
ll n,k,a,b;
bool check(ll m)
{
	return m*a+(n-m)*b<k;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	
	ll t,be,en;
	cin>>t;
	while(t--)
	{
		cin>>k>>n>>a>>b;
		if(n*a<k)
			cout<<n<<endl;
		else if(n*b>=k)
			cout<<-1<<endl;
		else
		{
			be=1;en=n;
			while(be<=en)
			{
				ll mid=(be+en)/2;
				if(check(mid))
					be=mid+1;
				else
					en=mid-1;
			}
			cout<<be-1<<endl;
		}
	}
	return 0;
}