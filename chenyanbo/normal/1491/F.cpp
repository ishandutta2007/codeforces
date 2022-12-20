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

#define N 4505
#define MO 
#define FF fflush(stdout); 


//order
int n,u,a,l,r,d[N];
//unordered_
set<int>S;

inline void _Sol_()
{
	int _T=0;
	read(n); S.clear();
	
	int T_=n+log2(n+0.001);
	
	F(i,1,n){
		printf("? 1 %d\n",n-i);
		printf("%d\n",i);
		F(j,i+1,n)printf("%d ",j);puts("");
		
		++_T;
		
		FF
		read(d[i]);
		if(d[i]){
			u=i;
			break;
		}
	}
	
	F(i,u+1,n-1){
		printf("? 1 1\n");
		printf("%d\n",u);
		printf("%d\n",i);
		
		++_T;
		
		FF
		read(a);
		d[u] -= a;
		if(!a)S.insert(i);
	}
	
//	cerr<<'*'<<u<<endl;
	
	if(!d[u])S.insert(n);
	l=1; r=u-1; a=0; int ss=0;
	while(l<=r){
		int mi=l+r>>1;
		printf("? 1 %d\n",mi);
		printf("%d\n",u);
		F(j,1,mi)printf("%d ",j);puts("");
		
		++_T;
		
		FF
		read(a);
		if(!a)l=mi+1; else ss=mi,r=mi-1;
	}
	
	//cerr<<ss<<'*'<<u<<endl;
	
	F2(i,1,u)if(i!=ss)S.insert(i);
	printf("! %d ",S.size());
	for(auto it=S.begin();it!=S.end();++it)printf("%d ",*it);
	puts("");FF
	
	if(_T > T_)while(1);
	
}

int main()
{
	int T=1; read(T);
	while(T--)_Sol_();
}
/*
1
4
-NSN
*/