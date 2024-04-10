#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 266666,SZ=7020;
bitset<SZ>l,r;int n,d,a[N];
int main() {
	read(n);read(d);rep(i,1,n)read(a[i]);
	int q,lst=0,lp=0,rp=0;read(q);
	while(q--){
		int x;read(x);l<<=x-lst;r>>=x-lst;lst=x;
		while(lp+1<=n&&a[lp+1]<x){
			if(x-a[lp+1]-1<SZ)l.set(x-a[lp+1]-1);lp++;
		}
		while(rp+1<=n&&a[rp+1]-x<SZ){
			if(a[rp+1]-x>=0)r.set(a[rp+1]-x);rp++;
		}
		double res=atan2(1,(l|r)._Find_first());
		umax(res,2*atan2(1,(l&r)._Find_first()));
		umax(res,2*atan2(1,((l>>1)&r)._Find_first()+1));
		umax(res,2*atan2(1,(l&(r>>1))._Find_first()+1));
		printf("%.11lf\n",res);
	}
	return 0;
}