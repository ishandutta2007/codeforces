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
const int N = 666666;
int n,a[N];
bool ck1(){
	per(i,n,1)if(a[n]-(n-i)>=1&&a[i]!=a[n]-(n-i))return 0;
	rep(i,1,n)if(a[n]-(n-i)<1&&a[i]&&a[i]+n-a[n]-i<=n)return 0;
	return 1;
}
int main() {
	read(n);rep(i,1,n)read(a[i]);
	rep(i,1,n)read(a[i]);
	if(a[n]&&ck1()){
		printf("%d",n-a[n]);return 0;
	}
	int res=n+1;
	rep(i,1,n)if(a[i])umax(res,i+n+1-(a[i]-1));
	printf("%d",res+n-1-n);
	return 0;
}