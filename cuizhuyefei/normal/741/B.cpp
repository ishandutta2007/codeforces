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
const int N = 4004;
int n,m,W,f[N],w[N],v[N],dp[N],tmp[N];
vector<int> a[N];
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline int find(int x) {
	if (f[x]==x) return x;
	return f[x]=find(f[x]);
}
int main() {
	read(n); read(m); read(W);
	rep(i,1,n) read(w[i]); rep(i,1,n) read(v[i]),f[i]=i;
	while (m--) {
		int a,b; read(a); read(b); int x=find(a),y=find(b); f[x]=y;
	}
	rep(i,1,n) a[find(i)].push_back(i);
	rep(i,1,n) {
		int len=a[i].size();
		rep(k,0,W) tmp[k]=dp[k];
		int s1=0,s2=0;
		rep(j,0,len-1) {
			int p=a[i][j]; s1+=w[p]; s2+=v[p];
			rep(k,w[p],W) tmp[k]=max(tmp[k],dp[k-w[p]]+v[p]);
		}
		rep(k,s1,W) tmp[k]=max(tmp[k],dp[k-s1]+s2);
		memcpy(dp,tmp,sizeof(tmp));
	}
	int ans=0; rep(i,0,W) ans=max(ans,dp[i]);
	printf("%d",ans);
	return 0;
}