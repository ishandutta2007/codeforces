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

#define N 5006
#define MO 
long long Ans;
int a[N],f[N],u,v,g,n;
int fid(int p)
{
	if(p > n)return 0;
	if(f[p]==p)return p;
	return f[p]=fid(f[p]);
}
inline void _Sol_()
{
	Ans=0;
	read(n);F(i,1,n)read(a[i]);
	
	F(i,1,n)f[i]=i;
		
	F(i,1,n){
		if(i+a[i] > n){
			Ans += i+a[i]-n-1;
			a[i] = n-i+1;
		}
		while(a[i] > 1){
			
//			F(i,1,n)pri_(a[i]);puts("");
			
			++Ans;
			u=i;
			while(1){
				
				
				
				if(a[u]==1){
					v=fid(u+1);
					u=fid(u);
					if(v)f[u]=v;
				}
				v=u+a[u];
				
			//	cerr<<u<<'*'<<v<<'*'<<a[u]<<' '<<f[2]<<endl;
				if(a[u]>2)--a[u];else {
					if(a[u]==2){
						a[u]=1;
						g=fid(u+1);
						if(g)f[u]=g;
					}
				}
				if(v>n)break;
				u=v;
			}
		}
	}
	priE(Ans);
}

int main()
{
	int T=1; read(T);
	while(T--)_Sol_();
}