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
const int N=4010,INF=1e9+10;

int n,m;
ll A[N],dp[N][N];
int Go(int l,int r) {
	if(l>r) return 0;
	int u=l;
	rep(i,l,r) if(A[i]<A[u]) u=i;
	rep(i,1,r-l+1) dp[u][i]=-1e18;
	int ls=Go(l,u-1);
	int rs=Go(u+1,r);
	rep(i,0,u-l) rep(j,0,r-u) {
		cmax(dp[u][i+j],dp[ls][i]+dp[rs][j]-2ll*A[u]*i*j);
		cmax(dp[u][i+j+1],dp[ls][i]+dp[rs][j]-A[u]*(2*(i*j+i+j)+1-m));
	}
	//cout<<"#"<<l<<' '<<r<<' '<<u<<endl;
	//rep(i,0,r-l+1) cout<<dp[u][i]<<' ';
	//puts("");
	return u;
}

bool Med;
int main() {
	//fprintf(stderr,"%.2lf\n",(&Med-&Mbe)/1024.0/1024.0);
	n=rd(),m=rd();
	rep(i,1,n) A[i]=rd();
	int u=Go(1,n);
	printf("%lld\n",dp[u][m]);
}