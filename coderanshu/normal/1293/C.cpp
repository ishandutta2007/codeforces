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
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,q,r,c;
	cin>>n>>q;
	set<ll> s1,s2;
	bool ans=true;
	ll checkvar=0;
	ll arr[3][n+1];
	mem0(arr);
	while(q--)
	{
		cin>>r>>c;
		if(r==1)
		{
			if(!s1.count(c))
			{
				if(s2.count(c+1))checkvar++;
				if(s2.count(c))checkvar++;
				if(s2.count(c-1))checkvar++;
				s1.insert(c);
			}
			else
			{
				if(s2.count(c+1))checkvar--;
				if(s2.count(c))checkvar--;
				if(s2.count(c-1))checkvar--;
				s1.erase(c);
			}
		}
		if(r==2)
		{
			if(!s2.count(c))
			{
				if(s1.count(c+1))checkvar++;
				if(s1.count(c))checkvar++;
				if(s1.count(c-1))checkvar++;
				s2.insert(c);
			}
			else
			{
				if(s1.count(c+1))checkvar--;
				if(s1.count(c))checkvar--;
				if(s1.count(c-1))checkvar--;
				s2.erase(c);
			}
		}
		if(checkvar>0)cout<<"no\n";
		else cout<<"Yes\n";
	}
	return 0;
}