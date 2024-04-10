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
const int N = 309,mo=10007;
char s[N];int len,n,f[205][205][205],dp[N],sz;
struct mtr{
	int a[N][N];
}A;
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
inline mtr mul(const mtr &a,const mtr &b){
	mtr c;memset(c.a,0,sizeof(c.a));
	rep(i,0,sz)rep(k,0,i)rep(j,0,k)
		c.a[i][j]=(c.a[i][j]+1LL*a.a[i][k]*b.a[k][j])%mo;
	return c;
}
void upd(int x, int y, int w){if(!w)return;
//	cerr<<"upd "<<x<<' '<<y<<' '<<w<<endl;
	if(x)add(A.a[sz-y][x-1],w);else add(dp[sz-y],w);
}
int main() {
	scanf("%s",s+1);len=strlen(s+1);read(n);n=(n+len);
	f[1][len][0]=1;
	rep(l,1,len)per(r,len,l)rep(i,0,len)if(f[l][r][i]){
		if(s[l]==s[r])add(f[l+1][r-1][i],f[l][r][i]);
		else add(f[l][r-1][i+1],f[l][r][i]),add(f[l+1][r][i+1],f[l][r][i]);
	}
	sz=len+len/2+2;int T=n/2;
//	rep(i,0,len)printf("%d %d %d\n",dp[i],i,(len-i+1)/2);puts("");
//	printf("need %d\n",T);
	rep(i,0,len)A.a[i][i]=24;rep(i,0,len-1)A.a[i+1][i]=1;
	rep(i,len+1,sz)A.a[i][i]=25;rep(i,len+1,sz-1)A.a[i+1][i]=1;A.a[sz][sz]=26;
	if(n&1){
		rep(i,0,len+1)rep(j,0,i-1)rep(k,0,len)upd(k,(len-k+1)/2,26*f[i][j][k]);//add(A.a[sz-(len-k+1)/2][k],26*f[i][j][k]);
	//	rep(i,1,len)rep(k,0,len)upd(k,(len-k-1)/2,f[i][i][k]);//add(A.a[sz-(len-k-1)/2][k],f[i][i][k]);
	}
	else rep(i,0,len+1)rep(j,0,i-1)rep(k,0,len)upd(k,(len-k+1)/2,f[i][j][k]);//add(A.a[sz-(len-k+1)/2][k],f[i][j][k]);
//	rep(i,0,sz){rep(j,0,sz)printf("%d ",A.a[i][j]);puts("");}
	/*rep(i,0,len)rep(j,0,i-1)rep(k,0,len)add(dp[k],f[i][j][k]);
	if(n&1){
		rep(k,0,len)dp[k]=26LL*dp[k]%mo;
		rep(i,1,len)rep(k,1,len)add(dp[k],f[i][i][k]);
	}
	rep(i,0,len)A.a[sz-(len-i+1)/2][i]=dp[i];*/
	dp[0]=1;
	while(T){
		if(T&1){
			static int f[N];memset(f,0,sizeof(f));
			rep(i,0,sz)rep(j,0,sz)f[i]=(f[i]+1LL*A.a[i][j]*dp[j])%mo;
			memcpy(dp,f,sizeof(f));
		}
		A=mul(A,A);T>>=1;
	}
int res=dp[sz];
if(n&1){
	memset(dp,0,sizeof(dp));dp[0]=1;memset(A.a,0,sizeof(A.a));T=n/2;
	rep(i,0,len)A.a[i][i]=24;rep(i,0,len-1)A.a[i+1][i]=1;
	rep(i,len+1,sz)A.a[i][i]=25;rep(i,len+1,sz-1)A.a[i+1][i]=1;A.a[sz][sz]=26;
	rep(i,1,len)rep(k,0,len)upd(k,(len-k-1)/2+1,f[i][i][k]);
	while(T){
		if(T&1){
			static int f[N];memset(f,0,sizeof(f));
			rep(i,0,sz)rep(j,0,sz)f[i]=(f[i]+1LL*A.a[i][j]*dp[j])%mo;
			memcpy(dp,f,sizeof(f));
		}
		A=mul(A,A);T>>=1;
	}
	add(res,dp[sz-1]);
}
	cout<<res<<endl;
	return 0;
}