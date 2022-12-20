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

#define N 400500
#define MO 
int f[100400][55],_w,n,m,u,v,tot,O[N],w,c[N][3],op,a[N];
struct node {
	int u, op ,w;
	bool operator < (const node&a)const{
		if(w!=a.w)return w<a.w;
		if(u!=a.u)return u<a.u;
		return op<a.op;
	}
};
set<node>S;
inline void _Sol_()
{
	read(n);read(m);
	F(i,1,m){
		read(u); read(v); read(w);
		c[++tot][0]=v; c[tot][1]=a[u]; c[tot][2]=w; a[u]=tot;
		c[++tot][0]=u; c[tot][1]=a[v]; c[tot][2]=w; a[v]=tot;
	}
	S.insert((node){1,0,0});
	F(i,1,n)O[i]=-1; O[1]=0;
	memset(f,0x7f,sizeof f);
	while(!S.empty()){
		u=S.begin()->u; op=S.begin()->op; w=S.begin()->w;
		S.erase(S.begin());
		if(!op){
			for(int o=a[u];o;o=c[o][1]){
				v=c[o][0];
				if(f[v][c[o][2]] > w){
					S.erase((node){v,c[o][2],f[v][c[o][2]]});
					f[v][c[o][2]]=w;
					S.insert((node){v,c[o][2],f[v][c[o][2]]});
				}
			}
			continue;
		}
		for(int o=a[u]; o; o=c[o][1]){
			v=c[o][0];
			_w=w+(op+c[o][2])*(op+c[o][2]);
			
			if(O[v]==-1 || O[v]>_w){
				S.erase((node){v,0,O[v]});
				O[v]=_w; 
				S.insert((node){v,0,O[v]});
			}
		}
	}
	F(i,1,n)priE(O[i]);
}

int main()
{
	int T=1; //read(T);
	while(T--)_Sol_();
}