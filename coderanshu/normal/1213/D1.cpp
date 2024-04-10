#pragma GCC optimize("Ofast")

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
#define INF 2e15
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
vector<ll> v[200005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,k,num,count,m=0;
	cin>>n>>k;
	while(n--)
	{
		cin>>num;
		m=max(m,num);
		v[num].pb(0);count=0;
		while(num!=1)
		{
			num/=2;count++;
			v[num].pb(count);
		}
	}
	ll i,j,ans=INF,a;
	for(i=1;i<=m;i++)
	{
		if(v[i].size()<k)continue;
		sort(all(v[i]));
		a=0;
		for(j=0;j<k;j++)a+=v[i][j];
		ans=min(ans,a);
	}
	cout<<ans;
	return 0;
}