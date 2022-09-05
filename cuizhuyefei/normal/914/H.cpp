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
const int N = 205;
int n,d;ll dp[N],f[N][N],C[N][N];int mo;
inline void add(ll&a,ll b){a=a+b<mo?a+b:a+b-mo;}
int main() {
	read(n);read(d);read(mo);f[0][0]=1;
	if(d==1){
		if(n>=3){puts("0");return 0;}
	}
	rep(i,0,n){
		C[i][0]=C[i][i]=1;
		rep(j,1,i-1)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	}
	rep(i,1,n){
		rep(j,1,d-1)add(dp[i],f[j][i-1]);if(i==1)dp[i]=1;
		rep(j,1,i)rep(k,1,i)
			f[j][i]=(f[j][i]+1LL*C[i-1][k-1]*dp[k]%mo*f[j-1][i-k])%mo;
	//	printf("%d:%d\n",i,dp[i]);
	//	rep(j,1,i)printf("%d %d : %d\n",j,i,f[j][i]);
	}
	ll res=0;
	rep(p,1,n)rep(i,0,d)if(i!=1)rep(j,0,d-i)res=(res+1LL*f[i][p-1]*f[j][n-p])%mo;
	res=2LL*res*n*(n-1)%mo;
	cout<<(res%mo+mo)%mo;
	return 0;
}