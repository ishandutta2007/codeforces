#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<string>
#define fi first
#define se second
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
int n,a[35][35],v[35][35],res=-1e9;
inline int gv(int x, int y, int c){return v[x][y]*(c?-1:1);}
inline void update(int s){
	memset(a,0,sizeof(a)); int m=(n+1)/2;
	rep(i,1,m)a[m][i]=(s>>i-1)&1;rep(i,m+1,n)a[m][i]=a[m][i-m]^a[m][m];
	int now=0;rep(i,1,n)now+=gv(m,i,a[m][i]);
	rep(i,1,m-1){
		a[i][m]=0;a[i+m][m]=a[i][m]^a[m][m];int v0=gv(i,m,a[i][m])+gv(i+m,m,a[i+m][m]);
		rep(j,1,m-1){
			int t0=gv(i,j,0)+gv(i,j+m,0^a[i][m])+gv(i+m,j,0^a[m][j])+gv(i+m,j+m,0^a[i][m]^a[m][j+m]);
			int t1=gv(i,j,1)+gv(i,j+m,1^a[i][m])+gv(i+m,j,1^a[m][j])+gv(i+m,j+m,1^a[i][m]^a[m][j+m]);
			v0+=max(t0,t1);
		}
		a[i][m]=1;a[i+m][m]=a[i][m]^a[m][m];int v1=gv(i,m,a[i][m])+gv(i+m,m,a[i+m][m]);
		rep(j,1,m-1){
			int t0=gv(i,j,0)+gv(i,j+m,0^a[i][m])+gv(i+m,j,0^a[m][j])+gv(i+m,j+m,0^a[i][m]^a[m][j+m]);
			int t1=gv(i,j,1)+gv(i,j+m,1^a[i][m])+gv(i+m,j,1^a[m][j])+gv(i+m,j+m,1^a[i][m]^a[m][j+m]);
			v1+=max(t0,t1);
		}
		now+=max(v0,v1);
	}
	res=max(res,now);
}
int main() {
//	freopen("4.in","r",stdin); //freopen("s.out","w",stdout);
	read(n); rep(i,1,n)rep(j,1,n)read(v[i][j]);
	rep(i,0,(1<<(n+1)/2)-1)update(i);
	cout<<res;
	return 0;
}