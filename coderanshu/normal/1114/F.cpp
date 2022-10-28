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
#define sz(a) (ll)a.size()
#define F first
#define S second
#define PI 3.1415926536
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
//RNG based on mersenne_twister 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
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
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
#define runSieve
bool notPrime[1000005];
ll divPrime[1000005];
int idx[305];
void sieve(int n=301)
{
	int k=sqrt(n);
	memf(notPrime);
	notPrime[1]=true;
	for(int i=2;i<=k;++i)
	{
		if(!notPrime[i])
		{
			for(int k=i*i;k<=n;k+=i)
			{
				notPrime[k]=true;
				divPrime[k]=i;
			}
		}
	}
}
vector<ll> pr,inv;
const int N=400005;
ll a[N];
struct node
{
	ll pro;
	bitset<62> bit;

}fake={1};
// base value is assigned to fake node
node tree[4*N];
node lazy[4*N];
inline node combine(node a,node b)
{
	node ret;
	ret.pro=a.pro*b.pro%M;
	ret.bit=a.bit|b.bit;
	return ret;
}
inline node make_node(ll val)
{
	node ret;
	ret.pro=val;
	ll k=val;
	ret.bit.reset();
	while(k!=1 && notPrime[k])
	{
		ll z=divPrime[k];
		ret.bit[idx[z]]=1;
		while(k%z==0)k/=z;
	}
	if(k>1)
		ret.bit[idx[k]]=1;
	return ret;
}
inline void pushdown(ll v,ll st,ll en)
{
	if(lazy[v].pro==1 && lazy[v].bit.count()==0)
		return ;
	tree[v].pro*=power(lazy[v].pro,en-st+1,M)%M;
	tree[v].pro%=M;
	tree[v].bit|=lazy[v].bit;
	if(st!=en)
	{
		lazy[v<<1].pro=lazy[v<<1].pro*lazy[v].pro%M;
		lazy[v<<1 | 1].pro=lazy[v<<1| 1].pro*lazy[v].pro%M;
		lazy[v<<1].bit|=lazy[v].bit;
		lazy[v<<1 | 1].bit|=lazy[v].bit;
	}
	lazy[v].pro=1;
	lazy[v].bit.reset();
	return ;
}
void buildTree(ll v,ll st,ll en)
{
	if(st==en)
	{
		tree[v]=make_node(a[st]);
		return ;
	}
	ll mid=(st+en)>>1;
	buildTree(v<<1,st,mid);
	buildTree(v<<1 | 1,mid+1,en);
	tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
}
void update(ll v,ll st,ll en,ll in,ll val)
{
	ll mid=(st+en)>>1;
	if(st==en)
	{
		tree[v]=make_node(val);
		a[st]=val;
		return ;
	}
	if(in<=mid)
		update(v<<1,st,mid,in,val);
	else
		update(v<<1 | 1,mid+1,en,in,val);
	tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
}
void rupdate(ll v,ll st,ll en,ll l,ll r,ll val)
{
	if(lazy[v].pro!=0)
	{
		pushdown(v,st,en);
	}
	if(en<l || st>r)return ;
	if(st>=l && en<=r)
	{
		lazy[v].pro=val;
		lazy[v].bit.reset();
		ll k=val;
		while(k!=1 && notPrime[k])
		{
			ll z=divPrime[k];
			lazy[v].bit[idx[z]]=1;
			while(k%z==0)k/=z;
		}
		if(k>1)
			lazy[v].bit[idx[k]]=1;
		pushdown(v,st,en);
		return ;
	}
	ll mid=(st+en)>>1;
	rupdate(v<<1,st,mid,l,r,val);
	rupdate(v<<1 | 1,mid+1,en,l,r,val);
	tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
}
node query(ll v,ll st,ll en,ll l,ll r)
{
	if(en<l || st>r)
		return fake;
	if(lazy[v].pro!=0)
	{
		pushdown(v,st,en);
	}
	if(st>=l && en<=r)
		return tree[v];
	ll mid=(st+en)>>1;
	return combine(query(v<<1,st,mid,l,r),query(v<<1 | 1,mid+1,en,l,r));
}
ll getans(ll st,ll en,ll l,ll r)
{
	node ans=query(1,st,en,l,r);
	ll ret=ans.pro;
	//cout<<ans.bit<<endl;
	for(ll i=0;i<62;++i)
	{
		if(ans.bit[i])
		{
			ret*=(pr[i]-1)*inv[i]%M;
			ret%=M;
		}
	}
	return ret;

}
int _runtimeTerror_()
{
	ll n,i,q;
	cin>>n>>q;
	for(i=0;i<n;++i)
		cin>>a[i];
	buildTree(1,0,n-1);
	while(q--)
	{
		string s;
		ll l,r,val;
		cin>>s>>l>>r;
		if(s=="TOTIENT")
		{
			cout<<getans(0,n-1,l-1,r-1)<<endl;
		}
		else
		{
			cin>>val;
			rupdate(1,0,n-1,l-1,r-1,val);
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifdef runSieve
		sieve();
	#endif
	#ifdef NCR
		initialize();
	#endif
	for(ll i=2;i<=300;++i)
		if(!notPrime[i])
			pr.pb(i),inv.pb(power(i,M-2,M));

	for(ll i=0;i<sz(pr);++i)
		idx[pr[i]]=i;

	for(ll i=0;i<4*N;++i)
		lazy[i].pro=1,lazy[i].bit.reset();
	int TESTS=1;
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	cerr<<"\n"<<_time_;
	return 0;
}