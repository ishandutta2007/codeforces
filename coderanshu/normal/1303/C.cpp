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
set<int> v[28];
bool vis[26];
string ans;
void dfs(int s)
{
	vis[s]=true;
	ans.pb((char)('a'+s));
	for(auto j:v[s])
	{
		if(!vis[j])dfs(j);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll tests,i;
	bool done;
	cin>>tests;
	while(tests--)
	{
		ans.clear();
		done=false;
		for(i=0;i<=25;++i)
		{
			v[i].clear();vis[i]=false;
		}
		string s;
		cin>>s;
		int n=s.length();
		if(n==1)
		{
			cout<<"YES\nabcdefghijklmnopqrstuvwxyz\n";continue;
		}
		for(i=0;i<n;++i)
		{
			if(i>0)
				v[s[i]-'a'].insert(s[i-1]-'a');
			if(i<n-1)
				v[s[i]-'a'].insert(s[i+1]-'a');
		}
		int start=-1;
		for(i=0;i<26;++i)
		{
			if(v[i].size()>2)
			{
				done=true;
			}
			if(v[i].size()==1)start=i;
		}
		if(done || start==-1)
		{
			cout<<"NO\n";continue;
		}
		dfs(start);
		cout<<"YES\n";
		for(i=0;i<26;++i)
		{
			if(!vis[i])cout<<(char)('a'+i);
		}
		cout<<ans<<endl;
	}
	return 0;
}