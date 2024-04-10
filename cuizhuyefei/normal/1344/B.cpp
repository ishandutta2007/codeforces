#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
mt19937 R(chrono::system_clock().now().time_since_epoch().count());

const int N = 1050;
int n,m,a[N][N],res;char S[N][N];
void GG(){puts("-1");exit(0);}
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void dfs(int x, int y){
	a[x][y]=0;
	rep(t,0,3)if(x+dx[t]>=1&&x+dx[t]<=n&&y+dy[t]>=1&&y+dy[t]<=m&&a[x+dx[t]][y+dy[t]]){
		dfs(x+dx[t],y+dy[t]);
	}
}
int main() {
	read(n);read(m);
	rep(i,1,n)scanf("%s",S[i]+1);
	rep(i,1,n)rep(j,1,m)a[i][j]=S[i][j]=='#';
	int x=0,y=0;
	rep(i,1,n){
		int cnt=0;
		rep(j,1,m)cnt+=a[i][j];
		rep(j,1,m-1)cnt-=a[i][j]&&a[i][j+1];
		if(cnt>1)GG();
		x+=!cnt;
	}
	rep(j,1,m){
		int cnt=0;
		rep(i,1,n)cnt+=a[i][j];
		rep(i,1,n-1)cnt-=a[i][j]&&a[i+1][j];
		if(cnt>1)GG();
		y+=!cnt;
	}
	if(x>0&&!y||y>0&&!x)GG();
	rep(i,1,n)rep(j,1,m)if(a[i][j])dfs(i,j),res++;
	cout<<res;
	return 0;
}