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
int a[100005];
pair<int,int> tree[400005];
void buildTree(int v,int st,int en)
{
	if(st==en)
	{
		tree[v].F=a[st];
		tree[v].S=1;
		return ;
	}
	int mid=(st+en)>>1;
	buildTree(v<<1,st,mid);
	buildTree(v<<1 | 1 ,mid+1,en);
	tree[v].F=__gcd(tree[2*v].F,tree[2*v+1].F);
	tree[v].S=(tree[v].F==tree[2*v].F)*tree[2*v].S+(tree[v].F==tree[2*v+1].F)*tree[2*v+1].S;
}
int querygcd(int v,int l,int r,int st,int en)
{
	if(l>r)return -1;
	if(l==st && r==en)
		return tree[v].F;
	int mid=(st+en)>>1;
	int a=querygcd(2*v,l,min(r,mid),st,mid);
	int b=querygcd(2*v+1,max(l,mid+1),r,mid+1,en);
	if(a==-1)
		return b;
	else if(b==-1)return a;
	return __gcd(a,b);
}
int solve(int v,int l,int r,int st,int en,int val)
{
	if(l>r)return 0;
	if(l==st && r==en)
	{
		if(val==tree[v].F)return tree[v].S;
		else return 0;
	}
	int mid=(st+en)>>1;
	return solve(2*v,l,min(r,mid),st,mid,val)+solve(2*v+1,max(l,mid+1),r,mid+1,en,val);
}
int _runtimeTerror_()
{
	ll n,i;
	cin>>n;
	for(i=0;i<n;++i)
		cin>>a[i];
	buildTree(1,0,n-1);
	ll t;
	cin>>t;
	while(t--)
	{
		ll l,r;
		cin>>l>>r;--l;--r;
		int x=querygcd(1,l,r,0,n-1);
		cout<<(r-l+1)-solve(1,l,r,0,n-1,x)<<endl;
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
// very nice use of segment tree andd number theory of _gcds