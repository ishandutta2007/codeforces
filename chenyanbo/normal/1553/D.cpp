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

#define N 500050
#define MO 
char s[N],t[N];
int n,m,f0[N],f1[N],u,v;
inline void _Sol_()
{
	scanf("%s",s+1);
	scanf("%s",t+1);
	
	n=strlen(s+1);
	m=strlen(t+1);
	
	f0[0]=0; //ou
	f1[0]=0; //ji
	
	F(i,0,n)f0[i]=f1[i]=0;
	
	F(i,1,n){
		
		u=f0[i-1];
		v=f1[i-1];
			
			if(s[i]==t[u+1])chmax(f1[i],u+1);
			if(s[i]==t[v+1] && v%2==1)chmax(f0[i],v+1);			
			
		if(i>2){
			u=f0[i-2];
			v=f1[i-2];
			
			chmax(f0[i],u);
			chmax(f1[i],v);
		}
	}
	
	if(f0[n]==m || f1[n]==m)puts("YES");else puts("NO");
}

int main()
{
	int T=1; read(T);
	while(T--)_Sol_();
}
/*
1
aababa
ababa
*/