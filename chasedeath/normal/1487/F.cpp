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

const int N=54,INF=1e9+10,K=50;

int n;
char s[N];
int dp[N][N*20][K*2+1];

int main(){
	s[1]='0',scanf("%s",s+2),n=strlen(s+1);
	int D=n*10;
	memset(dp,10,sizeof dp),dp[0][D][K]=0;
	rep(i,1,n) {
		rep(j,0,D*2) rep(k,0,K*2) if(dp[i-1][j][k]<1e9){
			int v=(k-K)*10+s[i]-'0'-(j-D);
			rep(d,-K,K) if(j+(v+d)>=0 && j+(v+d)<=2*D) {
				//cout<<"$"<<i<<' '<<j<<' '<<k<<' '<<d<<endl;
				cmin(dp[i][j+(v+d)][K-d],dp[i-1][j][k]+abs(v+d)*(n-i+1));
			}
		}
	}
	int ans=1e9;
	rep(i,0,D*2) cmin(ans,dp[n][i][K]);
	printf("%d\n",ans);
}