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
const int N = 3566,mo=1e9+7;
int len,p,alpha;char A[N];
int a[N],b[N],n,dp[N][N][2][2];
int calc(int mo){
	ll cur=0;
	per(i,len,1){
		cur=cur*10+a[i];
		a[i]=cur/mo;cur%=mo;
	}
	while(len&&!a[len])len--;
	return cur;
}
inline void trs(int &a, ll b){a=(a+b)%mo;}
inline int submod(int x){return x>=0?x:x+mo;}
inline int solve1(int r){//r<=2*(p-1)
	return r<=p-1?1LL*(r+1)*(r+2)/2%mo:(1LL*p*(r-p+1)+1LL*(r+2)*(p+p-r-1)/2)%mo;
}
inline int solve(int l, int r){
	umax(l,0);umin(r,2*(p-1));if(l>r)return 0;
	return submod(solve1(r)-(l-1>=0?solve1(l-1):0));
}
int main() {
	read(p);read(alpha);
	scanf("%s",A+1);len=strlen(A+1);rep(i,1,len)a[i]=A[i]-'0';reverse(a+1,a+len+1);
	if(p==1){ll x=calc(mo);cout<<(x+1)*(x+2)/2%mo<<endl;return 0;}
	while(len)b[++n]=calc(p);
//	per(i,n,1)cerr<<b[i];cerr<<endl;
	dp[n+1][0][1][0]=1;
	per(cur,n+1,2)rep(cnt,0,n+1){
		rep(i,0,1)if(dp[cur][cnt][0][i])rep(j,0,1)
			trs(dp[cur-1][cnt+j][0][j],1LL*dp[cur][cnt][0][i]*solve(-(j-p*i),-(j-p*i)+p-1));
		rep(i,0,1)if(dp[cur][cnt][1][i])rep(j,0,1)
			trs(dp[cur-1][cnt+j][1][j],1LL*dp[cur][cnt][1][i]*solve(-(j-p*i)+b[cur-1],-(j-p*i)+b[cur-1])),
			trs(dp[cur-1][cnt+j][0][j],1LL*dp[cur][cnt][1][i]*solve(-(j-p*i),-(j-p*i)+b[cur-1]-1));
	}
	int res=0;rep(i,alpha,n+1)trs(res,dp[1][i][0][0]+dp[1][i][1][0]);cout<<res;
	return 0;
}