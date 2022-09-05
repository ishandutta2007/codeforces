#pragma GCC optimize("Ofast")
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cassert>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 3030, M = 400000;
char t[N],s[N];
int l,n,m,A[M],B[M]; //C/V!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
int head[N],to[M],nxt[M],edgenum;
int val[N];
int sta[N],top,vis[N];
inline void add(int u, int v) {
	to[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum;
}
inline void init() {
	edgenum=top=0; memset(head,0,sizeof(head));
	memset(val,0x3f3f3f3f,sizeof(val));
	memset(vis,-1,sizeof(vis));
}
inline int id(int a, char b) {return a*2-(b=='C');}
inline int inv(int a) {return (a&1)?a+1:a-1;}
inline bool dfs(int u) {
//	if (top>n*2) printf("top = %d\n",top);
	L(i,u) if (vis[to[i]]==-1) {
		vis[to[i]]=1; vis[inv(to[i])]=0;
		sta[++top]=to[i]; sta[++top]=inv(to[i]);
		if (!dfs(to[i])) return 0; //!!!!!!!!!!!!!!!!!!
	}
	else if (vis[to[i]]==0) return 0;
	return 1;
}
inline bool solve() {
	rep(i,1,n) if (vis[i*2]==-1) {
		if (val[i*2-1]<val[i*2]) {
			vis[i*2-1]=1; vis[i*2]=0; top=2; sta[1]=i*2-1; sta[2]=i*2;
			if (!dfs(i*2-1)) { assert(top<=n*2);
				while (top) vis[sta[top--]]=-1;
				vis[i*2]=1; vis[i*2-1]=0; //????
				if (!dfs(i*2)) return 0;
			}
		}
		else {
			vis[i*2]=1; vis[i*2-1]=0; top=2; sta[1]=i*2-1; sta[2]=i*2;
			if (!dfs(i*2)) { assert(top<=n*2);
				while (top) vis[sta[top--]]=-1;
				vis[i*2-1]=1; vis[i*2]=0;
				if (!dfs(i*2-1)) return 0;
			}			
		}
	}
	rep(i,1,n) if (vis[i*2-1]==1&&val[i*2-1]>l) return 0;
	else if (vis[i*2]==1&&val[i*2]>l) return 0;
	rep(i,1,n) if (vis[i*2-1]==1) printf("%c",'a'+val[i*2-1]-1); else printf("%c",'a'+val[i*2]-1);
	return 1;
}
inline bool ok(int p) { //1..p: same
	init();
	rep(i,1,p) add(inv(id(i,t[s[i]-'a'+1])),id(i,t[s[i]-'a'+1]));
	rep(i,1,p) val[id(i,t[s[i]-'a'+1])]=s[i]-'a'+1;
	if (p+1<=n)
	per(i,l,s[p+1]-'a'+1+1)
		if (t[i]=='C') val[2*(p+1)-1]=i;
		else val[2*(p+1)]=i;
	rep(j,p+2,n) per(i,l,1)
		if (t[i]=='C') val[2*(j)-1]=i;
		else val[2*j]=i;
	rep(i,1,m) {add(A[i],B[i]); add(inv(B[i]),inv(A[i]));}
//	printf("%d \n",p);
	return solve();
}
int main() { //freopen("data.in","r",stdin);
	scanf("%s",t+1); l=strlen(t+1);
	read(n); read(m);
	rep(i,1,m) {
		int a,c; char b[3],d[3];
		read(a);scanf("%s",b);read(c);scanf("%s",d);
		A[i]=id(a,b[0]); B[i]=id(c,d[0]);
	}
	scanf("%s",s+1);
	per(i,n,0) if (ok(i)) return 0;
	puts("-1");
	return 0;
}