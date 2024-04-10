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
string str;
int func(ll l,ll r,ll &s,ll &f)
{
	if(f>s)
		{
			if((s+1<l || s+1>r) && (s<l || s>r)){str+="R";s++;}
				else
					str+="X";
				
		}
	if(f<s)
		{
				if((s-1<l || s-1>r) && (s<l || s>r)){str+="L";s--;}
				else
					str+="X";
		}
		return 0;
}
int count(ll n)
{
	int count1=0,count2=0;
	while(n!=0)
	{
		count1+=(n%10)==4;
		count2++;
		n/=10;
	}
	return (count1==count2/2);
}
vector<ll> adj[105];
ll num=0;
bool vis[105];
void dfs(ll s)
{
	vis[s]=true;
	for(auto j:adj[s])
	{
		if(!vis[j])
			dfs(j);
	}
}
bool check(ll a,ll b)
{
	memf(vis);
	dfs(a);
	return vis[b];
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,m,l,r;
	cin>>n>>m;
	int a[m];
	int i=0;
	if(m%2)
	{
		a[0]=m/2+1;
		i++;
		l=m/2;r=m/2+2;
	}
	else
	{
		l=m/2;r=m/2+1;
	}
	while(i<m)
	{
		a[i]=l;
		a[i+1]=r;
		l--;r++;
		i+=2;
	}
	for(i=0;i<n;i++)
		cout<<a[i%m]<<endl;
	return 0;
}