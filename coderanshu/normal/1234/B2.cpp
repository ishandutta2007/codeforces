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
#define findMax max_element
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
	ll n,k,i,num,t;
	cin>>n>>k;
	ll a[n];
	queue<ll> v;
	map<ll,ll> m;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		m[a[i]]=0;
	}
	ll ctr=0;
	for(i=0;i<n;i++)
	{
		if(m[a[i]]==0)
		{
			if(ctr<k){v.push(a[i]);m[a[i]]=1;ctr++;}
			else {m[v.front()]=0;v.pop();v.push(a[i]);m[a[i]]=1;}
		}
	}
	cout<<v.size()<<endl;
	vector<ll> vec;
	while(!v.empty())
	{
		vec.pb(v.front());
		v.pop();
	}
	reverse(all(vec));
	for(auto j:vec)cout<<j<<" ";
	return 0;
}