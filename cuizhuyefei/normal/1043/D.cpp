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
const int N = 102000;
int a[15][N],p[15][N],n,m,f[N];ll res;
int main() {
	read(n);read(m);
	rep(i,1,m)rep(j,1,n)read(a[i][j]),p[i][a[i][j]]=j;
	per(i,n,1){//f[a[1][i]]<--f[a[1][i+1]]
		bool ok=1;if(i==n)ok=0;
		rep(j,2,m)ok&=(a[j][p[j][a[1][i]]+1]==a[1][i+1]);
		if(!ok)f[i]=1;
		else f[i]=f[i+1]+1;
	}
	rep(i,1,n)res+=f[i];cout<<res;
	return 0;
}