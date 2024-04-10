#pragma GCC optimize("Ofast")
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<ctime>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> vec;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 503000, M = 605000;
int n,Len[N],Q,Left[N],Right[N];
string name[N];
char s[N];
struct dot{int x,y; dot(int X=0, int Y=0){x=X; y=Y;} };
bool cmp(dot a, dot b) {return a.x<b.x;}
struct que {
	int x,y,index,xs;
	que(int X=0, int Y=0, int Index=0, int XS=0) {
		x=X; y=Y; index=Index; xs=XS;
	}
};
bool cmp1(que a, que b) {return a.x<b.x;}
struct DOT {
	int ans[M],v[M],tot,n,size;
	dot s[M<<2];
	que q[M<<2];
	inline void init(int x) {tot=x;}
	inline void add(int p, int val) {while (p<=tot){v[p]+=val; p+=p&-p;}}
	inline int query(int p) {int res=0; while (p) {res+=v[p]; p-=p&-p;} return res;}
	inline void insert(int x, int y) { //dfn/bh
		s[++n]=dot(x,y);
	}
	inline void Query(int x0, int x1, int y0, int y1, int index) {
		x0--; y0--;
		q[++size]=que(x1,y1,index,1);
		q[++size]=que(x0,y0,index,1);
		q[++size]=que(x1,y0,index,-1);
		q[++size]=que(x0,y1,index,-1);
	}
	inline void solve() {
		sort(s+1,s+n+1,cmp); sort(q+1,q+size+1,cmp1);
		int p=0;
		rep(i,1,size) {
			while (p<n&&s[p+1].x<=q[i].x) add(s[++p].y,1);
			ans[q[i].index]+=q[i].xs*query(q[i].y);
		}
	}
} tree;
struct AC {
	int size,ch[N][26],val[N],f[N];
	inline void insert(char *s, int len) {
		int now=0;
		rep(i,1,len) {
			int c=s[i]-'a';
			if (!ch[now][c]) ch[now][c]=++size;
			now=ch[now][c];
		}
	}
	int num,L[N],R[N];
	queue<int> q;
	vector<int> to[N];
	inline void getfail() {
		while (!q.empty()) q.pop(); rep(i,0,25) if (ch[0][i]) q.push(ch[0][i]);
		while (!q.empty()) {
			int u=q.front(); q.pop();
			rep(i,0,25) if (ch[u][i]) {
				int v=ch[u][i],x=f[u]; q.push(v);
				while (x&&!ch[x][i]) x=f[x];
				f[v]=ch[x][i];
			}
		}
		rep(i,1,size) to[f[i]].push_back(i);
	}
	inline void dfs(int u) {
		L[u]=++num; int len=to[u].size();
		rep(i,0,len-1) dfs(to[u][i]);
		R[u]=num;
	}
	inline void query(char *s, int len, int tp) {
		int now=0;
		rep(i,1,len) {
			int c=s[i]-'a'; now=ch[now][c]; tree.insert(L[now],tp);
		}
		Left[tp]=L[now],Right[tp]=R[now];
	}
} ac;
int main() { //freopen("1.in","r",stdin); freopen("1.out","w",stdout);
	read(n); read(Q);
	rep(i,1,n) {
		scanf("%s",s+1); Len[i]=strlen(s+1);
		ac.insert(s,Len[i]); s[0]='*'; name[i]=s;
	}
//	printf("%lf\n",(double)clock()/CLOCKS_PER_SEC);
	ac.getfail(); ac.dfs(0); rep(i,1,n) {rep(j,1,Len[i]) s[j]=name[i][j]; ac.query(s,Len[i],i);}
	tree.init(max(ac.R[0],n));
//	printf("%lf\n",(double)clock()/CLOCKS_PER_SEC);
	rep(i,1,Q) {
		int l,r,k; read(l); read(r); read(k); //[ ac.L[node(k)],ac.R[node(k)] ], [l,r]
		int L=Left[k],R=Right[k]; tree.Query(L,R,l,r,i);
	}
//	printf("%lf\n",(double)clock()/CLOCKS_PER_SEC);
	tree.solve(); rep(i,1,Q) printf("%d\n",tree.ans[i]);
//	printf("%lf\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}