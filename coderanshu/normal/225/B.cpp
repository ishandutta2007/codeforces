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
void binary(ll n)
{
	ll i=0;
	vector<ll> v;
	while(n!=0)
	{
		int k=n%2;
		if(k==1)v.pb(power(2,i));
		i++;n/=2;
	}
	cout<<v.size()+1<<endl<<"0 ";
	for(auto j:v)cout<<j<<" ";
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll k,s,i;
	cin>>s>>k;
	vector<ll> v(100,0);
	
	if(k>=31)
	{
		binary(s);
		return 0;
	}
	v[k]=v[k+1]=1;
	i=k+1;
	while(v[i]<s)
	{
		i++;
		v[i]=2*v[i-1]-v[i-k-1];
	}
	vector<ll> ans;
	ans.pb(0);
	for(auto j=i;j>=k+1;j--)
	{
		if(s>=v[j])
		{
			ans.pb(v[j]);
			s-=v[j];
		}
	}
	cout<<ans.size()<<endl;
	for(auto j:ans)cout<<j<<" ";
	return 0;
}