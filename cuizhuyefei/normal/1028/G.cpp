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
const ll lim = 10004205361450474LL;
ll f[10005][6],p[10005];int n=9999;
int main() {
	rep(i,0,n)f[i][1]=i+1;
	rep(i,1,5){
		rep(x,0,n){
			p[0]=x;
			rep(j,1,x+2){
				p[j]=p[j-1]+1+f[min(1LL*n,p[j-1])][i-1];
				if(p[j]>n){p[x+2]=p[j]+(1LL+f[n][i-1])*(x+2-j);break;}
			}
			f[x][i]=p[x+2]-x-1;
		}
	}
//	cerr<<f[0][5]<<endl;
	ll l=1,r=lim;int i=5;
	while(i){
		int x=min(1LL*n,l-1);//f[x][i]
		p[0]=l-1;
		rep(j,1,x+2)p[j]=p[j-1]+1+f[min(1LL*n,p[j-1])][i-1];
		printf("%d ",x+1);rep(j,1,x+1)printf("%lld ",p[j]);puts("");fflush(stdout);
		int c;read(c);if(c==-1){return 0;}l=p[c]+1;r=p[c+1]-1;
		i--;
	}
	return 0;
}