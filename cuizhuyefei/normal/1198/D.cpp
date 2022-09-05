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
const int N = 55,inf=0x3f3f3f3f;
int n;char s[N][N];
int f[N][N][N][N];
int main() {
	read(n);rep(i,1,n)scanf("%s",s[i]+1);
//	memset(f,inf,sizeof(f));
	per(l1,n,1)rep(r1,l1,n)per(l2,n,1)rep(r2,l2,n){
		f[l1][r1][l2][r2]=max(r1-l1+1,r2-l2+1);
		if(r1-l1>r2-l2){
			rep(m,l1,r1-1)umin(f[l1][r1][l2][r2],f[l1][m][l2][r2]+f[m+1][r1][l2][r2]);
		}
		else{
			rep(m,l2,r2-1)umin(f[l1][r1][l2][r2],f[l1][r1][l2][m]+f[l1][r1][m+1][r2]);
		}
		if(l1==r1&&l2==r2)f[l1][r1][l2][r2]=s[l1][l2]=='#';
	}
	printf("%d\n",f[1][n][1][n]);
	return 0;
}