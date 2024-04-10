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
//ios_base::sync_with_stdio(false);cin
int n,m,s;
int t[200005]; 
int c[200005];
struct segtree{
	int v[200005<<2];
	void maintain(int i)
	{
		v[i]=v[i<<1]+v[i<<1|1];
	}
	void build(int i,int l,int r,int *a)
	{
		if(l==r)
		{
			v[i]=a[l];
		}
		else
		{
			int m=(l+r)>>1;
			build(i<<1,l,m,a);
			build(i<<1|1,m+1,r,a);
			maintain(i);
		}
	}
	void update(int i,int l,int r,int q,int d)
	{
		if(l==r)
		{
			v[i]+=d;
		}
		else
		{
			int m=(l+r)>>1;
			if(q<=m) update(i<<1,l,m,q,d);
			else update(i<<1|1,m+1,r,q,d);
			maintain(i);
		}
	}
	int query(int i,int il,int ir,int ql,int qr)
	{
		if(il>qr||ql>ir) return 0;
		if(ql<=il&&ir<=qr) return v[i];
		int m=(il+ir)>>1;
		return query(i<<1,il,m,ql,qr)+query(i<<1|1,m+1,ir,ql,qr);
	}
};
segtree cc;
ll tot=0,nw=1;//probability
ll fac[200005];
ll ivf[200005];
ll qkpw(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod1;
		a=a*a%mod1;
		b>>=1;
	}
	return res;
}
void init()
{
	fac[0]=1;
	rep1(i,200000) fac[i]=fac[i-1]*i%mod1;
	ivf[200000]=qkpw(fac[200000],mod1-2);
	per(i,200000) ivf[i]=ivf[i+1]*(i+1)%mod1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	init();
	cin>>n>>m;
	rep(i,n)
	{
		cin>>s;++c[s];
	}
	cc.build(1,1,200000,c);
	rep(i,m)
	{
		cin>>t[i];
		if(t[i]>1)
		{
			tot+=nw*cc.query(1,1,200000,1,t[i]-1)%mod1*qkpw(cc.query(1,1,200000,1,200000),mod1-2)%mod1;
			//cout<<"Nw value * "<<cc.query(1,1,200000,1,t-1)<<" / "<<cc.query(1,1,200000,1,200000)<<endl;
			if(tot>=mod1) tot-=mod1;
		}
		nw=nw*cc.query(1,1,200000,t[i],t[i])%mod1*qkpw(cc.query(1,1,200000,1,200000),mod1-2)%mod1;
	//	cout<<"Nw value *= "<<cc.query(1,1,200000,t,t)<<" / "<<cc.query(1,1,200000,1,200000)<<endl;
		cc.update(1,1,200000,t[i],-1);
	}
//	cout<<tot<<endl;
	tot=tot*fac[n]%mod1;
	rep1(i,200000) tot=tot*ivf[c[i]]%mod1;
	if(m>n)
	{
		bool flag=1;
		rep(i,n)
		{
			--c[t[i]];
		}
		rep1(i,200000)
		{
			if(c[t[i]]<0)
			{
				flag=0;break;
			}
		}
		if(flag)
		{
			++tot;
			if(tot==mod1) tot=0;
		}
	}
	cout<<tot<<endl;
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