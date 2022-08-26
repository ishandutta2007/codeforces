#include<bits/stdc++.h>
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
#include<cassert>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j,a[200005];
struct ii{long long x,y;long long f(long long k){return x*k+y;}};
__int128 crs(ii x,ii y)
{
	return ((__int128)x.x)*y.y-((__int128)x.y)*y.x;
}
ii operator -(ii x,ii y)
{
	return (ii){x.x-y.x,x.y-y.y};
}
struct que
{
	ii qx[200005];int ql,qr;
	void clear(){ql=1;qr=0;}
	void push(ii x)
	{
		while(ql<qr&&crs(qx[qr]-qx[qr-1],x-qx[qr])<=0) qr--;
		qx[++qr]=x;
	}
	long long query(long long x)
	{
		if(ql>qr) return 5e18;
		while(ql<qr&&qx[ql].f(x)>=qx[ql+1].f(x)) ql++;
		return qx[ql].f(x);
	}
}q1,q2,q3,q4; // +r,-l
struct sta
{
	ii qx[200005];int tp;
	void clear(){tp=0;}
	void push(ii x)
	{
		while(1<tp&&crs(qx[tp]-qx[tp-1],x-qx[tp])<=0) tp--;
		qx[++tp]=x;
	}
	long long query(long long x)
	{
		if(1>tp) return 5e18;
		while(1<tp&&qx[tp].f(x)>=qx[tp-1].f(x)) tp--;
		return qx[tp].f(x);
	}
}s1,s2,s3,s4; // +l,-r
long long calc(long long t)
{
	long long res=0;int l=2,r=n;
	q1.clear();q2.clear();q3.clear();q4.clear();
	s1.clear();s2.clear();s3.clear();s4.clear();
	if(a[1]+t>=0) s1.push((ii){a[1]+t,1ll*a[1]*t}),q1.push((ii){a[1]+t,1ll*a[1]*t});
	else s2.push((ii){a[1]+t,1ll*a[1]*t}),q2.push((ii){a[1]+t,1ll*a[1]*t});
	while(l<=r){
		long long mi=5e18,tmp;int typ=-1;
		tmp=q1.query(a[l]);if(tmp<mi) mi=tmp,typ=1;
		tmp=q2.query(a[l]);if(tmp<mi) mi=tmp,typ=1;
		tmp=q3.query(a[l]);if(tmp<mi) mi=tmp,typ=1;
		tmp=q4.query(a[l]);if(tmp<mi) mi=tmp,typ=1;
		tmp=s1.query(a[l]);if(tmp<mi) mi=tmp,typ=1;
		tmp=s2.query(a[l]);if(tmp<mi) mi=tmp,typ=1;
		tmp=s3.query(a[l]);if(tmp<mi) mi=tmp,typ=1;
		tmp=s4.query(a[l]);if(tmp<mi) mi=tmp,typ=1;
		tmp=q1.query(a[r]);if(tmp<mi) mi=tmp,typ=2;
		tmp=q2.query(a[r]);if(tmp<mi) mi=tmp,typ=2;
		tmp=q3.query(a[r]);if(tmp<mi) mi=tmp,typ=2;
		tmp=q4.query(a[r]);if(tmp<mi) mi=tmp,typ=2;
		tmp=s1.query(a[r]);if(tmp<mi) mi=tmp,typ=2;
		tmp=s2.query(a[r]);if(tmp<mi) mi=tmp,typ=2;
		tmp=s3.query(a[r]);if(tmp<mi) mi=tmp,typ=2;
		tmp=s4.query(a[r]);if(tmp<mi) mi=tmp,typ=2;
		res+=mi;int p=0;
		if(typ==1){
			p=l++;
			if(a[p]+t>=0) s1.push((ii){a[p]+t,1ll*a[p]*t}),q1.push((ii){a[p]+t,1ll*a[p]*t});
			else s2.push((ii){a[p]+t,1ll*a[p]*t}),q2.push((ii){a[p]+t,1ll*a[p]*t});
		}
		else{
			p=r--;
			if(a[p]+t>=0) s3.push((ii){a[p]+t,1ll*a[p]*t}),q3.push((ii){a[p]+t,1ll*a[p]*t});
			else s4.push((ii){a[p]+t,1ll*a[p]*t}),q4.push((ii){a[p]+t,1ll*a[p]*t});
		}
	}
//	cerr<<t<<' '<<res<<endl;
	return res;
}
void solve()
{
	read(n);fz1(i,n) read(a[i]);sort(a+1,a+n+1);
	long long l=-2.05e12,r=2.05e12,mid;
	if(calc(l-1)>calc(l)||calc(r+1)>calc(r)){
		puts("INF");return;
	}
	while(l<r){
		mid=((l+r)>>1);
		if(calc(mid)<calc(mid+1)) l=mid+1; else r=mid;
	}
	printf("%lld\n",calc(l));
}
int main()
{
	int t;
	read(t);
	while(t--){
		solve();
	}
	return 0;
}