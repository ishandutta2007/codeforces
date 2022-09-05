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
int n,m,k,dy[1027],cnt[1027];
bool mtr[12][12];
ll dp[1027][1027][12];
int main() {
	read(n);read(m);read(k);
	rep(i,1,n) dy[1<<i]=i;
	rep(i,1,(1<<n)) cnt[i]=cnt[i>>1]+(i&1);
	rep(i,1,m){int x,y;read(x);read(y);x--;y--;mtr[x][y]=mtr[y][x]=1;}
//	rep(i,0,n-1) dp[1<<i][1<<i][0]=1;
	dp[1][1][0]=1;
	rep(s2,0,(1<<n)-1) for (register int s1=s2; s1; s1=(s1-1)&s2) rep(K,0,k) {
		ll now=dp[s1][s2][K]; if (!now) continue;
		int bit=s1&-s1; dp[s1^bit][s2][K+1]+=now; int u=dy[bit];
		int s=((1<<n)-1)^s2; rep(i,0,n-1) if (((s>>i)&1)&&!mtr[u][i]) s^=1<<i;
		for (register int s3=s; s3; s3=(s3-1)&s) { //root !!!
			dp[(s1^bit)|s3][s2|s3][K+(s2==1&&s1==1&&cnt[s3]==1)]+=now;
		}
	}
	cout<<dp[0][(1<<n)-1][k];
	return 0;
}