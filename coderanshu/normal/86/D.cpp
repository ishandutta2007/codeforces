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
#define INF 2e18
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
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

const int N=200004;
ll a[N];
int BLOCK;
struct node{
	ll l,r,idx;
}Q[N];
ll arr[1000005],A[N];
inline void add(ll idx,ll &ans)
{
	if(arr[a[idx]]==0)
		ans+=a[idx];
	else
		ans+=((arr[a[idx]]+1)*(arr[a[idx]]+1)-arr[a[idx]]*arr[a[idx]])*a[idx];
	++arr[a[idx]];
}
inline void del(ll idx,ll &ans)
{
	if(arr[a[idx]]==1)
		ans-=a[idx];
	else
		ans+=((arr[a[idx]]-1)*(arr[a[idx]]-1)-arr[a[idx]]*arr[a[idx]])*a[idx];
	--arr[a[idx]];
}
int _runtimeTerror_()
{
	ll n,q,i;
	cin>>n>>q;
	for(i=1;i<=n;++i)
		cin>>a[i];
	for(i=0;i<q;++i)
	{
		cin>>Q[i].l>>Q[i].r;
		Q[i].idx=i;
	}
	BLOCK=max((ll)(n/sqrt(q)),1ll);
	sort(Q,Q+q,[&](node a,node b){if(a.l/BLOCK==b.l/BLOCK)return a.r<b.r;return a.l/BLOCK<b.l/BLOCK;});
	ll curL=1,curR=0,ans=0;
	for(i=0;i<q;++i)
	{
		while(curR<Q[i].r)add(++curR,ans);
		while(curR>Q[i].r)del(curR--,ans);
		while(curL<Q[i].l)del(curL++,ans);
		while(curL>Q[i].l)add(--curL,ans);
		A[Q[i].idx]=ans;
	}
	for(i=0;i<q;++i)
		cout<<A[i]<<endl;
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
	int TESTS=1;
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	cerr<<_time_;
	return 0;
}