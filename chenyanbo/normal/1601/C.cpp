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

#define N 2000600
int a[N],d[N],c[N],b[N],n,o,t,m,Ans[N],pr[N],su[N];
struct BIT{

int h[N];
void ins(int p)
{
	for(;p<=t;p+=lo(p))++h[p];
}
int que(int p)
{
	int ss=0;
	for(;p;p-=lo(p))ss += h[p];
	return ss;
}

}T;

void sol(int l, int r, int x, int y)  // qian of [bl,br] ax..ay
{
	if(l>=r) {
		F(i,x,y) Ans[i] = l;
		return;
	}
	int mi = l+r >> 1; //qian of [bl,bmi]
	//l..mi-1   mi..r-1
	//sol bmi
	pr[x-1] = 0;
	F(i,x,y){
		pr[i]=pr[i-1]+(a[i]>b[mi]);
	}
	su[y+1] = 0;
	dF(i,y,x){
		su[i]=su[i+1]+(a[i]<b[mi]);
	}
	int p; p=x-1;
	F(i,x,y){
		if(pr[i] + su[i+1] < pr[p]+su[p+1]) p = i;
	}
	sol(l,mi,x,p);
	sol(mi+1,r,p+1,y);
}

inline void _Sol_()
{
	read(n); read(m); t=0;
	F(i,1,n) read(a[i]),c[++t] = a[i];
	F(i,1,m) read(b[i]),c[++t] = b[i];
	sort(c+1,c+t+1);
	t = unique(c+1,c+t+1)-c-1;
	
	F(i,1,t) T.h[i] = 0;
	
	F(i,1,n) a[i] = lower_bound(c+1,c+t+1,a[i])-c;
	F(i,1,m) b[i] = lower_bound(c+1,c+t+1,b[i])-c;
	sort(b+1,b+m+1);
	sol(1,m+1,1,n);
	int u=1; o=0;
	F(i,1,n){
		while(Ans[i]>u){
			d[++o] = b[u]; ++u;
		}
		d[++o] = a[i];
	}
	while(u<=m){
		d[++o]=b[u]; ++u;
	}
	ll Ans=0;
	dF(i,o,1){
		Ans+=T.que(d[i]-1);
		T.ins(d[i]);
	}
	priE(Ans);
}

int main()
{
	int T=1; read(T);
	while(T--)_Sol_();
}
/*
1
3 3
3 2 1
1 2 3

*/