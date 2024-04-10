#include <bits/stdc++.h>
//#define CinCout
#define rep(i,n) for(int i=0,_##i##__end=(n);i<_##i##__end;++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,_##i##__end=(n);i<=_##i##__end;++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define pb push_back
#define mp make_pair
#define debugv(x) cout<<#x<<'='<<x<<",line "<<__LINE__-1<<endl
#define debug cout<<"at line "<<__LINE__-1<<" in function "<<__FUNCTION__<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
#ifdef CinCout
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#else
#define Yes puts("Yes")
#define No puts("No")
#define YES puts("YES")
#define NO puts("NO")
#endif
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int n,m;
int c[400005];
long long rreal[400005];
int dfn[400005],rgt[400005];
int t;
int tp,x,y;
vector<int> g[400005];
void dfs(int v,int u)
{
	dfn[v]=++t;
	rep(i,g[v].size())
	{
		int w=g[v][i];
		if(w!=u) dfs(w,v);
	}
	rgt[v]=t;
}
int cnt(long long popcnt)
{
	int ans=0;
	while(popcnt)
	{
		++ans;popcnt&=popcnt-1;
	}
	return ans;
}
struct segtree{
	ll v[400005<<2];
	ll t[400005<<2];
	void maintain(int i)
	{
		v[i]=v[i<<1]|v[i<<1|1];
	}
	void pushdown(int i)
	{
		if(t[i])
		{
			v[i<<1]=t[i];v[i<<1|1]=t[i];
			t[i<<1]=t[i];t[i<<1|1]=t[i];
			t[i]=0;
		}
	}
	void build(int i,int l,int r,ll* F)
	{
		t[i]=0;
		if(l==r)
		{
			v[i]=F[l];
		}
		else
		{
			int m=(l+r)>>1;
			build(i<<1,l,m,F);
			build(i<<1|1,m+1,r,F);
			maintain(i);
		}
	}
	void update(int i,int il,int ir,int ql,int qr,long long mk)
	{
		if(il>qr||ql>ir) return;
		if(ql<=il&&ir<=qr)
		{
			v[i]=mk;t[i]=mk;return;
		}
		pushdown(i);
		int m=(il+ir)>>1;
		update(i<<1,il,m,ql,qr,mk);
		update(i<<1|1,m+1,ir,ql,qr,mk);
		maintain(i);
	}
	ll query(int i,int il,int ir,int ql,int qr)
	{
		if(il>qr||ql>ir) return 0;
		if(ql<=il&&ir<=qr) return v[i];
		pushdown(i);
		int m=(il+ir)>>1;
		return query(i<<1,il,m,ql,qr)|query(i<<1|1,m+1,ir,ql,qr);
	}
};
segtree seg;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	rep1(i,n) cin>>c[i];
	rep1(i,n-1)
	{
		cin>>x>>y;g[x].pb(y);g[y].pb(x);
	}
	dfs(1,0);
	rep1(i,n)
	{
		rreal[dfn[i]]=1ll<<c[i];
	}
	seg.build(1,1,n,rreal);
	while(m--)
	{
		cin>>tp;
		if(tp==1)
		{
			cin>>x>>y;
			seg.update(1,1,n,dfn[x],rgt[x],1ll<<y);
		}
		else
		{
			cin>>x;
			cout<<cnt(seg.query(1,1,n,dfn[x],rgt[x]))<<endl;
		}
	}
	return 0;
}
/* things to check
1.  int overflow or long long memory need
2.  recursion/array/binary search/dp/loop bounds
3.  precision
4.  special cases(n=1,bounds)
5.  delete debug statements
6.  initialize(especially multi-tests)
7.  = or == , n or m ,++ or -- , i or j , > or >= , < or <=
8.  keep it simple and stupid
9.  do not delete, use // instead
10. operator priority
11. is there anything extra to output?
12. ...
*/

/* something to think about
1. greedy? dp? searching? dp with matrix/ segment tree? binary search?
2. If contains "not", why not  or few affect?
*/