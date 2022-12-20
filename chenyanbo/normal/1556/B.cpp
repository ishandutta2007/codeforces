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

#define N 200050
#define MO 

int a[N],u,ss,n;
ll Ans,Ans2;
inline void _Sol_()
{
	read(n); ss=0;
	F(i,1,n)read(a[i]),a[i]%=2,ss+=a[i];
	
	
	
	if(n%2==0){
		if(ss!=n/2){
			puts("-1");return;
		}
		Ans=0;
		u=1;
		F(i,1,n){
			if(a[i]){
				Ans+=abs(u-i);
				u+=2;
			}
		}
		Ans2=0;
		u=1;
		F(i,1,n){
			if(!a[i]){
				Ans2+=abs(u-i);
				u+=2;
			}
		}
		priE(min(Ans,Ans2));
		
		return;
	}
	
	if(ss<n/2 || ss>n/2+1){
		puts("-1");return;
	}
	
	if(ss==n/2){
		ss=n-ss;
		F(i,1,n)a[i]^=1;
	}
	Ans=0;
	u=1;
	F(i,1,n){
		if(a[i]){
			Ans+=abs(u-i);
			u+=2;
		}
	}
	priE(Ans);
}

int main()
{
	int T=1; read(T);
	while(T--)_Sol_();
}