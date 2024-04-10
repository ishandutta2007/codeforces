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

const int N=3010,P=998244353;

int n,m,k;
int F[N],S[N],C[N];
int Find(int x){ 
	//cout<<x<<' '<<F[x]<<endl;
	return F[x]==x?x:F[x]=Find(F[x]); 
}
int dp[N][N/2];
int X[N*N/4],Y[N*N/4];

int main(){
	n=rd();
	rep(i,1,n) F[i]=i,S[i]=1,C[i]=0,dp[i][0]=dp[i][1]=1;
	rep(i,1,n) rep(j,1,n) {
		int x=rd();
		if(i<j) X[x]=i,Y[x]=j;
	}
	rep(i,0,n*n) if(X[i]) {
		//cout<<"E "<<X[i]<<' '<<Y[i]<<endl;
		int x=Find(X[i]),y=Find(Y[i]);
		//cout<<"$"<<x<<' '<<y<<endl;
		if(x==y) {
			if(++C[x]==S[x]*(S[x]-1)/2) dp[x][1]++;
		} else {
			++n;
			rep(a,0,S[x]) rep(b,0,S[y]) if((a>0)==(b>0)) dp[n][a+b]=(dp[n][a+b]+1ll*dp[x][a]*dp[y][b])%P;
			F[x]=F[y]=n,S[n]=S[x]+S[y],C[n]=C[x]+C[y]+1,F[n]=n;
			if(C[n]==S[n]*(S[n]-1)/2) dp[n][1]++;
			//rep(i,0,S[n]) cout<<dp[n][i]<<' ';
			//puts("");
		}
	}
	rep(i,1,S[n]) printf("%d ",dp[n][i]);
}