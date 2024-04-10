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
#define pi 3.1415926536

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
	int n,m,x,y;
	cin>>n>>m;
	bool vis[n];
	memf(vis);
	while(m--)
	{
		cin>>x>>y;
		vis[x-1]=true;vis[y-1]=true;
	}
	int ans;
	for(auto i=0;i<n;i++)
	{
		if(!vis[i])
		{
			ans=i;
			break;
		}
	}
	cout<<n-1<<endl;
	for(auto i=0;i<n;i++)
	{
		if(i!=ans)
		cout<<ans+1<<" "<<i+1<<"\n";
	}
	return 0;
}