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

const int N=1e6+10,INF=1e9+10;

int n,k;
int pri[N],notpri[N],pc;
int phi[N];

int main(){
	n=rd(),k=rd();
	if(k==1) return puts("3"),0;
	rep(i,2,n) {
		if(!notpri[i]) pri[++pc]=i,phi[i]=i-1;
		for(int j=1;j<=pc && 1ll*i*pri[j]<=n;j++){
			notpri[i*pri[j]]=1;
			if(i%pri[j]==0){
				phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
			phi[i*pri[j]]=phi[i]*(pri[j]-1);
		}
	}
	//rep(i,3,n) cout<<phi[i]<<' ';
	//puts("");
	sort(phi+3,phi+n+1);	
	ll ans=2;
	rep(i,3,k+2) ans+=phi[i];
	printf("%lld\n",ans);
}