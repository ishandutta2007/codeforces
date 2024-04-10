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

const int N=30,INF=1e9+10;

int n,k;
int dp[1<<20],pre[1<<20];
int F[2010];


void dfs(int p) {
	if(!pre[p]) return;
	dfs(pre[p]),dfs(pre[p]^p);
	printf("%d %d\n",dp[pre[p]],dp[pre[p]^p]);
}

int main(){
	n=rd(),k=rd();
	rep(i,0,n-1) dp[1<<i]=rd();
	rep(i,1,2000) F[i]=i%k==0?F[i/k]:i;
	int A=(1<<n)-1;
	rep(i,1,A) if(!dp[i]) {
		dp[i]=1e9;
		for(int j=i&(i-1);j>=(j^i);j=(j-1)&i) {
			int t=F[dp[j]+dp[j^i]];
			if(t<dp[i]) dp[i]=t,pre[i]=j;
		}
	}
	if(dp[A]>1) return puts("NO"),0;
	puts("YES");
	dfs(A);
}