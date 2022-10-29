#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007LL
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
int val[15],n,m,p,rem=0;
queue<pair<int,int>> q[15];
int ans[15];
char a[1005][1005];
bool var;
int level[1005][1005];
void bfs(int p)
{
	queue<pair<int,int>> qt=q[p];
	while(!qt.empty())
	{
		pair<int,int> t=qt.front();qt.pop();
		level[t.F][t.S]=0;
	}
	while(!q[p].empty())
	{
		pair<int,int> t=q[p].front();q[p].pop();
		if(t.F>0 && a[t.F-1][t.S]=='.')
		{
			var=true;
			++ans[p];
			int z=level[t.F-1][t.S]=level[t.F][t.S]+1;
			if(z==val[p])
				qt.push({t.F-1,t.S});
			else q[p].push({t.F-1,t.S});
			a[t.F-1][t.S]='#';
		}
		if(t.S>0 && a[t.F][t.S-1]=='.')
		{
			var=true;
			++ans[p];
			int z=level[t.F][t.S-1]=level[t.F][t.S]+1;
			if(z==val[p])
				qt.push({t.F,t.S-1});
			else q[p].push({t.F,t.S-1});
			a[t.F][t.S-1]='#';
		}
		if(t.F<n-1 && a[t.F+1][t.S]=='.')
		{
			var=true;
			++ans[p];
			int z=level[t.F+1][t.S]=level[t.F][t.S]+1;
			if(z==val[p])
				qt.push({t.F+1,t.S});
			else q[p].push({t.F+1,t.S});
			a[t.F+1][t.S]='#';
		}
		if(t.S<m-1 && a[t.F][t.S+1]=='.')
		{
			var=true;
			++ans[p];
			int z=level[t.F][t.S+1]=level[t.F][t.S]+1;
			if(z==val[p])
				qt.push({t.F,t.S+1});
			else q[p].push({t.F,t.S+1});
			a[t.F][t.S+1]='#';
		}
	}
	q[p]=qt;
	return ;
}
int _runtimeTerror_()
{
	int i;
	cin>>n>>m>>p;
	for(i=0;i<p;++i)
	{
		cin>>val[i];
	}
	for(i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			cin>>a[i][j];
			if(a[i][j]=='.')continue;
			if(a[i][j]!='#')
			{
				ans[a[i][j]-'1']++;
				q[a[i][j]-'1'].push({i,j});
			}
		}
	}
	var=true;
	while(var)
	{
		var=false;
		for(i=0;i<p;++i)
		{
			bfs(i);
		}
	}
	for(i=0;i<p;++i)
		cout<<ans[i]<<" ";
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