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

const int N=42,P=1e9+7;

int n,m;
int p[N],vis[N],C[N][N];
int a[N],W[N][N],J[N],sz[1<<14];
vector<vector<vector<int>>> dp;

int main() {
	n=rd();
	rep(i,1,n) p[i]=rd();
	rep(i,0,n) rep(j,*C[i]=1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
	rep(i,*J=1,n) J[i]=1ll*J[i-1]*i%P;
	int c1=0,c2=0;
	rep(i,1,n) if(!vis[i]) {
		int c=0;
		for(int j=i;!vis[j];j=p[j]) vis[j]=1,c++;
		if(c==1) c1++;
		else if(c==2) c2++;
		else a[m++]=c;
	}
	rep(i,0,n-1) {
		int t=0;
		rep(j,0,i) t=(t+1ll*C[i][j]*J[j]%P*J[n-j-1])%P;
		rep(j,*W[i]=1,n) W[i][j]=1ll*W[i][j-1]*t%P;
	}
	int A=(1<<m)-1;
	rep(i,1,A) sz[i]=sz[i&(i-1)]+a[__lg(i&-i)];
	dp.resize(c1+1);
	rep(i,0,c1) {
		dp[i].resize(c2+1);
		rep(j,0,c2) dp[i][j].resize(A+1);
	}
	dp[0][0][0]=1;
	rep(i,0,c1) rep(j,0,c2) rep(S,0,A) {
		int c=sz[S]+i+2*j;
		rep(a,0,c1-i) rep(b,0,c2-j) {
			int R=A^S;
			for(int T=R;;T=(T-1)&R) {
				if(!a && !b && !T) break;
				int d=sz[T]+a+b*2,parity=(__builtin_parity(T)^a^b)&1;
				//cout<<"Go "<<a+i<<' '<<b+j<<' '<<(S|T)<<' '<<W[c][d]<<' '<<C[a+i][i]<<' '<<C[b+j][j]<<endl;
				dp[a+i][b+j][S|T]=(dp[a+i][b+j][S|T]+1ll*(parity&1?1:-1)*W[c][d]*dp[i][j][S]%P*C[a+i][i]%P*C[b+j][j])%P;
				if(T==0) break;
			}
		}
	}
	int ans=(dp[c1][c2][A]+P)%P;
	printf("%d\n",ans);
}