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
const int N = 1020;const double eps=1e-6;
int n,sx[N],tot;double p[N][N],dis[N],cur[N];
void upd(int u){
	sx[u]=++tot;
	rep(i,1,n)if(!sx[i])dis[i]+=cur[i]*p[i][u]*dis[u],cur[i]*=1-p[i][u];
}
int main() {
	read(n);rep(i,1,n)rep(j,1,n){
		int x;read(x);p[i][j]=x*0.01;
	}
	rep(i,1,n)cur[i]=1;rep(i,1,n-1)dis[i]=1;
	upd(n);
	while(tot<n){
		int p=0;rep(i,1,n)if(!sx[i]&&cur[i]<=1-eps&&(!p||dis[i]/(1-cur[i])<dis[p]/(1-cur[p])))p=i;
		dis[p]/=1-cur[p];
		upd(p);
	}
	printf("%.11lf\n",dis[1]);
	return 0;
}