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

#define N 699969
#define MO 
ll k;
int n,m,a[N];
vector<int>G[N];
int l, r, mi, tot,di[N],du[N],q[N],qn,u,v,ss;

inline void _Sol_()
{
	read(n); read(m); read(k); //--k;
	F(i,1,n)read(a[i]);
	F(i,1,m){
		read(u); read(v);
		G[u].push_back(v);
	}
	ss = -1;
	l = 1; r = 1e9;
	while(l<=r){
		tot = qn = 0;
		mi = l+r >> 1;
		F(i,1,n)du[i] = 0, di[i] = -1;
		F(i,1,n) if(a[i] <= mi){
			++tot;
			for(auto u:G[i])if(a[u]<=mi){
				++du[u];
			}
		}
		F(i,1,n) if(!du[i] && a[i] <= mi){
			q[++qn] = i; di[i] = 1;
		}
		F(q1,1,qn){
			int u = q[q1];
			for(auto v:G[u])if(a[v]<=mi){
				chmax(di[v],di[u]+1);
				--du[v];
				if(!du[v])q[++qn]=v;
			}
		}
		if(qn < tot){
			ss = mi; r = mi - 1;
			continue;
		}
		int _=-1;
		for(int i=1;i<=qn;++i){
			chmax(_,di[q[i]]);
		}
		if(_ >= k){
			ss = mi; r = mi - 1;
			continue;
		}
		l = mi+1;
	}
	priE(ss);
}

int main()
{
	int T=1; //read(T);
	while(T--)_Sol_();
}