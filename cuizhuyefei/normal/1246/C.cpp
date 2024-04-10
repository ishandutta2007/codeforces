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
const int N = 2266,mo=1e9+7;
int n,m;char s[N][N];
int d[N][N],r[N][N],f[N][N],g[N][N],qzd[N][N],qzr[N][N];
inline int getmod(int x){return x<mo?x:x-mo;}
void upd(int x, int y){
	qzr[x][y]=getmod(qzr[x][y-1]+r[x][y]);
	qzd[x][y]=getmod(qzd[x-1][y]+d[x][y]);
}
int main() {
	read(n);read(m);rep(i,1,n)scanf("%s",s[i]+1);
	if(n==1&&m==1){puts("1");return 0;}
	rep(i,1,n){
		static int hz[N];
		hz[m+1]=0;per(j,m,1)hz[j]=hz[j+1]+(s[i][j]=='R');
		for(int j=1,k=1;j<=m;j++){
			while(hz[k+1]>m-j)k++;
			f[i][j]=k;
		}
	}
	rep(j,1,m){
		static int hz[N];
		hz[n+1]=0;per(i,n,1)hz[i]=hz[i+1]+(s[i][j]=='R');
		for(int i=1,k=1;i<=n;i++){
			while(hz[k+1]>n-i)k++;
			g[i][j]=k;
		}
	}
	d[1][1]=r[1][1]=1;upd(1,1);
	rep(i,1,n)rep(j,1,m)if(i+j>2){
		d[i][j]=getmod(qzr[i][j-1]-qzr[i][f[i][j]-1]+mo);
		r[i][j]=getmod(qzd[i-1][j]-qzd[g[i][j]-1][j]+mo);
		upd(i,j);
	}
	cout<<getmod(d[n][m]+r[n][m]);
	return 0;
}