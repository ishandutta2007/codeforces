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
void solve(int i);
const int N = 666666;
int dx[]={1,-1,0,0,0,0};
int dy[]={0,0,1,-1,0,0};
int dz[]={0,0,0,0,1,-1};
int n,m,k,a[6][N],era[N];
int getbh(int x, int y, int z){
	return (x-1)*m*k+(y-1)*k+z;
}
void ck(int i, int j){
	int z=(i-1)%k+1;
	int y=(i-z)/k%m+1;
	int x=(i-z-(y-1)*k)/m/k+1;
	int rec=a[j][i];
	while(x>=1&&x<=n&&y>=1&&y<=m&&z>=1&&z<=k&&era[getbh(x,y,z)])x+=dx[j],y+=dy[j],z+=dz[j];
	if(x>=1&&x<=n&&y>=1&&y<=m&&z>=1&&z<=k)a[j][getbh(x,y,z)]=rec,solve(getbh(x,y,z));
	else if(rec>0){puts("-1");exit(0);}
}
void solve(int i){
	if(era[i])return;
	int v=0;bool ok=0;
	rep(j,0,5)if(!a[j][i]||a[j][i]>0&&v>0&&v!=a[j][i])ok=1;
	else if(a[j][i]>0)v=a[j][i];
	if(!ok)return;
	era[i]=1;//printf("erase %d\n",i);
	rep(j,0,5)if(a[j][i]>=0)ck(i,j);
}
int main() {
	read(n);read(m);read(k);
	rep(i,0,5)rep(j,1,n*m*k)a[i][j]=-1;
	rep(i,1,m)rep(j,1,k)read(a[0][getbh(1,i,j)]);
	rep(i,1,m)rep(j,1,k)read(a[1][getbh(n,i,j)]);
	rep(i,1,n)rep(j,1,k)read(a[2][getbh(i,1,j)]);
	rep(i,1,n)rep(j,1,k)read(a[3][getbh(i,m,j)]);
	rep(i,1,n)rep(j,1,m)read(a[4][getbh(i,j,1)]);
	rep(i,1,n)rep(j,1,m)read(a[5][getbh(i,j,k)]);
	rep(i,1,n*m*k)if(!era[i])solve(i);
	rep(x,1,n)rep(y,1,m)rep(z,1,k){
		int res=0;rep(i,0,5)if(a[i][getbh(x,y,z)]>0)res=a[i][getbh(x,y,z)];
		if(era[getbh(x,y,z)])res=0;//!!!
		printf("%d ",res);
	}
	return 0;
}