#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 5050,inf=2e9;
int n,a[N],f[N][N],b[N];
inline int g(int x){return x<0?0:x+1;}
int main() {
	read(n);rep(i,1,n)read(a[i]);
	rep(i,0,n)rep(j,1,n)f[i][j]=inf;
//	rep(i,0,n)f[i][0]=0;
	rep(i,1,n)f[i][1]=g(a[i+1]-a[i])+g(a[i-1]-a[i]);
	rep(j,2,(n+1)/2){
		int mn=inf;
		rep(i,1,n){
			if(i-3>=0)mn=min(mn,f[i-3][j-1]);
			f[i][j]=min(mn+g(a[i+1]-a[i])+g(a[i-1]-a[i]),i-2>=0?f[i-2][j-1]+g(a[i+1]-a[i])+g(min(a[i-1],a[i-2]-1)-a[i]):inf);
		}
	}
	b[(n+3)/2]=inf;per(i,(n+1)/2,1){
		b[i]=b[i+1];
		rep(j,1,n)b[i]=min(b[i],f[j][i]);
	}
	rep(i,1,(n+1)/2)printf("%d ",b[i]);
	return 0;
}