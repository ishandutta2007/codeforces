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
const int N = 100002;
int n,m,len[N],ans[N],size;
Vi vec[N];
int cho[N];
bool flag=1;
struct P {
	int x,y;
} s[N];
struct Gr {
	int head[N],edgenum,to[N<<1],nxt[N<<1];
	inline void add(int u, int v) {
		to[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum;
	}
	inline void dfs(int u, int val) {
		cho[u]=val;
		for (int i=head[u]; i!=0; i=nxt[i]) {
			int v=to[i];
			if (cho[v]==-1) dfs(v,val);
			else if (cho[v]!=val) {flag=0; return;}
		}
	}
} g1,g2;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(n);read(m);
	rep(i,1,n) {
		read(len[i]);
		int x; rep(j,1,len[i]) {read(x); vec[i].push_back(x);}
	}
	memset(cho,-1,sizeof(cho));
	rep(i,1,n-1) {
		int l=min(len[i],len[i+1]); int p=-1;
		rep(j,0,l-1) if (vec[i][j]!=vec[i+1][j]) {p=j; break;}
		if (p==-1) {
			if (len[i]>len[i+1]) flag=0; continue;
		}
	//	printf("[%d %d]\n",i,p);
		if (vec[i][p]>vec[i+1][p]) {
			if (cho[vec[i][p]]==0 || cho[vec[i+1][p]]==1) flag=0;
			cho[vec[i][p]]=1; cho[vec[i+1][p]]=0;
		//	printf("%d %d\n",vec[i][p],vec[i+1][p]);
		}
		else {
		//	puts("OwO");
			g1.add(vec[i][p],vec[i+1][p]); g2.add(vec[i+1][p],vec[i][p]);
		}
	}
//	printf("%d\n",flag);
	rep(i,1,m) if (cho[i]!=-1) {
		if (cho[i]==1) g2.dfs(i,1);
		else g1.dfs(i,0);
	}
	if (!flag) puts("No");
	else {
		puts("Yes");
		rep(i,1,m) if (cho[i]==1) ans[++size]=i;
		printf("%d\n",size);
		rep(i,1,size) printf("%d ",ans[i]);
	}
	return 0;
}