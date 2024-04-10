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
const int N = 106;
int val[N][N],c[N],n;
int qry(int x1, int y1, int x2, int y2){
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);
	int x;read(x);return x;
}
bool isok(int x, int y){
	return x>=1&&x<=n&&y>=1&&y<=n&&val[x][y]==-1;
}
void dfs(int x, int y){
	rep(i,0,2)if(isok(x+i,y+2-i)){
		int tmp=qry(x,y,x+i,y+2-i);
		val[x+i][y+2-i]=tmp^1^val[x][y];
		dfs(x+i,y+2-i);
	}
	rep(i,0,2)if(isok(x-i,y-(2-i))){
		int tmp=qry(x-i,y-(2-i),x,y);
		val[x-i][y-(2-i)]=tmp^1^val[x][y];
		dfs(x-i,y-(2-i));
	}
}
void finish(){
	printf("!\n");
	rep(i,1,n){rep(j,1,n)printf("%d",val[i][j]);puts("");}
	fflush(stdout);
	exit(0);
}
int main() {
	read(n);memset(val,-1,sizeof(val));
	val[1][1]=1;val[n][n]=0;
	dfs(1,1);val[1][2]=0;dfs(1,2);
	rep(i,1,n)rep(j,1,n)if(i+2<=n&&j+1<=n)
		if(val[i+1][j]!=val[i][j+1]||val[i+2][j]!=val[i+1][j+1]){
			int tmp=qry(i,j,i+2,j+1);
			if((val[i][j]^tmp^1)!=val[i+2][j+1]){
				rep(x,1,n)rep(y,1,n)if(x+y&1)val[x][y]^=1;
			}
			finish();
		}
	rep(i,1,n)rep(j,1,n)c[i+j]=val[i][j];
	rep(i,1,n)rep(j,1,n)assert(val[i][j]==0||val[i][j]==1);
	rep(i,2,n*2-3)if((c[i]^c[i+1]^c[i+2]^c[i+3])==0){
		int x1,y1,x2,y2;
		rep(x,1,n)rep(y,1,n)if(x+y==i)x1=x,y1=y;
		rep(x,1,n)rep(y,1,n)if(x+y==i+3&&x>=x1&&y>=y1){x2=x,y2=y;break;}
		int tmp=qry(x1,y1,x2,y2);
		if((c[i]^tmp^1)!=c[i+3]){
			rep(x,1,n)rep(y,1,n)if(x+y&1)val[x][y]^=1;
		}
		finish();
	}
//	assert(0);
	return 0;
}