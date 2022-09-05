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
const int N = 1<<17|3, mo = 1e9+7;
int f[N],g[N],n,all,s[N],dp1[N],dp2[N],dp3[N],dp[18][N],cnt[N];
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
inline void sub(int &x, int y){x=x-y>=0?x-y:x-y+mo;}
inline int power(int a, int n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo; n>>=1;
	}
	return res;
}
inline void fwt(int *a, int xs){
	for(int j=2;j<=(1<<n);j<<=1)for(int k=0;k<=all;k+=j)rep(i,0,(j>>1)-1){
		int x=a[k+i],y=a[k+i+(j>>1)];
		a[k+i]=x+y<mo?x+y:x+y-mo;a[k+i+(j>>1)]=x-y>=0?x-y:x-y+mo;
	}
	if(xs==-1){int ni=power(1<<n,mo-2);rep(i,0,all)a[i]=1LL*a[i]*ni%mo;}
}
inline void andfwt(int *a, int xs){
	if(xs==1){rep(i,0,n-1)per(j,all,0)if(!(j>>i&1))add(a[j],a[j^(1<<i)]);}
	else{rep(i,0,n-1)per(j,all,0)if(!(j>>i&1))sub(a[j],a[j^(1<<i)]);}
}
inline void orfwt(int *a, int xs){
	if(xs==1){rep(i,0,n-1)rep(j,0,all)if(j>>i&1)add(a[j],a[j^(1<<i)]);}
	else{rep(i,0,n-1)rep(j,0,all)if(j>>i&1)sub(a[j],a[j^(1<<i)]);}
}
int main() {
	int mx=0;read(n);rep(i,1,n){int x;read(x);s[x]++;umax(mx,x);}
	n=0;while((1<<n)-1<mx)n++;all=(1<<n)-1;
//	n=17;
	f[1]=1;rep(i,2,all)f[i]=(f[i-1]+f[i-2])%mo;
	rep(i,1,all)cnt[i]=cnt[i>>1]+(i&1);
	rep(i,0,all)dp[cnt[i]][i]=s[i];
	rep(i,0,n)orfwt(dp[i],1);
	rep(j,0,n){
		static ll g[N];memset(g,0,sizeof(g));
		rep(k,0,j)rep(p,0,all)g[p]+=1LL*dp[k][p]*dp[j-k][p];
		static int feed[N];rep(i,0,all)feed[i]=g[i]%mo;orfwt(feed,-1);
		rep(i,0,all)if(cnt[i]==j)dp1[i]=1LL*feed[i]*f[i]%mo;
	}
	rep(i,0,all)dp2[i]=1LL*s[i]*f[i]%mo;
	rep(i,0,all)g[i]=s[i];
	fwt(g,1);rep(i,0,all)g[i]=1LL*g[i]*g[i]%mo;fwt(g,-1);
	rep(i,0,all)dp3[i]=1LL*g[i]*f[i]%mo;
	andfwt(dp1,1);andfwt(dp2,1);andfwt(dp3,1);
	rep(i,0,all)dp1[i]=1LL*dp1[i]*dp2[i]%mo*dp3[i]%mo;andfwt(dp1,-1);
	int res=0;rep(i,0,n-1)add(res,dp1[1<<i]);cout<<res;
	return 0;
}