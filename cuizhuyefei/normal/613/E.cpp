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
const int N = 2020, mo = 1e9+7;
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
char S[N*4],s[2][N],t[N];int n,m,res,lcp[N*4][N],sz;
int zuo[2][N][N>>1],you[2][N][N>>1],r[2][N],l[2][N],dp[2][N][2][N];//rightward
inline int solve(){
	sz=0;rep(i,0,1){rep(j,1,n)S[r[i][j]=++sz]=s[i][j];S[++sz]='#';}
	rep(i,0,1){per(j,n,1)S[l[i][j]=++sz]=s[i][j];S[++sz]='#';}
	per(i,sz,1)per(j,m,1)lcp[i][j]=S[i]==t[j]?1+lcp[i+1][j+1]:0;
	rep(i,0,1)rep(j,0,n+1)zuo[i][j][0]=you[i][j][0]=1;
	rep(i,0,n+1){
		if(i-1>=1)rep(j,2,min(m/2,i)){
			zuo[1][i][j]=lcp[l[0][i-1]][1]>=j&&lcp[r[1][i-j]][1+j]>=j;
			zuo[0][i][j]=lcp[l[1][i-1]][1]>=j&&lcp[r[0][i-j]][1+j]>=j;
		//	if(zuo[1][i][j])cerr<<"B "<<i<<' '<<j<<endl;
		//	if(zuo[0][i][j])cerr<<"A "<<i<<' '<<j<<endl;
		}
		if(i+1<=n)rep(j,2,min(m/2,n-i)){
			you[1][i][j]=lcp[r[1][i+1]][m-2*j+1]>=j&&lcp[l[0][i+j]][m-j+1]>=j;
			you[0][i][j]=lcp[r[0][i+1]][m-2*j+1]>=j&&lcp[l[1][i+j]][m-j+1]>=j;
		//	if(you[1][i][j])cerr<<"D "<<i<<' '<<j<<endl;
		//	if(you[0][i][j])cerr<<"C "<<i<<' '<<j<<endl;
		}
	}
	memset(dp,0,sizeof(dp));
	rep(i,0,1)rep(j,1,n){
		rep(k,0,min(m/2,j))if(s[i][j]==t[2*k+1])dp[i][j][0][2*k+1]=zuo[i][j][k];
	}
//	cerr<<zuo[1][3][2]<<endl;
//	cerr<<dp[1][3][0][5]<<endl;
	rep(j,1,n){
		rep(i,0,1)rep(k,1,m)if(t[k+1]==s[i^1][j])add(dp[i^1][j][1][k+1],dp[i][j][0][k]);
		rep(i,0,1)rep(k,1,m)if(t[k+1]==s[i][j+1])add(dp[i][j+1][0][k+1],dp[i][j][0][k]),add(dp[i][j+1][0][k+1],dp[i][j][1][k]);
	}
	/*cerr<<dp[1][2][1][4]<<endl;
	cerr<<dp[1][3][0][5]<<endl;
	cerr<<dp[1][3][1][6]<<endl;*/
	int res=0;
	rep(i,0,1)rep(j,1,n){
		rep(k,0,min(m/2,n-i)){
			res=(res+1LL*(dp[i][j][0][m-2*k]+dp[i][j][1][m-2*k])*you[i][j][k])%mo;
			if(m%2==0&&k&&m/2-k)res=(res+1LL*you[i][j][k]*zuo[i][j+1][m/2-k])%mo;
		//	if(1LL*(dp[i][j][0][m-2*k]+dp[i][j][1][m-2*k])*you[i][j][k]%mo)
		//		printf("%d %d %d:%d\n",i,j,k,1LL*(dp[i][j][0][m-2*k]+dp[i][j][1][m-2*k])*you[i][j][k]%mo);
		}
	}
	return res;
}
int main() {
	rep(i,0,1)scanf("%s",s[i]+1);n=strlen(s[0]+1);
	scanf("%s",t+1);m=strlen(t+1);cerr<<n<<' '<<m<<endl;
	if(m==1){
		int res=0;rep(i,0,1)rep(j,1,n)res+=s[i][j]==t[1];
		cout<<res<<endl;
		return 0;
	}
	if(m==2){
		int dx[]={1,-1,0,0};
		int dy[]={0,0,1,-1};
		int res=0;rep(i,0,1)rep(j,1,n)if(s[i][j]==t[1]){
			rep(k,0,3)if(i+dx[k]>=0&&i+dx[k]<=1&&j+dy[k]>=1&&j+dy[k]<=n)
				res+=s[i+dx[k]][j+dy[k]]==t[2];
		}
		cout<<res<<endl;
		return 0;
	}
	res=solve();
	/*rep(i,3,3)rep(j,2,2)
		cerr<<lcp[l[0][i-1]][1]<<' '<<lcp[r[1][i-j]][1+j]<<endl;
	cerr<<zuo[1][3][2]<<endl;*/
//	cerr<<dp[1][2][1][4]<<endl;
//	rep(i,0,1)rep(j,1,n)rep(k,0,1)rep(l,1,m)if(dp[i][j][k][l])
//		cerr<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<dp[i][j][k][l]<<endl;
	
	cerr<<res<<endl;
	rep(i,0,1)reverse(s[i]+1,s[i]+n+1);
	res=(solve()+res)%mo;
//	int CUR=res;
	cerr<<res<<endl;
	rep(i,0,n+1){
		if(i-1>=1&&m%2==0)add(res,zuo[0][i][m/2]),add(res,zuo[1][i][m/2]);
		if(i+1<=n&&m%2==0)add(res,you[0][i][m/2]),add(res,you[1][i][m/2]);
	}
	/*memset(dp,0,sizeof(dp));
	rep(i,0,1)rep(j,1,n){
		rep(k,0,min(m/2,i))if(s[i][j]==t[2*k+1])dp[i][j][0][2*k+1]=zuo[i][j][k];
	}
	rep(j,1,n){
		rep(i,0,1)rep(k,1,m)if(t[k+1]==s[i^1][j])add(dp[i^1][j][1][k+1],dp[i][j][0][k]);
	}
	cerr<<res<<endl;
	rep(i,0,1)rep(j,1,n){
		rep(k,0,min(m/2,n-i))res=(res-1LL*(dp[i][j][0][m-2*k]+dp[i][j][1][m-2*k])*you[i][j][k])%mo;
	}*/
	res=(res+mo)%mo;cout<<res<<endl;
	/*if(res==520540716){
		cout<<n<<' '<<m<<' '<<CUR<<endl;
	}*/
	return 0;
}