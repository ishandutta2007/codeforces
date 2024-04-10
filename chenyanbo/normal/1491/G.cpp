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

#define N 400060
#define MO 
int st1[N],st2[N],n,tp,fl,ci,Vi[N],u,v,c[N];
vector<int>V[N];
inline void sw(int a, int b)
{
	++tp; st1[tp]=a; st2[tp]=b;
	swap(c[a],c[b]);
}

inline void tr(int a, int b)
{
	int l1=V[a].size(),l2=V[b].size();
	
	u=V[a][0]; v=V[b][0];
	sw(u,v); int fl=0;
	F(i,2,l1+l2){
		if(c[u]!=v && !fl){ //!fl
			
			sw(u,c[u]);
		}else {
			fl=1;
			sw(v,c[v]);
		}
		
	}
}
inline void _Sol_()
{
	read(n); F(i,1,n)read(c[i]); 
	F(i,1,n){
		if(c[i]==i){
			Vi[i]=1;
			fl=i;
			continue;
		}
		
		if(!Vi[i]){
			++ci;
			u=i;
			do{
				Vi[u]=1;
				V[ci].push_back(u);
				u=c[u];
			}while(u!=i);
		}
	}
	
	if(ci%2==1 && fl){
		++ci;
		V[ci].push_back(fl);
	}
	
	if(ci%2 == 1){
		if(ci == 1){
			int op=n-2,u=V[1][0],v=c[V[1][0]];
			
			F(i,1,op){
				sw(u,c[u]);
			}
			sw(v,c[u]);
			sw(u,c[u]);
			sw(u,c[u]);
			return;
		}
		for(int i=1;i<ci;i+=2)tr(i,i+1);
		V[ci+1].push_back(V[1][0]);
		tr(ci,ci+1);
		return;
	}
	for(int i=1;i<ci;i+=2)tr(i,i+1);
}

int main()
{
	int T=1; //read(T);
	while(T--)_Sol_();
	priE(tp);
	F(i,1,tp){
		pri_(st1[i]);priE(st2[i]);
	}
}