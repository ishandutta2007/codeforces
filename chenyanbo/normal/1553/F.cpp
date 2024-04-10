#pragma GCC optimize("Ofast")
#pragma GCC target("avx") 
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

#define N 210005

#define O 1500
#define E 1000

#define D 300001
struct BIT {

int h[310005];
inline void ins(int p, int w)
{
	for(;p<=D;p+=lo(p)) h[p] += w;
}
int que(int l, int r)
{
	chmin(r,D);
	int ss=0;
	--l;for(;l;l-=lo(l)) ss-=h[l];
	for(;r;r-=lo(r)) ss+=h[r];
	return ss;
}

	
}T1;

struct BT {

long long h[310005];
inline void ins(int p, int w)
{
	for(;p<=D;p+=lo(p)) h[p] += w;
}
long long que(int l, int r)
{
	chmin(r,D);
	long long ss=0;
	--l;for(;l;l-=lo(l)) ss-=h[l];
	for(;r;r-=lo(r)) ss+=h[r];
	return ss;
}

	
}T,T2;

int n,k,si,a[N],H[N],G[N],Big;
long long Ans1,su,Ans2;


inline void _Sol_()
{
	read(n); 
	F(i,1,n)read(a[i]);
	F(i,1,n){
		k=a[i];
		//j % i
		
		if(a[i] <= O) {
			Ans1 += H[a[i]];
		}
		else {
			for(int j=0;j<=300000;j+=k){
				si = T1.que(j+1,j+k);
				su = T2.que(j+1,j+k);
				Ans1 += su;
				Ans1 -= (long long)j*si;
				
			}
		}
		T1.ins(a[i]+1,1);
		T2.ins(a[i]+1,a[i]);
		F(j,1,O){
			H[j] += a[i] % j; 
		}
		
		// i % j
		
		F(i,1,E) {
			Ans2 += (long long)k%i*G[i];
		}
		Ans2 += (long long)k*Big;
		Ans2 -= T.que(1,k+1);
		
		if(a[i] <= E) {
			++G[a[i]];
		} else {
			++Big;
			for(int j=k;j<=300000;j+=k)T.ins(j+1,k);
		}
		
		pri_(Ans1+Ans2);
	} 
}

int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	
	int T=1; //read(T);
	while(T--)_Sol_();
}