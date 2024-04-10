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
#define INF 2e9
#define endl "\n"
#define MAX 1000005
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
int ln(ll v)
{
	return (int)log2(v);
}
ll a[1000005],tree[4000005],n;
void buildTree(ll v,ll st,ll en)
{
	if(st==en)
	{
		tree[v]=a[st];
		return;
	}
	ll mid=(st+en)/2;
	buildTree(2*v,st,mid);
	buildTree(2*v+1,mid+1,en);
	int z=(n%2)^(ln(v)%2);
	if(z)
		tree[v]=(tree[2*v]|tree[2*v+1]);
	else
		tree[v]=(tree[2*v]^tree[2*v+1]);
}
void updateTree(ll v,ll st,ll en,ll pos,ll val)
{
	if(st==en)
	{
		tree[v]=val;return;
	}
	ll mid=(st+en)/2;
	if(pos<=mid)
		updateTree(2*v,st,mid,pos,val);
	else
		updateTree(2*v+1,mid+1,en,pos,val);
	ll z=(n-ln(v))%2;
	if(z)tree[v]=tree[2*v]|tree[2*v+1];
	else tree[v]=tree[2*v]^tree[2*v+1];
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll m,t,i,p,b;
	cin>>n>>m;
	t=power(2,n);
	for(i=0;i<t;i++)
	{
		cin>>a[i];
	}
	
	buildTree(1,0,t-1);
	while(m--)
	{
		cin>>p>>b;
		updateTree(1,0,t-1,p-1,b);
		cout<<tree[1]<<endl;
	}
	
	return 0;
}