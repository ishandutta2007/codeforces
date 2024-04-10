#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 50005, inf = 0x3f3f3f3f;
int n,k,l,a[N],e[N];
int dot[N],len,d[N],q[N],dis[23][23],ts[23];
int dp[1048577],dy[1048577],cnt[1048577];
inline void bfs(int s) {
	memset(d,inf,sizeof(d)); d[s]=0;
	int f=0,r=1; q[f]=s;
	while (f!=r) {
		int u=q[f++];
		rep(i,1,l) rep(j,0,1) {
			int v=u+e[i]*(j==1?1:-1); if (v<1||v>n+1) continue;
			if (d[v]>d[u]+1) d[v]=d[u]+1,q[r++]=v;
		}
	}
}
int main() {
	read(n); read(k); read(l);
	rep(i,1,k) {int x; read(x); a[x]=1;}
	rep(i,1,l) read(e[i]);
	per(i,n,1) {a[i]^=a[i-1]; if (a[i]) dot[++len]=i;}
	rep(i,1,len) {
		bfs(dot[i]); rep(j,1,len) dis[i][j]=d[dot[j]]; ts[i]=d[n+1];
	//	printf("ts[%d]=%d\n",i,ts[i]);
	}
	rep(i,1,20) dy[1<<i]=i;
	rep(i,1,(1<<len)-1) cnt[i]=cnt[i>>1]+(i&1);
	memset(dp,inf,sizeof(dp)); dp[0]=0;
//	printf("len = %d\n",len);
	rep(s,1,(1<<len)-1) if (((cnt[s]>>1)<<1)==cnt[s]) {
		int a=s&-s,tmp=s^a; while (tmp) {
			int bit=tmp&-tmp; tmp-=bit;
			dp[s]=min(dp[s],dp[s^a^bit]+dis[dy[a]+1][dy[bit]+1]);
		}
	}
	int ans=dp[(1<<len)-1];
	rep(i,0,len-1) ans=min(ans,dp[((1<<len)-1)^(1<<i)]+ts[i+1]);
	printf("%d",ans<inf?ans:-1);
	return 0;
}