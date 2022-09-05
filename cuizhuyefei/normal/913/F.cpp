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
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 2333, mo = 998244353;
int n,p[N],g[N][N],f[N],mi1[N],mi2[N];
int power(int a, int n){
	int res=1;
	while(n){if(n&1)res=1LL*res*a%mo;a=1LL*a*a%mo;n>>=1;}
	return res;
}
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
inline void sub(int &x, int y){x=x-y>=0?x-y:x-y+mo;}
int main() {
	read(n);int a,b;read(a);read(b);int P=1LL*a*power(b,mo-2)%mo;
	mi1[0]=1;rep(i,1,n)mi1[i]=1LL*mi1[i-1]*P%mo;//WA
	mi2[0]=1;rep(i,1,n)mi2[i]=1LL*mi2[i-1]*(1+mo-P)%mo;
	g[0][0]=1;
	rep(i,0,n)rep(j,0,i)if(g[i][j])
		add(g[i+1][j],1LL*g[i][j]*mi1[j]%mo),add(g[i+1][j+1],1LL*g[i][j]*mi2[i-j]%mo);
	rep(i,1,n){
		p[i]=1;rep(j,1,i-1)sub(p[i],1LL*p[j]*g[i][j]%mo);
	}
	rep(i,2,n){
		int c=1LL*i*(i-1)%mo;
		rep(j,1,i-1)add(c,1LL*p[j]*g[i][j]%mo*((f[j]+f[i-j]-1LL*(i-j)*(i-j-1))%mo)%mo);
		f[i]=1LL*c*power(1-p[i]+mo,mo-2)%mo;f[i]=(f[i]+mo)%mo;
		//printf("%d:%d\n",i,f[i]);
	}
	cout<<1LL*f[n]*((mo+1)/2)%mo;
	//rep(i,1,n)rep(j,1,i)printf("%d %d:%d\n",i,j,g[i][j]);
	//rep(i,1,n)printf("%d:%d\n",i,p[i]);
	
	return 0;
}