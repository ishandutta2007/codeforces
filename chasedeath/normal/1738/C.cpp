#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int,int> Pii;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

bool Mbe;
const int N=1e6+10,INF=1e9+10;

int dp[110][110][2][2];

bool Med;
int main() {
	fprintf(stderr,"%.2lf\n",(&Med-&Mbe)/1024.0/1024.0);
	rep(_,1,rd()) {
		int n=rd();
		int c1=0,c2=0;
		rep(i,1,n) {
			if(rd()&1) c1++;
			else c2++;
		}
		memset(dp,-1,sizeof dp);
		dp[0][0][0][0]=1;
		dp[0][0][0][1]=0;
		dp[0][0][1][0]=0;
		dp[0][0][1][1]=1;
		rep(i,0,c1) rep(j,0,c2) if(i || j) rep(u,0,1) rep(c,0,1) {
			int f=0;
			if(i) f|=!dp[i-1][j][u^1][c^(u==0)];
			if(j) f|=!dp[i][j-1][u^1][c];
			dp[i][j][u][c]=f;
		}
		puts(dp[c1][c2][0][0]?"Alice":"Bob");
	}
}