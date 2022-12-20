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
struct node{
	int d, i;
	bool operator < (const node & a)const {
		return d<a.d;
	}
}A[N];
int c[N][2],tot,a[N],n,m,k,op[N],q[N],qn,u,v,Vi[N],d[N],D[N],ma,Ans;
inline void _Sol_()
{
	read(n);read(m);read(k);
	F(i,1,k)read(op[i]);
	F(i,1,m){
		read(u);read(v);
		c[++tot][0]=v;c[tot][1]=a[u];a[u]=tot;
		c[++tot][0]=u;c[tot][1]=a[v];a[v]=tot;
	}
	Vi[1]=1;
	q[qn=1]=1;
	F(q1,1,qn){
		u=q[q1];
		for(int o=a[u]; o; o=c[o][1]){
			v=c[o][0];
			if(!Vi[v]){
				Vi[v]=1;d[v]=d[u]+1;q[++qn]=v;
			}
		}
	}
	F(i,1,n)Vi[i]=0;
	Vi[n]=1;
	q[qn=1]=n;
	F(q1,1,qn){
		u=q[q1];
		for(int o=a[u]; o; o=c[o][1]){
			v=c[o][0];
			if(!Vi[v]){
				Vi[v]=1;D[v]=D[u]+1;q[++qn]=v;
			}
		}
	}
	
	F(i,1,k){
		A[i].d=d[op[i]];A[i].i=op[i];
	}
	sort(A+1,A+k+1);
	ma=D[A[k].i];
	dF(i,k-1,1){
		chmax(Ans,A[i].d+1+ma);
		chmax(ma,D[A[i].i]);
	}	
	chmin(Ans,d[n]);
	priE(Ans);
}

int main()
{
	int T=1; //read(T);
	while(T--)_Sol_();
}