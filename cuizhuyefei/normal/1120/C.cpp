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
const int N = 5050;
int c[N][N],n,a,b,f[N];char s[N];
int main() {
	read(n);read(a);read(b);scanf("%s",s+1);
	rep(i,1,n)f[i]=1e9;
	per(i,n,1)per(j,n,1)c[i][j]=s[i]==s[j]?1+c[i+1][j+1]:0;
	rep(i,0,n-1){
		umin(f[i+1],f[i]+a);
		int lcp=0;rep(j,1,i)umax(lcp,min(c[j][i+1],i-j+1));
		umin(f[i+lcp],f[i]+b);
	}
	cout<<f[n];
	return 0;
}