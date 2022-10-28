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
	
	int n,i,t;
	cin>>n;
	int a[n+1][2];
	for(i=1;i<=n;++i)
	{
		cin>>a[i][0]>>a[i][1];
	}
	vector<int> v;
	v.pb(1);
	if(a[a[1][0]][0]==a[1][1] || a[a[1][0]][1]==a[1][1])
	{
		v.pb(a[1][0]);v.pb(a[1][1]);
	}
	else
	{
		v.pb(a[1][1]);v.pb(a[1][0]);
	}
	while(v.size()<n)
	{
		t=v[v.size()-2];
		v.pb(a[t][0]+a[t][1]-v[v.size()-1]);
	}
	for(auto j:v)
		cout<<j<<" ";
	return 0;
}