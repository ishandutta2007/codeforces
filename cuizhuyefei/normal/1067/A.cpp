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
const int N = 122000, mo = 998244353;
int n,a[N];
ll f[N][202][2];

int main() {
	read(n);rep(i,1,n)read(a[i]);
	if(a[1]==-1)rep(j,1,200)f[1][j][1]=1;else f[1][a[1]][1]=1;
	rep(i,2,n){
		ll sum=0;rep(j,1,200)sum+=f[i-1][j][0];
		ll qz0=0,qz1=0;
		rep(j,1,200){
			if(a[i]==-1||a[i]==j){
				f[i][j][0]=f[i-1][j][1]+sum-qz0;
				f[i][j][1]=qz0+qz1;
			}
			qz1+=f[i-1][j][1];qz0+=f[i-1][j][0];
		}
		rep(j,1,200)f[i][j][0]%=mo,f[i][j][1]%=mo;
	}
	ll res=0;rep(j,1,200)res+=f[n][j][0];res%=mo;res=(res+mo)%mo;
	cout<<res;return 0;
}