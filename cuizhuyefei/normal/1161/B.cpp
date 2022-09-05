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
const int N = 233333;
int n,m;Pii a[N],b[N];
int M(int x){return x%n?x%n:n;}
void ck(int x){
	rep(i,1,m){
		b[i]=Pii(M(a[i].fi+x),M(a[i].se+x));
		if(b[i].fi>b[i].se)swap(b[i].fi,b[i].se);
	}
	sort(b+1,b+m+1);
	rep(i,1,m)if(a[i]!=b[i])return;
	puts("Yes");exit(0);
}
int main() {
	read(n);read(m);
	rep(i,1,m){
		read(a[i].fi),read(a[i].se);
		if(a[i].fi>a[i].se)swap(a[i].fi,a[i].se);
	}
	sort(a+1,a+m+1);
	int x=n;
	for(int i=2;i*i<=x;i++)if(x%i==0){
		ck(n/i);while(x%i==0)x/=i;
	}
	if(x>1)ck(n/x);
	
	puts("No");
	return 0;
}