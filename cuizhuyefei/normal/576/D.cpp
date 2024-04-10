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
const int N = 153,inf=0x3f3f3f3f;
int n,m,c,e[N][N],w[N],dis[N],q[N];bool a[N];
struct mtr{
	bitset<153>a[N];
	inline void clear(){
		rep(i,0,n)a[i].reset();
	}
};
inline mtr mul(mtr b, mtr c){
	mtr a;a.clear();
	rep(i,1,n)rep(j,1,n)if(b.a[i][j])a.a[i]=a.a[i]|c.a[j];
	return a;
}
int main() {
	read(n);read(m);c=m;
	rep(i,1,n)rep(j,1,n)e[i][j]=inf;
	rep(i,1,m){
		int u,v,W;read(u);read(v);read(W);
		umin(e[u][v],W);w[i]=W;
	}
	sort(w+1,w+c+1);c=unique(w+1,w+c+1)-w-1;w[c+1]=inf;
	rep(u,1,n)rep(v,1,n)if(e[u][v]<inf)e[u][v]=lower_bound(w+1,w+c+1,e[u][v])-w;
	a[1]=1;
	for(int t=0;t<=c;t++){
		rep(i,1,n)dis[i]=inf;int f=0,r=1;dis[n]=0;q[f]=n;
		while(f!=r){
			int u=q[f++];
			rep(i,1,n)if(dis[i]>dis[u]+1&&e[i][u]<=t){
				q[r++]=i;dis[i]=dis[u]+1;
			}
		}
		int mn=inf+5;rep(i,1,n)if(a[i])umin(mn,dis[i]+w[t]);
		if(mn<w[t+1]){printf("%d\n",mn);return 0;}
		mtr I;I.clear();rep(i,1,n)rep(j,1,n)if(e[i][j]<=t)I.a[j][i]=1;
		int T=w[t+1]-w[t];
		while(T){
			if(T&1){
				static bool b[N];rep(i,1,n)b[i]=0;
				rep(i,1,n)rep(j,1,n)b[i]|=I.a[i][j]&a[j];
				rep(i,1,n)a[i]=b[i];
			}
			I=mul(I,I);T>>=1;
		}
	}
	puts("Impossible");
	return 0;
}