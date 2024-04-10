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
mt19937 R(chrono::system_clock().now().time_since_epoch().count());
const int N = 4200,inf=0x3f3f3f3f;
int n,m,l[N],s[N],c[N],f[2][N][N],mx[N];
Vi a[N];
int main() {
	read(n);read(m);
	rep(i,1,n)read(l[i]),mx[l[i]]++,a[l[i]].pb(i);
	rep(i,1,n)read(s[i]);
	rep(i,1,n+m)read(c[i]);
	rep(i,1,n+m)mx[i]+=mx[i-1]/2;
	rep(i,0,1)rep(j,0,n)rep(k,0,n+1)f[i][j][k]=-inf;
	f[1][0][n+1]=0;
	rep(v,1,n+m){
		int p=v&1,q=p^1;//p-->q
		rep(cnt,0,max(mx[v],mx[v+1]))rep(lst,1,n+1)f[q][cnt][lst]=-inf;
		rep(cnt,0,mx[v])per(lst,n+1,1)if(f[p][cnt][lst]>-inf){
			umax(f[q][cnt/2][lst],f[p][cnt][lst]+cnt*c[v]);
			for(int i=0;i<SZ(a[v])&&a[v][i]<lst;i++)
				umax(f[p][cnt+1][a[v][i]],f[p][cnt][lst]-s[a[v][i]]);
		}
	//	rep(cnt,0,mx[v])per(lst,n+1,1)if(f[p][cnt][lst]>-inf)
	//		printf("%d %d %d:%d\n",v,cnt,lst,f[p][cnt][lst]);
	}
	int res=-inf;rep(i,1,n+1)umax(res,f[n+m+1&1][0][i]);
	cout<<res;
	return 0;
}