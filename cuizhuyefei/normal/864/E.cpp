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
const int N = 105;
int n,m,f[N][2002],a[N],len;
bool used[N][2002];
struct Dot {
	int t,d,v,ind;
} s[N];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline bool cmp(Dot a, Dot b) {
	return a.d<b.d;
}
inline void print(int now) {
	int mm=now;
	per(i,n,1) {
		if (used[i][mm]) {a[++len]=s[i].ind; mm-=s[i].t;}
	}
}
int main() {
	read(n);
	rep(i,1,n) {
		read(s[i].t),read(s[i].d),read(s[i].v),s[i].d--,s[i].ind=i;
		m=max(m,s[i].d);
	}
	sort(s+1,s+n+1,cmp);
	
	rep(i,1,n) rep(j,1,m) {
		f[i][j]=f[i-1][j]; //pre[i][j]=0
		if (j<=s[i].d&&j>=s[i].t) { //> >=   !!!!!!!
			int tmp=f[i-1][j-s[i].t]+s[i].v;
			if (tmp>f[i][j]) {f[i][j]=tmp; used[i][j]=1;}
		}
	}
	int now=1,mx=f[n][1]; 
	for (int p=2; p<=m; p++) if (f[n][p]>=mx) {mx=f[n][p]; now=p;}
	print(now); //sort(a+1,a+len+1);
	printf("%d\n%d\n",f[n][now],len);
	per(i,len,1) printf("%d ",a[i]);
	return 0;
}