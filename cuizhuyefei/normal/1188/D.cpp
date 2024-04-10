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
int n,s[N],qz[N];ll a[N],f[62][N];
int main() {
	read(n);rep(i,1,n)read(a[i]);
	sort(a+1,a+n+1);ll t=a[n];rep(i,1,n)a[i]=t-a[i];
	rep(j,0,60)rep(i,0,n)f[j][i]=1e18;f[0][0]=0;
	rep(i,1,n)s[i]=i;
	rep(i,0,59){
		rep(j,1,n)qz[j]=qz[j-1]+(a[s[j]]>>i&1);
		rep(j,0,n){
			umin(f[i+1][qz[j]],f[i][j]+j-qz[j]+qz[n]-qz[j]);
			umin(f[i+1][j+qz[n]-qz[j]],f[i][j]+qz[j]+n-j-(qz[n]-qz[j]));
		}
		static int t[N];int len=0;
		rep(j,1,n)if((a[s[j]]>>i&1))t[++len]=s[j];
		rep(j,1,n)if(!(a[s[j]]>>i&1))t[++len]=s[j];
		rep(j,1,n)s[j]=t[j];
	}
	cout<<f[60][0];
	return 0;
}