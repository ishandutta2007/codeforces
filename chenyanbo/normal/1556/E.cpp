//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx") 
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3f
#define y0 _lxybz_
#define y1 _ljmnzyzhhhoscartxdy_
typedef long double ld;
typedef long long ll;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize
#define lo(x) ((x)&(-(x)))
#define trav(a, x) for (auto &a : x)
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
const ld Pi = 4*atan((ld)1);
template<class T> void chmin(T &a,const T&b) { a = min(a, b); }
template<class T> void chmax(T &a,const T&b) { a = max(a, b); }
namespace IO{
template<class T> inline void read(T&ret)
{
	ret=0; int f=1; char c=getchar();
	while(c<48||c>57){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	ret*=f;
}
template<class T> inline void prin(const T&ret)
{
	if(!ret){putchar(48);return;} static T o; o=ret;
	if(o<0){putchar('-');o=-o;}
	static int op[25],tt; tt=0;
	while(o){
		op[++tt]=o%10;
		o/=10;
	}
	for(int i=tt;i;--i)putchar(op[i]+48);
}
template<class T> inline void pri_(const T&ret)
{
	prin(ret);putchar(' ');
}
template<class T> inline void priE(const T&ret)
{
	prin(ret);putchar('\n');
}
}
using namespace IO;

#define N 300500
#define MO 
int n,q;
ll sa[N];
int a[N],b[N],l,r;

struct BIT {
#define ls (p<<1)
#define rs ((p<<1)|1)
#define M 270006
ll su[M],ss[M],sl[M],sr[M];

void bui(int p, int l, int r, int *w)
{
	if(l==r){
		su[p]=w[l];
		if(w[l]>0)sl[p]=w[l],sr[p]=w[l],ss[p]=w[l];
		return;
	}
	int mi=l+r>>1;
	bui(ls,l,mi,w);
	bui(rs,mi+1,r,w);
	
	su[p]=su[ls]+su[rs];
	sl[p]=max(sl[ls],su[ls]+sl[rs]);
	sr[p]=max(sr[rs],su[rs]+sr[ls]);
	ss[p]=sr[ls]+sl[rs];
	chmax(ss[p],ss[ls]);
	chmax(ss[p],ss[rs]);
}

//l
ll Q1(int p, int l, int r, int x, int y)
{
	if(x<=l&&r<=y){
		return sl[p];
	}
	if(x>r||y<l)return 0;
	int mi=l+r>>1;
	if(y<=mi)return Q1(ls,l,mi,x,y);
	return max(Q1(ls,l,mi,x,y),su[ls]+Q1(rs,mi+1,r,x,y));
}

//r
ll Q2(int p, int l, int r, int x, int y)
{
	if(x<=l&&r<=y){
		return sr[p];
	}
	if(x>r||y<l)return 0;
	int mi=l+r>>1;
	if(x>mi)return Q2(rs,mi+1,r,x,y);
	return max(Q2(rs,mi+1,r,x,y),su[rs]+Q2(ls,l,mi,x,y));
}

ll que(int p, int l, int r, int x, int y)
{
	if(x<=l&&r<=y){
		return ss[p];
	}
	if(x>r||y<l)return 0;
	int mi=l+r>>1;
	
	if(y<=mi)return que(ls,l,mi,x,y);
	if(x>=mi+1)return que(rs,mi+1,r,x,y);
	
	ll Ans=0;
	chmax(Ans,que(ls,l,mi,x,y)); 
	chmax(Ans,que(rs,mi+1,r,x,y));
	
	chmax(Ans,Q2(ls,l,mi,x,y)+Q1(rs,mi+1,r,x,y));
	return Ans;
}

}T1,T2; 

inline void _Sol_()
{
	read(n);read(q);
	F(i,1,n)read(a[i]);
	F(i,1,n)read(b[i]);
	F(i,1,n)a[i]-=b[i];
	F(i,1,n)b[i]=-a[i];
	
	F(i,1,n)sa[i]=sa[i-1]+a[i];
	
	T1.bui(1,1,n,a);
	T2.bui(1,1,n,b);
	
	F(i,1,q){
		read(l);read(r);
		if(sa[r]!=sa[l-1]){
			puts("-1");continue;
		}
		ll Ans=max(T1.que(1,1,n,l,r),T2.que(1,1,n,l,r));
		priE(Ans);
	}
}

int main()
{
	int T=1; //read(T);
	while(T--)_Sol_();
}