#include <bits/stdc++.h>
#define rep(i,n) for(int i=0,_##i##__end=(n);i<_##i##__end;++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,_##i##__end=(n);i<=_##i##__end;++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define repk(i,a,b) for(int i=(a),_##i##__end=(b);i<=_##i##__end;++i)
#define perk(i,a,b) for(int i=(a),_##i##__end=(b);i>=_##i##__end;++i)
#define rep0(i,a,b) for(int i=(a),_##i##__end=(b);i<_##i##__end;++i)
#define pb push_back
#define mp make_pair
#define debug(x) cout<<#x<<'='<<x<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int n,q,tp,x,y;
ll a[200005];
struct Node{
	int l;
	int r;
	ll res;
	bool flag;
	Node()
	{
		l=r=0;res=0;flag=1;
	}
	Node(const int&L,const int&R,const ll&I,const bool&fl)
	{
		l=L,r=R,res=I,flag=fl;
	}
};
ll cnt(const ll&x)
{
	return (x*(x+1))>>1;
}
//Hooray ! No lazytags ! (I hate lazytags QwQ QAQ QvQ)
struct segtree{
	Node s[1000006];
	void maintain(const int&i,const int&l,const int&r)
	{
		int m=(l+r)>>1;
		s[i].flag=s[i<<1].flag&&s[i<<1|1].flag&&(a[m]<=a[m+1]);
		if(s[i<<1].flag&&s[i<<1|1].flag)/*2 parts!*/
		{
			s[i].res=0;
			s[i].l=m-l+1;
			s[i].r=r-m;
		}
		else if(s[i<<1].flag)/*1 increasing!*/
		{
			s[i].l=m-l+1;
			s[i].r=s[i<<1|1].r;
			s[i].res=s[i<<1|1].res;
			if(a[m]<=a[m+1])
			{
				s[i].l+=s[i<<1|1].l;
			}
			else
			{
				
				s[i].res+=cnt(s[i<<1|1].l);
			}
		}
		else if(s[i<<1|1].flag)/*1 increasing*/
		{
			s[i].l=s[i<<1].l;
			s[i].r=r-m;
			s[i].res=s[i<<1].res;
			if(a[m]<=a[m+1])
			{
				s[i].r+=s[i<<1].r;
			}
			else
			{
				s[i].res+=cnt(s[i<<1].r);
			}
		}
		else/*nothing special1!*/
		{
			s[i].l=s[i<<1].l;
			s[i].r=s[i<<1|1].r;
			s[i].res=s[i<<1].res+s[i<<1|1].res;
			if(a[m]<=a[m+1])
			{
				s[i].res+=cnt(s[i<<1].r+s[i<<1|1].l);
			}
			else
			{
				s[i].res+=cnt(s[i<<1].r)+cnt(s[i<<1|1].l);
			}
		}
	}
	void build(const int&i,const int&l,const int&r)
	{
		if(l==r)
		{
			s[i]=Node();
			return ;
		}
		int m=(l+r)>>1;
		build(i<<1,l,m);
		build(i<<1|1,m+1,r);
		maintain(i,l,r);
	}
	void update(const int&i,const int&il,const int&ir,const int&q,const ll&x)
	{
		//cout<<"HGH AK"<<endl;
		if(il==ir)
		{
			a[q]=x;
			return;
		}
		int m=(il+ir)>>1;
		if(q<=m)
		update(i<<1,il,m,q,x);
		else
		update(i<<1|1,m+1,ir,q,x);
		//cout<<"CSP"<<endl;
		maintain(i,il,ir);
	}
	void query(const int&i,const int&il,const int&ir,const int&ql,const int&qr,ll&ans,int&len)
	{
		if(max(il,ql)>min(ir,qr)) return;
		if(ql<=il&&ir<=qr)
		{
			if(s[i].flag)
			{
				if(a[il-1]<=a[il])
				{
					len+=ir-il+1;
				}
				else
				{
					ans+=cnt(len);len=ir-il+1;
				}
			}
			else
			{
				ans+=s[i].res;
				if(a[il-1]<=a[il])
				{
					ans+=cnt(len+s[i].l);
				}
				else
				{
					ans+=cnt(len)+cnt(s[i].l);
				}
				len=s[i].r;
			}
			return ;
		}
		int m=(il+ir)>>1;
		if(ql<=m) query(i<<1,il,m,ql,qr,ans,len);
		if(m<qr) query(i<<1|1,m+1,ir,ql,qr,ans,len);
	}
	void upd(const int&i,const ll&x)
	{
		update(1,1,n,i,x);
	}
	ll qry(const int&l,const int&r)
	{
		ll ans=0;int x=0;
		query(1,1,n,l,r,ans,x);
		//cout<<ans<<' '<<x<<endl;
		return ans+cnt(x);
	}
};
segtree seg;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>q;
	rep1(i,n) cin>>a[i];
	seg.build(1,1,n);
	while(q--)
	{
		cin>>tp>>x>>y;
		if(tp==1) seg.upd(x,y);
		else cout<<seg.qry(x,y)<<endl;
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