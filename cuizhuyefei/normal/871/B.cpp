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
const int N = 10005;
int n,a[N],b[N];
int s[N],t[N];
int size,ans[N];
bool vis[N];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(n);
	rep(i,0,n-1) {
		printf("? %d %d\n",0,i);
		fflush(stdout);
		read(a[i]);
	}
	rep(i,1,n-1) {
		printf("? %d %d\n",i,0);
		fflush(stdout);
		read(b[i]); b[i]^=a[0];
	}	
	rep(x,0,n-1) {
		s[0]=x; rep(i,1,n-1) s[i]=x^b[i];
		rep(i,0,n-1) t[i]=x^a[i]; bool flag=1;
		memset(vis,0,sizeof(vis)); 
		rep(i,0,n-1) {if (vis[s[i]]) flag=0; vis[s[i]]=1;}
		rep(i,0,n-1) if (!vis[i]) flag=0;
		memset(vis,0,sizeof(vis));
		rep(i,0,n-1) {if (vis[t[i]]) flag=0; vis[t[i]]=1;}
		rep(i,0,n-1) if (!vis[i]) flag=0;
		rep(i,0,n-1) if (s[t[i]]!=i) flag=0;
		if (flag) {
			size++;
			rep(i,0,n-1) ans[i]=s[i];
		}
	}
	puts("!");
	printf("%d\n",size);
	rep(i,0,n-1) printf("%d ",ans[i]);
	return 0;
}
//[0,n)1