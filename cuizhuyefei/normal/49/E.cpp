#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 55, inf = 0x3f3f3f3f;
char s[N],t[N];
bool f[N][N][28],g[N][N][28];
int n,m,dp[N][N],F[N][N],G[N][N];
vector<pair<char,char> > e[257];
inline void umin(int &a, int b) {a=a<b?a:b;}
int main() { //freopen("1.in","r",stdin);
	scanf("%s%s",s+1,t+1); n=strlen(s+1); m=strlen(t+1);
	int q; read(q);
	while (q--) {
		char str[11]; scanf("%s",str+1);
		e[str[1]-'a'].push_back(pair<char,char>(str[4],str[5]));
	}
	rep(i,1,n) rep(j,0,25) f[i][i][j]=(s[i]=='a'+j);
	rep(L,1,n-1) rep(i,1,n-L+1) rep(c,0,25) {
		int j=i+L,len=e[c].size();
		rep(k,i,j-1) per(p,len-1,0) {
			int a=e[c][p].fi-'a',b=e[c][p].se-'a';
			f[i][j][c]|=f[i][k][a]&f[k+1][j][b];
		}
	}
	rep(i,1,m) rep(j,0,25) g[i][i][j]=(t[i]=='a'+j);
	rep(L,1,m-1) rep(i,1,m-L+1) rep(c,0,25) {
		int j=i+L,len=e[c].size();
		rep(k,i,j-1) per(p,len-1,0) {
			int a=e[c][p].fi-'a',b=e[c][p].se-'a';
			g[i][j][c]|=g[i][k][a]&g[k+1][j][b];
		//	if (c=='z'-'a'&&i==1&&j==3&&k==2&&a=='e'-'a'&&b=='a'-'a')
			//	printf("<%d,%d>\n",g[i][k][a],g[k+1][j][b]);
		}
	}
//	rep(c,0,25) if (f[1][n][c]|g[1][2][c]) printf("%c : %d %d\n",'a'+c,f[1][n][c],g[1][2][c]);
	rep(i,1,n) rep(j,i,n) rep(c,0,25) F[i][j]+=f[i][j][c]<<c;
	rep(i,1,m) rep(j,i,m) rep(c,0,25) G[i][j]+=g[i][j][c]<<c;
	/*printf("%d %d\n",f[1][1]['m'-'a'],g[1][1]['m'-'a']);
	printf("%d %d\n",f[2][3]['x'-'a'],g[2][2]['x'-'a']);
	printf("%d %d\n",F[2][3],G[2][2]);*/
	memset(dp,inf,sizeof(dp)); dp[0][0]=0;
	rep(i,0,n) rep(j,0,m) if (dp[i][j]<inf) {
		rep(k,i+1,n) rep(l,j+1,m)
			if (F[i+1][k]&G[j+1][l]) umin(dp[k][l],dp[i][j]+1);
	//	printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
	}
	printf("%d",dp[n][m]==inf?-1:dp[n][m]);
	return 0;
}