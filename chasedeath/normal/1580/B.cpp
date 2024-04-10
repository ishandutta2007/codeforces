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
const int N=110,INF=1e9+10;

int n,m,k,P;
int C[N][N],T[N];
int F[N][N],G[N][N];

bool Med;
int main() {
	//fprintf(stderr,"%.2lf\n",(&Med-&Mbe)/1024.0/1024.0);
	n=rd(),m=rd(),k=rd(),P=rd();
	rep(i,0,n) rep(j,*C[i]=1,i) C[i][j]=C[i-1][j]+C[i-1][j-1],Mod1(C[i][j]);
	T[0]=1;
	rep(i,1,n) rep(j,0,i-1) T[i]=(T[i]+1ll*T[j]*T[i-1-j]%P*C[i-1][j])%P;
	rep(i,1,n) F[1][i]=T[i];
	rep(i,2,m) {
		rep(a,0,k) rep(b,a,n) G[a][b]=F[a][b],F[a][b]=0;
		rep(a,0,k) rep(b,a,n) if(G[a][b]) {
			F[a][b+1]=(F[a][b+1]+2ll*G[a][b])%P;
			rep(c,0,k-a) rep(d,c,n-b-1) if(G[c][d]) {
				F[a+c][b+d+1]=(F[a+c][b+d+1]+1ll*G[a][b]*G[c][d]%P*C[b+d][d])%P;
			}
		}
		F[0][1]++,Mod1(F[0][1]);
		//rep(a,0,k) rep(b,a,n) cout<<"#"<<a<<' '<<b<<' '<<F[a][b]<<endl;
	}
	printf("%d\n",F[k][n]);
}