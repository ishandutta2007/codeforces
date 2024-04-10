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
#define llevel 20
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
ll a[1005][1005];
pair<ll,ll> p[1005][1005];
char b[1005+2][1005+2];
bool vis[1005][1005];
bool var;ll n;
void dfs(ll i,ll j,ll k,ll l)
{
	if(vis[i][j])return ;
	vis[i][j]=true;
	//cout<<"FUCK";
	if(i==k && j==l)b[i][j]='X';
	if(i>k)b[i][j]='U';
	if(i<k)b[i][j]='D';
	if(j>l)b[i][j]='L';
	if(j<l)b[i][j]='R';
	if(i>0 && p[i-1][j].F==p[i][j].F && p[i-1][j].S==p[i][j].S){dfs(i-1,j,i,j);}
	if(i<n-1 && p[i+1][j].F==p[i][j].F && p[i+1][j].S==p[i][j].S){dfs(i+1,j,i,j);}
	if(j>0 && p[i][j-1].F==p[i][j].F && p[i][j-1].S==p[i][j].S){dfs(i,j-1,i,j);}
	if(j<n-1 && p[i][j+1].F==p[i][j].F && p[i][j+1].S==p[i][j].S){dfs(i,j+1,i,j);}
	return ;
}
int _runtimeTerror_()
{
	ll i,j,x,y;
	cin>>n;
	memf(vis);
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			b[i][j]='.';
			cin>>p[i][j].F>>p[i][j].S;
			if(p[i][j].F>0)
				--p[i][j].F;
			if(p[i][j].S>0)
				--p[i][j].S;
			if(p[i][j].F==i && j==p[i][j].S)
				b[i][j]='X';
		}
	}
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			if(p[i][j].F==-1 && p[i][j].S==-1)
			{
				vis[i][j]=true;
				ll count=0;
				if(i>0 && p[i-1][j].F==-1 && p[i-1][j].S==-1){++count;b[i][j]='U';}
				if(i<n-1 && p[i+1][j].F==-1 && p[i+1][j].S==-1){++count;b[i][j]='D';}
				if(j>0 && p[i][j-1].F==-1 && p[i][j-1].S==-1){++count;b[i][j]='L';}
				if(j<n-1 && p[i][j+1].F==-1 && p[i][j+1].S==-1){++count;b[i][j]='R';}
				if(count==0)
				{
					cout<<"INVALID";return 0;
				}
			}
		}
	}
	//var=true;
	//dfs(0,1);
	//cout<<b[0][0];
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			if(b[i][j]=='X')
			{
				//cout<<"FUCK";
				dfs(i,j,i,j);
			}
		}
	}
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			if(!vis[i][j])
			{
				cout<<"INVALID";return 0;
			}
		}
	}
	cout<<"VALID\n";
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
			cout<<b[i][j];
		cout<<endl;
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int TESTS=1;
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	return 0;
}