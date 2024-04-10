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
#define INF 

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
	ll n,t,num;
	cin>>t;
	n=1;
	map<ll,ll> m;
	while(t--)
	{
		cin>>num;
		m[num]++;
		n=(n*num)%M;
	}
	ll p=1;
	//cout<<n<<endl;
	bool found=false;
	for(auto j:m)
	{
		if((j.S+1)%2==0)
		{
			m[j.F]=j.S/2;
			found=true;
			break;
		}
	}
	if(found)
	{
		for(auto j:m)
		{
			n=power(n,j.S+1,M);
		}
	}
	else if(!found)
	{
		for(auto j=m.begin();j!=m.end();j++)
		{
			j->second=(j->second)/2;
		}
		n=1;
		for(auto j:m)
		{
			n=(n*power(j.F,j.S,M))%M;
		}
		for(auto j:m)
		{
			n=power(n,2*j.S+1,M);
		}
	}
	cout<<n;
	return 0;
}