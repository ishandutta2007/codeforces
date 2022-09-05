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
const int N = 2333;
int n,a[N][N],tot;
int main() {
	read(n);//tot=16;
	memset(a,-1,sizeof(a));
	for(int i=1;i+3<=n;i+=4)
		for(int j=1;j+3<=n;j+=4){
			rep(x,i,i+3)rep(y,j,j+3)a[x][y]=tot++;
		}
//	rep(i,1,n)rep(j,1,n)a[i][j]=tot++;
	rep(i,1,n){
		int s=0;rep(j,1,n)s^=a[i][j];
		assert(s==0);
	}
	rep(j,1,n){
		int s=0;rep(i,1,n)s^=a[i][j];
		assert(s==0);
	}
	rep(i,1,n){
		rep(j,1,n)printf("%d ",a[i][j]);puts("");
	}
	return 0;
}