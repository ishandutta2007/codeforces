#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 255;
int n,m,v[2][N*N],a[N][N],aa[N][N],b[N],c[N];
Pii d[N*N];int len;
bool cmp(Pii a, Pii B){return min(b[a.fi],c[a.se])<min(b[B.fi],c[B.se]);}
int main() {
	read(n);read(m);
	rep(i,1,n)rep(j,1,m){
		read(a[i][j]);aa[j][i]=a[i][j];
	}
	rep(i,1,n)v[0][*max_element(a[i]+1,a[i]+m+1)]=1;
	rep(i,1,m)v[1][*max_element(aa[i]+1,aa[i]+n+1)]=1;
	int x=0,y=0;memset(a,0,sizeof(a));
	rep(i,1,max(n,m))b[i]=c[i]=1e9;
	per(i,n*m,1)if(v[0][i]||v[1][i]){
		if(v[0][i])x++;
		if(v[1][i])y++;
		a[x][y]=i;
		if(v[0][i])umin(b[x],i);
		if(v[1][i])umin(c[y],i);
	}
//	rep(i,1,n)rep(j,1,m)if(!a[i][j])d[++len]=mp(i,j);
//	sort(d+1,d+len+1,cmp);
	static int qz[N],hz[N];
	rep(i,1,n)rep(j,1,m)if(!a[i][j])qz[i]=j;else break;
	rep(i,1,n){hz[i]=m+1;per(j,m,1)if(!a[i][j])hz[i]=j;else break;}
	/*rep(i,1,n)printf("%d:%d %d\n",i,qz[i],hz[i]);
	rep(i,1,n)rep(j,1,m){
		printf("%d%c",a[i][j],j<m?' ':'\n');
	}*/
	per(x,n*m,1)if(!(v[0][x]||v[1][x])){
	//	assert(i<=min(b[d[len].fi],c[d[len].se]));
	//	printf("%d:%d\n",i,min(b[d[len].fi],c[d[len].se]));
		//a[d[len].fi][d[len].se]=i,len--;
		bool fd=0;
		rep(i,1,n)if(!fd&&qz[i]&&x<=min(b[i],c[qz[i]]))
			fd=1,a[i][qz[i]]=x,qz[i]--;
		per(i,n,1)if(!fd&&hz[i]<=m&&x<=min(b[i],c[hz[i]]))
			fd=1,a[i][hz[i]]=x,hz[i]++;
		/*rep(i,1,n)rep(j,1,m){
			printf("%d%c",a[i][j],j<m?' ':'\n');
		}
		puts("");*/
		assert(fd);
	}
	rep(i,1,n)rep(j,1,m){
		printf("%d%c",a[i][j],j<m?' ':'\n');
	}
	return 0;
}