#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 105;
int dp[N][N*N],n,k,a[N];
void solve(int l, int r, int k, int vl, int vr, int cons){
	if(l==r){a[l]=vl;return;}
	if(dp[r-l+1][k]>0){
		int cnt=dp[r-l+1][k];
		if(cons){
			rep(i,l,l+cnt-2)a[i]=vr--;
			solve(l+cnt-1,r,k-cnt*(cnt+1)/2+1,vl,vr,0);
		}
		else{
			rep(i,l,l+cnt-2)a[i]=vl++;
			solve(l+cnt-1,r,k-cnt*(cnt+1)/2+1,vl,vr,1);
		}
		return;
	}
	int cnt=-dp[r-l+1][k],nk=k-cnt;
	if(cnt&1){
		int lim=vl+(r-cnt/2)-(l+cnt/2);
		rep(i,0,cnt/2-1)a[l+i]=lim+(i+1)*2,a[r-i]=lim+i*2+1;
		solve(l+cnt/2,r-cnt/2,nk,vl,vl+(r-cnt/2)-(l+cnt/2),0);
	}
	else{
		int lim=vl+(r-cnt/2+1)-(l+cnt/2);
		rep(i,0,cnt/2-1)a[l+i]=lim+i*2+1;
		rep(i,0,cnt/2-2)a[r-i]=vr-i*2-1;
		solve(l+cnt/2,r-cnt/2+1,nk,vl,vl+(r-cnt/2+1)-(l+cnt/2),0);
	}
}
int main() {
	dp[1][1]=1;
	rep(n,1,100)rep(k,1,n*(n+1)/2){
		for(int i=2;i<=n&&!dp[n][k];i++)if(k-i*(i+1)/2+1>=0&&dp[n-i+1][k-i*(i+1)/2+1]){
			dp[n][k]=i;
		}
		for(int i=4;i<=n&&i<=k&&!dp[n][k];i++)if(dp[n-i+1][k-i]){
			dp[n][k]=-i;
		}
	}
	int q;read(q);while(q--){
		read(n);read(k);
		if(!dp[n][k])puts("NO");
		else{
			puts("YES");
			solve(1,n,k,1,n,0);
			rep(i,1,n)printf("%d ",a[i]);puts("");
		}
	}
	return 0;
}