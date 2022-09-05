#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 23, M = 4194305;
int n,m,jh[N],dp[M],pre[M],pre1[M],dy[M];
int ans[N];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() { //freopen("1.in","r",stdin);
	read(n);read(m); rep(i,0,n) jh[i]=1<<i; //include
	rep(i,1,n-1) dy[1<<i]=i;
	rep(i,1,m) {int a,b; read(a); read(b); a--; b--; jh[a]|=1<<b; jh[b]|=1<<a;}
//	rep(i,0,n-1) printf("%d : %d\n",i,jh[i]);
	memset(dp,0x3f3f3f3f,sizeof(dp));
	rep(i,1,(1<<n)-1) {
		int tmp=i; bool gg=0;
		while (tmp) {
			int bit=tmp&-tmp; tmp-=bit; bit=dy[bit]; 
			if ((jh[bit]&i)!=i) gg=1;
		//	printf("%d %d %d\n",i,bit,gg);
		}
		if (!gg) dp[i]=0;
	}//rintf("%d\n",dp[(1<<n)-1]);
	rep(i,1,(1<<n)-1) {
		int tmp=i;
		while (tmp) {
			int bit=tmp&-tmp; tmp-=bit; bit=dy[bit]; 
			if (dp[i|jh[bit]]>dp[i]+1) {dp[i|jh[bit]]=dp[i]+1; pre[i|jh[bit]]=bit; pre1[i|jh[bit]]=i;}
		}
	//	printf("%d : %d\n",i,dp[i]);
	} printf("%d\n",dp[(1<<n)-1]);
	for (int i=1,j=(1<<n)-1; i<=dp[(1<<n)-1]; i++) {ans[i]=pre[j]; j=pre1[j];}
	per(i,dp[(1<<n)-1],1) printf("%d ",ans[i]+1);
	return 0;
}