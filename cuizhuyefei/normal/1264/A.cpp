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
int n,p[N],ok[N];

int main() {
	int T;read(T);while(T--){
		read(n);rep(i,1,n)read(p[i]);
		rep(i,1,n-1)ok[i]=p[i]>p[i+1];ok[n]=0;
		int x=0,y=0,z=0;
		per(i,n-1,1)if(ok[i])x=i;
		rep(i,1,n/2)if(ok[i])z=i;
		rep(i,2*x+1,z-1)if(ok[i]){y=i;break;}
		if(x&&y&&z&&x<y&&y<z&&x<y-x&&x<z-y)printf("%d %d %d\n",x,y-x,z-y);
		else puts("0 0 0");
	}
	return 0;
}