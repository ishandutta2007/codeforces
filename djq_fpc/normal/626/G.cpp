#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define incm(x,y) {x=((x)+(y))%mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
#define fi first
#define se second
#define mk make_pair
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,q,i,j,p[200005],l[200005],c[200005];
set<pair<double,int> > pq1;
set<pair<double,int> > pq2;
double f(int x,int y)
{
	if(y==-1) return -1e18;
	y=min(y,l[x]);
	return 1.0*p[x]*y/(l[x]+y);
}
double ans;
void inc()
{
	int x=pq1.rbegin()->second;
	pq1.erase(make_pair(f(x,c[x]+1)-f(x,c[x]),x));
	pq2.erase(make_pair(f(x,c[x])-f(x,c[x]-1),x));
	ans-=f(x,c[x]);ans+=f(x,++c[x]);
	pq1.insert(make_pair(f(x,c[x]+1)-f(x,c[x]),x));
	pq2.insert(make_pair(f(x,c[x])-f(x,c[x]-1),x));
}
void dec()
{
	int x=pq2.begin()->second;
	pq1.erase(make_pair(f(x,c[x]+1)-f(x,c[x]),x));
	pq2.erase(make_pair(f(x,c[x])-f(x,c[x]-1),x));
	ans-=f(x,c[x]);ans+=f(x,--c[x]);
	pq1.insert(make_pair(f(x,c[x]+1)-f(x,c[x]),x));
	pq2.insert(make_pair(f(x,c[x])-f(x,c[x]-1),x));
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	fz1(i,n){
		read(p[i]);
	}
	fz1(i,n){
		read(l[i]);
		c[i]=0;
		pq1.insert(make_pair(f(i,1)-f(i,0),i));
		pq2.insert(make_pair(f(i,0)-f(i,-1),i));
	}
	while(m--){
		inc();
	}
	while(q--){
		int op,x;
		read(op);read(x);
		pq1.erase(make_pair(f(x,c[x]+1)-f(x,c[x]),x));
		pq2.erase(make_pair(f(x,c[x])-f(x,c[x]-1),x));
		ans-=f(x,c[x]);
		l[x]+=(op==1?1:-1);
		ans+=f(x,c[x]);
		pq1.insert(make_pair(f(x,c[x]+1)-f(x,c[x]),x));
		pq2.insert(make_pair(f(x,c[x])-f(x,c[x]-1),x));
		while(pq1.rbegin()->first>pq2.begin()->first){
			dec();inc();
		}
		printf("%.10f\n",ans);
	}
	return 0;
}