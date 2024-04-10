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

#define N 400004
#define MO 
int l,r,s[N],h[N],mi[N],a[N],n,k,ss;
inline int ch(int p)
{
	F(i,1,n)if(a[i]<p)h[i]=-1;else h[i]=1;
	F(i,1,n)s[i]=s[i-1]+h[i];
	mi[1]=min(0,s[1]);
	F(i,2,n)mi[i]=min(mi[i-1],s[i]);
	ss=0;
	F(i,1,n){
		ss+=h[i];
		if(i>=k){
			if(ss-mi[i-k] > 0){
				return 1;
			}
		}
	}
	return 0;
}

inline void _Sol_()
{
	read(n);read(k);
	F(i,1,n){
		read(a[i]);
	} 
	l=1; r=n; int ss;
	while(l<=r){
		int mi=l+r>>1;
		if(ch(mi))ss=mi,l=mi+1;else r=mi-1;
	}
	priE(ss);
}

int main()
{
	int T=1; //read(T);
	while(T--)_Sol_();
}