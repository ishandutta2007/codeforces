#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 2666,inf=0x3f3f3f3f;
int n,m,a[100][N];Vi b[N];
bool cmp(Vi a, Vi b){return a[0]>b[0];}
int dp[1<<12|3],all,g[1<<12|3],sum[1<<12|3],dy[1<<12|3];
int main() {
	rep(i,0,12)dy[1<<i]=i;
	int T;read(T);while(T--){
		read(n);read(m);rep(i,1,n)rep(j,1,m)read(a[i][j]);
		rep(j,1,m){
			b[j].clear();
			int p=1;rep(i,1,n)if(a[i][j]>a[p][j])p=i;
			for(int cnt=1;cnt<=n;cnt++){
				b[j].pb(a[p][j]);p++;if(p>n)p=1;
			}
		}
		sort(b+1,b+m+1,cmp);umin(m,n);all=(1<<n)-1;
		rep(i,0,all)dp[i]=-inf;dp[0]=0;
		rep(j,1,m){
			rep(i,0,all)g[i]=-inf;
			rep(off,0,n-1){
				rep(i,0,all)sum[i]=0;
				static int val[N];
				for(int cnt=0,cur=off;cnt<=n-1;cnt++){
					val[cnt]=b[j][cur];cur++;if(cur==n)cur=0;
				}
				rep(i,1,all)sum[i]=sum[i^(i&-i)]+val[dy[i&-i]];
				rep(i,0,all)umax(g[i],sum[i]);
			}
			per(i,all,0)for(int s=i;;s=(s-1)&i){
				umax(dp[i],dp[s]+g[s^i]);if(!s)break;
			}
		}
		printf("%d\n",dp[all]);
	}
	return 0;
}