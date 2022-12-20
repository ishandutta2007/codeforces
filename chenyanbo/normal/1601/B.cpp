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

#define N 300500

vector<int>G[N],A[N];
int a[N],b[N],c[N],n,Ans[N],pr[N];
#define fi first
#define se second

struct BIT {
#define ls (p<<1)
#define rs ((p<<1)|1)

#define M 1100004
pair<int,int>su[M];

void bui(int p, int l, int r)
{
	if(l == r) {
		su[p] = make_pair(c[l],l);
		return;
	}
	int mi = l + r >> 1;
	bui(ls,l,mi);
	bui(rs,mi+1,r);
	su[p] = min(su[ls],su[rs]);
}

void ins(int p, int l, int r, int x, int w)
{
	if(l == r) {
		su[p] = make_pair(w,l);
		return;
	}
	int mi = l + r >> 1;
	if(x<=mi)ins(ls,l,mi,x,w);
		else ins(rs,mi+1,r,x,w);
	su[p] = min(su[ls],su[rs]);
}

pair<int,int> que(int p, int l, int r, int x, int y)
{
	if(x<=l&&r<=y)return su[p];
	if(x>r||y<l)return make_pair(INF,0);
	int mi=l+r>>1;
	return min(que(ls,l,mi,x,y),que(rs,mi+1,r,x,y));
}

}T; 
inline void _Sol_()
{
	read(n);
	F(i,1,n) read(a[i]);
	F(i,1,n) read(b[i]);
	
	F(i,1,n) A[i+b[i]].push_back(i);
	F(i,1,n) c[i] = i - a[i]; //c[0] = INF;
	T.bui(1,1,n);
	
	G[0].push_back(0); 
	F(i,1,n){
		if(!c[i]){
			G[1].push_back(i);
			T.ins(1,1,n,i,INF);
			pr[i] = 0;
			Ans[i] = 1;
		} else pr[i] = -1;
	}
	for(int de=1;G[de].size();++de){
		for(auto u:G[de]){
			for(auto v:A[u]){
				// i - ai <= v <= i
				while(1) {
					pair<int,int> h = T.que(1,1,n,v,n);
					if(h.fi > v) break;
					G[de+1].push_back(h.se);
					Ans[h.se] = de+1;
					pr[h.se] = v;
					T.ins(1,1,n,h.se,INF);
				}
			}
		}
	}
	
	if(pr[n]==-1){
		puts("-1");return;
	}
	priE(Ans[n]);
	int u = n;
	while(1){
		u = pr[u]; 
		pri_(u);
		if(!u) break;
		u += b[u];
	}
}

int main()
{
	int T=1; //read(T);
	while(T--)_Sol_();
}