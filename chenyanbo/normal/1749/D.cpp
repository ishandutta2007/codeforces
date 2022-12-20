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

#define N 500500
#define MO 998244353
ll Ans,G,O,n,m,_Ans,A,p[N];

inline int ksm(int p, int k)
{
	static int vv[70];
	vv[0]=p; int s=1;
	for(int i=1; i<=29; ++i)vv[i]=(long long)vv[i-1]*vv[i-1]%MO;
	for(int i=29; i>=0; --i){
		if(k>=1<<i){
			k-=1<<i;
			s=(long long)s*vv[i]%MO;
		}
	}
	return s;
}
inline void _Sol_()
{
	read(n); read(m);
	for(int i=2;i<=n;++i)
	for(int j=i+i;j<=n;j+=i)p[j]=1;
	Ans = 1; G=1;
	F(i,1,n){
		if(Ans){
			if(!p[i]){
				O = __gcd(G,(ll)i);
				G /= O;
				if(G*i > m){
					Ans = 0; 
				}
				else G*=i;
			}
			Ans=Ans*(m/G%MO)%MO;
		}
		_Ans=ksm(m%MO,i);
		A = (A+_Ans)%MO;
		A = (A+MO-Ans)%MO;
	}

	priE(A);
}

int main()
{
	int T=1; //read(T);
	while(T--)_Sol_();
}