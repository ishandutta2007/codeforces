#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1000005,mod=1e9+7;
vector<int> adj[M];
int par[M],lev[M];
ll v[M];
ll e[M],o[M];
ll ans,res,n;
ll powmod(ll base, ll exponent)
{ 
	//cout<<base<<" "<<exponent<<endl;
 
	ll ans=1;
	
		while(exponent)
		{ 
			while(exponent%2==0)
			{
				base=(base*base)%mod;
				exponent/=2;
			}
			
			exponent--;
			ans=(ans*base)%mod;
		}
		
	return ans;
}
void dfs(int x,int depth)
{
	//o[x]++;
 
	lev[x]=depth;
	
	int cno=0;
 
	for(int i=0;i<adj[x].size();i++)
	{
		int c=adj[x][i];
	
		if(c!=par[x])
		{
			par[c]=x;
	
			dfs(c,depth+1);
		
			if(cno>0)
			{
				ans=( (ans+ 2*( o[x]*e[c]%mod - e[x]*o[c]%mod + mod)%mod*v[x]%mod)+mod )%mod;
			}
			
			cno++;
		
			o[x]+=e[c];
			e[x]+=o[c];
		
		}
	
	}
	
	o[x]++;
 
	
}
int main()
{
	//freopen("o.out","r",stdin);
 
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	
	for(int i=1;i<n;i++)
	{
		int u,v;
		
		cin>>u>>v;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(1,0); 
	
	//cout<<ans<<endl;
	
	for(int i=1;i<=n;i++)
	{	
		//cout<<"###"<<i<<endl;
		if(lev[i]%2)
		{
			ans=((ans+2*(o[i]*(e[1]-o[i]+1)%mod - e[i]*(o[1]-e[i])%mod +mod)%mod*v[i]%mod)%mod+mod )%mod;
		}
		else
		{
			ans=((ans+2*(o[i]*(o[1]-o[i]+1)%mod - e[i]*(e[1]-e[i])%mod +mod)%mod*v[i]%mod)%mod+mod )%mod;
		}
		
		//cout<<ans<<endl;
		
		ans=((ans-v[i])%mod+mod)%mod;
		
//		cout<<i<<" "<<ans<<endl;
		//cout<<ans<<endl;
	}
	
	cout<<ans<<endl;
 
}