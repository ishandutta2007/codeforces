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
const int N = 5005, mo = 1e9+7;
char s[N];
int len,k,dis[N],cnt[N];
int qz[N],dp[1010][1010];
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() { //freopen("1.in","r",stdin);
	scanf("%s%d",s+1,&k); len=strlen(s+1);
	if (!k) {printf("1"); return 0;}
	rep(i,1,1000) cnt[i]=cnt[i>>1]+(i&1);
	rep(i,2,1000) {
		dis[i]=dis[cnt[i]]+1;
	}
	rep(i,1,len) qz[i]=qz[i-1]+(s[i]=='1');
	dp[1][0]=1;
	rep(i,1,len-1) {
		rep(j,0,i) if (dp[i][j]) {
			(dp[i+1][j]+=dp[i][j])%=mo;
			(dp[i+1][j+1]+=dp[i][j])%=mo;
		}
		if (s[i+1]=='1') (dp[i+1][qz[i]]+=1)%=mo;
	}
	dp[len][qz[len]]++;
	ll ans=0;
//	rep(i,0,len) printf("%d:%d\n",i,dp[len][i]);
	rep(i,1,len) if (dis[i]==k-1) (ans+=dp[len][i])%=mo;
	if (k==1) {ans--; if (ans<0) ans+=mo;}
	cout<<ans%mo;
//	rep(i,1,30) printf("%d %d\n",i,dis[i]);
	
	return 0;
}