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
ll n;
bool check(ll t)
{
	map<int,int> m;
	while(t!=0)
	{
		m[t%10]++;
		t/=10;
	}
	return m.size()<=2;
}
int dfs(ll i,ll &ans)
{
	if(i<=n && i>0)
		ans++;
	if(i>n)return 0;
	for(auto j=0;j<=9;j++)
	{
		if(i*10+j>0)
		{
			if(check(i*10+j))
				dfs(i*10+j,ans);
		}
	}
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll ans;
	cin>>n;
	ans=0;
	dfs(0,ans);
	cout<<ans;
	return 0;
}