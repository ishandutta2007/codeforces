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
ll f[100];
map<long long, int>mp;
int n,c[N][2],sz[N],tot,a[N],u,v,cu[N];

void dfs(int p, int pr)
{
	sz[p] = 1; 
	for(int o=a[p]; o; o=c[o][1]){
		int u = c[o][0];
		if(u == pr)continue;
		dfs(u,p);
		sz[p] += sz[u];
	}
}

int df(int p, int pr,int n)
{
	
	
	
	for(int o=a[p]; o; o=c[o][1]){
		if(cu[o/2])continue;
		int u = c[o][0];
		if(u == pr)continue;
		if(mp[sz[u]] && mp[n-sz[u]]){
			cu[o/2]=1;
			sz[p] -= sz[u];
			return u;			
		}
		int op=df(u,p,n);
		if(op){
			sz[p] -= sz[op];
			return op;
		}
	}
	return 0;
}

void sol(int p, int n)
{
	if(n==1)return;
//	cerr<<p<<' '<<n<<endl;	
	int u=df(p,0,n);
	if(!u){
		puts("NO");
		exit(0);
	}
	sol(p,sz[p]);
	sol(u,sz[u]);
}

inline void _Sol_()
{
	read(n);
	f[1]=f[2]=1; mp[1]=1;
	F(i,3,50)f[i]=f[i-1]+f[i-2],mp[f[i]]=1;
	
	if(!mp[n]){
		puts("NO");return;
	}
	tot=1;
	F(i,1,n-1){
		read(u);read(v);
		c[++tot][0]=v;c[tot][1]=a[u];a[u]=tot;
		c[++tot][0]=u;c[tot][1]=a[v];a[v]=tot;
	}
	
	dfs(1,0);
	sol(1,n);
	puts("YES");
}

int main()
{
	int T=1; //read(T);
	while(T--)_Sol_();
}