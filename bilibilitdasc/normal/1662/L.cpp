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
int n,l2;
ll v,t[400005],a[400005];
struct pt{
	ll l,r;
};
pt p[400005];
ll all[400005];
bool operator<(pt x1,pt x2)
{
	if(x1.l!=x2.l) return x1.l>x2.l;
	return x1.r<x2.r;
}
struct segtree{
	int v[400005<<2];
	void init()
	{
		memset(v,0xc0,sizeof(v));
	}
	void maintain(int i)
	{
		v[i]=max(v[i<<1],v[i<<1|1]);
	}
	void update(int i,int l,int r,int q,int V)
	{
		if(l==r)
		{
			v[i]=max(V,v[i]);
		}
		else
		{
			int m=(l+r)>>1;
			if(q<=m) update(i<<1,l,m,q,V);
			else update(i<<1|1,m+1,r,q,V);
			maintain(i);
		}
	}
	int query(int i,int il,int ir,int ql,int qr)
	{
		if(qr<il||ir<ql) return int(0xc0c0c0c0);
		if(ql<=il&&ir<=qr) return v[i];
		int m=(il+ir)>>1;
		return max(query(i<<1,il,m,ql,qr),query(i<<1|1,m+1,ir,ql,qr));
	}
	void deb(int i,int l,int r)
	{
		if(v[i]==int(0xc0c0c0c0)) return;
		cout<<i<<" ["<<l<<","<<r<<"] "<<v[i]<<endl;
		if(l<r)
		{
			int m=(l+r)>>1;
			deb(i<<1,l,m);
			deb(i<<1|1,m+1,r);
		}
		
	}
};
segtree seg;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>v;
	rep(i,n) cin>>t[i];
	seg.init();
	rep(i,n)
	{
		cin>>a[i];
		p[i].l=a[i]-v*t[i];
		p[i].r=a[i]+v*t[i];
	//	cout<<p[i].l<<","<<p[i].r<<endl; 
		all[i<<1]=p[i].l;
		all[i<<1|1]=p[i].r;
	}
	all[n<<1]=0; 
	sort(all,all+(n<<1|1));
	l2=unique(all,all+(n<<1|1))-all;
	rep(i,n)
	{
		p[i].l=lower_bound(all,all+l2,p[i].l)-all;
		p[i].r=lower_bound(all,all+l2,p[i].r)-all;
	}
	seg.update(1,0,400000,lower_bound(all,all+l2,0)-all,0);
	sort(p,p+n);
//	rep(i,n) cout<<p[i].l<<","<<p[i].r<<endl;
//	seg.deb(1,0,400000);
//	cout<<endl;
	rep(i,n)
	{
		if(p[i].l<=lower_bound(all,all+l2,0)-all)
		seg.update(1,0,400000,p[i].r,1+seg.query(1,0,400000,0,p[i].r));
	//	seg.deb(1,0,400000);
	//	cout<<endl;
	}
	cout<<seg.query(1,0,400000,0,400000)<<endl;
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