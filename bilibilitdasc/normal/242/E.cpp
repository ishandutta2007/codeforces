#include <bits/stdc++.h>
//on luogu
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
struct bits{
	int len;
	int x[20];
	bits(int v=0,int l=1)
	{
		len=l;
		rep(i,20)
		{
			x[i]=(v>>i)&1;
		}
	}
};
bits operator+(bits a,bits b)
{
	bits c;
	c.len=a.len+b.len;
	rep(i,20)
	c.x[i]=a.x[i]+b.x[i];
	return c;
}
bits operator&=(bits&a,int b)
{
	rep(i,20)
	{
		if(!((b>>i)&1))
		{
			a.x[i]=0;
		}
	}
	return a;
}
bits operator^=(bits&a,int b)
{
	rep(i,20)
	{
		if((b>>i)&1)
		{
			a.x[i]=a.len-a.x[i];
		}
	}
	return a;
}
bits operator|=(bits&a,int b)
{
	rep(i,20)
	{
		if((b>>i)&1)
		{
			a.x[i]=a.len;
		}
	}
	return a;
}
ll toint(const bits&a)
{
	ll res=0;
	rep(i,20)
	res+=ll(a.x[i])<<i;
	return res;
}
const int ALL=1048575;
struct segtree{
	bits s[100005<<2];
	int tag[100005<<2];
	void maintain(int i)
	{
		s[i]=s[i<<1]+s[i<<1|1];
	}
	void pushdown(int i)
	{
		if(tag[i])
		{
			s[i<<1]^=tag[i];
			s[i<<1|1]^=tag[i];
			tag[i<<1]^=tag[i];
			tag[i<<1|1]^=tag[i];
			tag[i]=0;
		}
	}
	void build(int i,int l,int r,int *a)
	{
		if(l==r)
		{
			tag[i]=0;
			s[i]=a[l];
		}
		else
		{
			int m=(l+r)>>1;
			build(i<<1,l,m,a);
			build(i<<1|1,m+1,r,a);
			maintain(i);
		}
	}
	void update(int i,int il,int ir,int ql,int qr,int val)
	{
		if(il>qr||ql>ir) return;
		if(ql<=il&&ir<=qr)
		{
			s[i]^=val;tag[i]^=val;return;
		}
		pushdown(i); 
		int m=(il+ir)>>1;
		update(i<<1,il,m,ql,qr,val);
		update(i<<1|1,m+1,ir,ql,qr,val);
		maintain(i);
	}
	bits query(int i,int il,int ir,int ql,int qr)
	{
		if(il>qr||ql>ir) return bits(0,0);
		if(ql<=il&&ir<=qr) return s[i];
		pushdown(i);
		int m=(il+ir)>>1;
		return query(i<<1,il,m,ql,qr)+query(i<<1|1,m+1,ir,ql,qr); 
	}
};
int n,m,tp,l,r,x;
int a[100005];
segtree A;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	rep1(i,n) cin>>a[i];
	A.build(1,1,n,a);
	cin>>m;
	rep(i,m)
	{
		cin>>tp>>l>>r;
		if(tp==1)
		{
			cout<<toint(A.query(1,1,n,l,r))<<endl;
		}
		else
		{
			cin>>x;A.update(1,1,n,l,r,x);
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
6.  initial.ize(especially multi-tests)
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