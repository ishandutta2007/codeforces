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
const int N=2e7+10,INF=1e9+10;

int n;
int A[N],C[N],M[N];
ll dp[N];
int pri[N],pc;
bool notpri[N];

bool Med;
int main() {
	//fprintf(stderr,"%.2lf\n",(&Med-&Mbe)/1024.0/1024.0);
	n=rd();
	rep(i,1,n) C[rd()]++;
	rep(i,2,N-1) {
		if(!notpri[i]) pri[++pc]=i;
		for(int j=1;j<=pc && i*pri[j]<N;++j) {
			notpri[i*pri[j]]=1;
			if(i%pri[j]==0) break;
		}
	}
	rep(i,1,pc) {
		int d=(N-1)/pri[i],x=pri[i];
		for(int j=d,k=j*x;j;--j,k-=x) C[j]+=C[k];
	}
	/*rep(i,1,pc) {
		int d=(N-1)/pri[i],x=pri[i];
		for(int j=d,k=j*x;j;--j,k-=x) cmax(M[j],max(M[k],C[k]));
	}*/
	//rep(i,1,pc) drep(j,(N-1)/pri[i],1) cmax(M[j],max(C[j*pri[i]],M[j*pri[i]]));
	ll ans=0;
	//rep(i,1,10) cout<<C[i]<<' '<<M[i]<<endl;
	pri[pc+1]=INF;
	drep(i,N-1,1) {//if(C[i]>M[i]) {
		dp[i]=0;
		int d=(N-1)/i;
		for(int j=1;pri[j]<=d;++j) {
			int k=i*pri[j];
			cmax(dp[i],dp[k]-1ll*C[k]*i);
		}
		cmax(ans,dp[i]+=1ll*C[i]*i);
		//cout<<"$"<<i<<' '<<C[i]<<' '<<dp[i]<<endl;
	}
	printf("%lld\n",ans);
}