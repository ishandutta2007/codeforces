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
const int N = 266;
int n,m,a[N][N],tot;char S[N][N];
bool ckrow(int i){
	rep(j,1,m)if(!a[i][j])return 0;
	return 1;
}
bool ckcol(int j){
	rep(i,1,n)if(!a[i][j])return 0;
	return 1;
}
int getans(){
	if(ckrow(1)||ckrow(n))return 1;
	if(ckcol(1)||ckcol(m))return 1;
	if(a[1][1]||a[1][m]||a[n][1]||a[n][m])return 2;
	rep(i,1,n)if(ckrow(i))return 2;
	rep(j,1,m)if(ckcol(j))return 2;
	int lm=0;rep(i,2,n-1)rep(j,2,m-1)lm+=a[i][j];
	if(lm==tot)return 4;
	return 3;
}
int main() {
	int T;read(T);while(T--){
		read(n);read(m);tot=0;
		rep(i,1,n)scanf("%s",S[i]+1);
		rep(i,1,n)rep(j,1,m)a[i][j]=S[i][j]=='A',tot+=a[i][j];
		if(!tot)puts("MORTAL");
		else if(tot==n*m)puts("0");
		else printf("%d\n",getans());
	}
	return 0;
}