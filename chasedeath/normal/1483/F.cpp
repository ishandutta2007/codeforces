#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int,int> Pii;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=1e6+10,INF=1e9+10;

int n;
int fail[N],lst[N],trie[N][26],End[N],dep[N],fa[N],L[N],R[N],I[N],dfn,cnt;
struct Edge{
	int to,nxt;
} e[N<<1];
int head[N],ecnt;
void AddEdge(int u,int v) {
	e[++ecnt]=(Edge){v,head[u]};
	head[u]=ecnt;
}

void dfs(int u) {
	I[L[u]=++dfn]=u;
	for(int i=head[u];i;i=e[i].nxt) {
		int v=e[i].to;
		if(!lst[v]) lst[v]=lst[u];
		dfs(v);
	}
	R[u]=dfn;
}

void Build() {
	static queue <int> que;
	rep(i,0,25) if(trie[0][i]) que.push(trie[0][i]);
	while(!que.empty()) {
		int u=que.front(); que.pop();
		AddEdge(fail[u],u);
		rep(i,0,25) {
			int &v=trie[u][i];
			if(!v) v=trie[fail[u]][i];
			else fail[v]=trie[fail[u]][i],que.push(v);
		}
	}
	dfs(0);
}

struct BIT{
	int s[N];
	void Add(int p,int x){ while(p<=dfn) s[p]+=x,p+=p&-p; }
	int Que(int p){
		int res=0;
		while(p) res+=s[p],p-=p&-p;
		return res;
	}
	int Que(int l,int r){ return Que(r)-Que(l-1); }
} T;

char s[N];
int A[N],B[N],C;

int main(){
	n=rd();
	rep(i,1,n) {
		scanf("%s",s+1);
		int u=0;
		for(int j=1;s[j];++j) {
			int &v=trie[u][s[j]-'a'];
			if(!v) v=++cnt,fa[v]=u,dep[v]=dep[u]+1;
			u=v;
		}
		lst[End[i]=u]=u;
	}
	Build();
	int ans=0;
	rep(i,1,n) {
		C=0;
		for(int u=End[i],mi=1e9;u;u=fa[u]) {
			T.Add(L[u],1);
			int p=lst[u==End[i]?fail[u]:u];
			int l=dep[u]-dep[p]+1;
			if(!p || mi<=l) continue; // none or being included
			mi=l;
			if(!B[p]) A[++C]=p;
			B[p]++;
		}
		rep(j,1,C) {
			ans+=T.Que(L[A[j]],R[A[j]])==B[A[j]];
			B[A[j]]=0;
		}
		for(int u=End[i];u;u=fa[u]) T.Add(L[u],-1);
	}
	printf("%d\n",ans);
}