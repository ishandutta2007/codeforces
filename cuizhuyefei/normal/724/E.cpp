#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register ll i=(a); i<=(b); i++)
#define per(i,a,b) for (register ll i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 23333;const ll inf = 1e16;
ll n,c,a[N],b[N],f[2][N];//-1e9..-1
int main() {
	read(n);read(c);rep(i,1,n)read(a[i]);rep(i,1,n)read(b[i]);
	f[0][0]=0;
	rep(i,0,n-1){
		int p=i&1,q=p^1;rep(j,0,i+1)f[q][j]=inf;
		//memset(f[q],0,sizeof(ll)*(n+2));
		rep(j,0,i){
			f[q][j]=min(f[q][j],f[p][j]+a[i+1]+j*c);
			f[q][j+1]=min(f[q][j+1],f[p][j]+b[i+1]);
		}
	}
	ll res=inf;rep(i,0,n)res=min(res,f[n&1][i]);cout<<res;
	return 0;
}