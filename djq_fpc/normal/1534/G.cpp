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
inline void read(long long &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
priority_queue<long long> ql;
priority_queue<long long,vector<long long>,greater<long long> > qr;
long long n,m,i,j,tagr;
long long res;
struct ii
{
	long long h,y;
}a[800005];
bool cmp(ii x,ii y)
{
	return x.h<y.h;
}
int main()
{
	read(n);
	fz1(i,n){
		long long x,y;
		read(x);read(y);
		a[i].h=(x+y);
		a[i].y=y;
	}
	sort(a+1,a+n+1,cmp);
	ql.push(a[1].y);
	qr.push(a[1].y);
	fz(i,2,n){
		tagr+=a[i].h-a[i-1].h;
		long long tl=ql.top(),tr=qr.top()+tagr;
		if(a[i].y<tl){
			qr.push(tl-tagr);
			ql.pop();
			ql.push(a[i].y);
			ql.push(a[i].y);
			res+=tl-ql.top();
			res+=abs(ql.top()-a[i].y);
		}
		else if(a[i].y>tr){
			ql.push(tr);
			qr.pop();
			qr.push(a[i].y-tagr);
			qr.push(a[i].y-tagr);
			res+=abs(ql.top()-a[i].y);
		}
		else{
			ql.push(a[i].y);
			qr.push(a[i].y-tagr);
		}
	}
	printf("%lld\n",res);
	return 0;
}