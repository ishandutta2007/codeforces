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

const int N=2010,INF=1e9+10;

int n;
char G[N][N];

int deg[N];
int Check(){
	static int t[N];
	memset(t,0,n<<2);
	rep(i,1,n) t[deg[i]]++;
	int c=0,s=0;
	rep(i,0,n-1) {
		while(t[i]--) {
			if(++c==n) return 1;
			if((s+=i)==c*(c-1)/2) return 0;
		}
	}
	return 1;
}

namespace pt1{
	void Solve(){
		int mi=1e9,ans=0;
		rep(S,0,(1<<n)-1) {
			int c=__builtin_popcount(S);
			if(c>mi) continue;
			rep(i,1,n) if(S&(1<<(i-1))) rep(j,1,n) if(i!=j) G[i][j]^=1,G[j][i]^=1;
			rep(i,1,n) deg[i]=0;
			rep(i,1,n) rep(j,1,n) deg[i]+=G[i][j]-'0';
			if(Check()) {
				if(c<mi) mi=c,ans=1;
				else ans++;
			}
			rep(i,1,n) if(S&(1<<(i-1))) rep(j,1,n) if(i!=j) G[i][j]^=1,G[j][i]^=1;
		}
		if(mi==1e9) puts("-1");
		else {
			rep(i,1,mi) ans*=i;
			printf("%d %d\n",mi,ans);
		}
	}
}

int main() {
	n=rd();
	rep(i,1,n) scanf("%s",G[i]+1);
	if(n<=6) return pt1::Solve(),0;
	rep(i,1,n) rep(j,1,n) deg[i]+=G[i][j]-'0';
	if(Check()) return puts("0 1"),0;
	int ans=0;
	rep(i,1,n) {
		rep(j,1,n) if(i!=j) {
			if(G[i][j]=='1') deg[i]--,deg[j]++;
			else deg[j]--,deg[i]++;
		}
		ans+=Check();
		rep(j,1,n) if(i!=j) {
			if(G[i][j]=='0') deg[i]--,deg[j]++;
			else deg[j]--,deg[i]++;
		}
	}
	printf("1 %d\n",ans);
}