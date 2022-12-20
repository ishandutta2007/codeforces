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

#define N 100050 
#define MO 
#define FF fflush(stdout);


int n,k,x1,x2,x3,y1,y2,y3,a[N];
inline void _Sol_()
{
	read(n);read(k);
	
	puts("or 1 2"); FF read(x1);
	puts("or 1 3"); FF read(x2);
	puts("or 2 3"); FF read(x3);
	
	puts("and 1 2"); FF read(y1);
	puts("and 1 3"); FF read(y2);
	puts("and 2 3"); FF read(y3);
	
	dF(i,29,0){
		
		////00
		if((x1>>i)%2==0){
			if((x2>>i)&1){
				a[3]+=1<<i;
			}
			continue;
		}
		
		/////11
		if((y1>>i)&1){
			a[1]+=1<<i;
			a[2]+=1<<i;
			if((y2>>i)&1){
				a[3]+=1<<i;
			}
			continue;
		}
		
		/////101
		if((y2>>i)&1){
			a[1]+=1<<i; a[3]+=1<<i;
			continue;
		}
		
		/////011
		if((y3>>i)&1){
			a[2]+=1<<i; a[3]+=1<<i;
			continue;
		}
		
		
		
		///100
		
		if((x3>>i)%2==0){
		
			a[1] +=1<<i;
			continue;
		}
		
		
		//010
		a[2]+=1<<i;
	}
	
	F(i,4,n){
		printf("or 1 %d\n",i); FF read(x1);
		printf("and 1 %d\n",i); FF read(y1);
		a[i]=x1^y1^a[1];
	}
	sort(a+1,a+n+1);
	printf("finish ");priE(a[k]);
	FF
}

int main()
{
	int T=1; //read(T);
	while(T--)_Sol_();
}