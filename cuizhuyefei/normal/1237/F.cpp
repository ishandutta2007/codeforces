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
const int N = 3666,mo=998244353;
int fac[N],C[N][N],n,m,cnt;bool A[N],B[N];
struct yzr{
	int sum,dp[N],dp1[N];
	void ini(int n, bool *gg){
		dp[0]=1;rep(l,1,n)if(!gg[l]){
			int r=l;while(r+1<=n&&!gg[r+1])r++;
			sum+=r-l+1;//[l,r]
			memset(dp1,0,sizeof(dp1));
			rep(j,0,n)if(dp[j])per(i,(r-l+1)/2,0){
				dp1[j+i]=(dp1[j+i]+1LL*dp[j]*C[r-l+1-i][i])%mo;
			}
			memcpy(dp,dp1,sizeof(dp1));
			l=r;
		}
	}
	int solve(int x, int y){
		return sum-x*2>=y?1LL*dp[x]*C[sum-x*2][y]%mo:0;
	}
}a,b;
int main() {
	read(n);read(m);read(cnt);
	fac[0]=1;rep(i,1,max(n,m)+2)fac[i]=1LL*fac[i-1]*i%mo;
	rep(i,0,max(n,m)+2){
		C[i][0]=C[i][i]=1;
		rep(j,1,i-1)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	}
	while(cnt--){
		int x,y;read(x);read(y);A[x]=B[y]=1;
		read(x);read(y);A[x]=B[y]=1;
	}
	a.ini(n,A);b.ini(m,B);int res=0;
	rep(i,0,n/2)rep(j,0,n-i*2)
		res=(res+1LL*a.solve(i,j)*b.solve(j,i)%mo*fac[i]%mo*fac[j])%mo;
	cout<<res<<endl;
	return 0;
}