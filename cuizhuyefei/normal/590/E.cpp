#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<bitset>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i; i=nxt[i])
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
const int N = 10000020;
bitset<766> a[766];
char s[N];
struct AC {
	int ch[N][2],f[N],word[N],sz,pos[N],fa[N];
	inline void ins(char *s, int n, int val) {
		int now=0;
		rep(i,1,n) {
			int c=s[i]-'a';
			if (!ch[now][c]) ch[now][c]=++sz;
			fa[ch[now][c]]=now; now=ch[now][c];
		}
		pos[now]=val;
	}
	inline void getfail() {
		queue<int> q;
		rep(i,0,1) if (ch[0][i]) {q.push(ch[0][i]);}
		while (!q.empty()) {
			int u=q.front(); q.pop();
			rep(i,0,1) if (ch[u][i]) {
				int v=ch[u][i],x=f[u]; q.push(v);
				while (x&&!ch[x][i]) x=f[x];
				f[v]=ch[x][i]; word[v]=pos[v]?v:word[f[v]];
			}
		}
		rep(i,1,sz) {word[i]=(pos[f[i]])?f[i]:word[f[i]];}
		rep(i,1,sz) if (pos[i]) {
			for (int u=i; u; u=fa[u]) {
				if (word[u]) a[pos[i]][pos[word[u]]]=1;
				if (pos[u]) a[pos[i]][pos[u]]=1;
			}
		}
	}
} ac;
int n,e[1505][1505];
int match[1505];
bool vis[1505];
inline bool dfs(int u) {
	vis[u]=1;
	rep(i,1,n<<1) if (e[u][i]&&!vis[i]) {
		vis[i]=1;
		if (!match[i]||dfs(match[i])) {
			match[u]=i; match[i]=u;
			return 1;
		}
	}
	return 0;
}
inline int erMatch(int n) {
	int res=0;
	for (int i=1; i<=n*2; i+=2) if (!match[i]) {
		memset(vis,0,sizeof(vis));
		res+=dfs(i);
	}
	return res;
}
inline void dfs1(int u) {
	vis[u]=1; if (!u) return;
	rep(i,1,n<<1) if (e[u][i]&&!vis[i]) {
		vis[i]=1; dfs1(match[i]);
	}
}
int main() { //freopen("1.in","r",stdin);
	read(n);
	rep(i,1,n) {scanf("%s",s+1); int l=strlen(s+1); ac.ins(s,l,i);}
	ac.getfail();
	rep(i,1,n) rep(j,1,n) if (a[i][j]) a[i]|=a[j];
//	rep(i,1,n) rep(j,1,n) if (i!=j&&a[i][j]) printf("%d %d : %d\n",i,j,int(a[i][j]));
	rep(i,1,n) rep(j,1,n) if (i!=j&&a[i][j]) {e[2*i][2*j-1]=1; e[2*j-1][2*i]=1;}
	printf("%d\n",n-erMatch(n));
	memset(vis,0,sizeof(vis));
	rep(i,1,n) if (!match[2*i]) dfs1(2*i);
//	rep(i,1,n) if (!vis[2*i-1]) printf("%d ",2*i-1);
//	rep(i,1,n) if (vis[2*i]) printf("%d ",2*i);
	rep(i,1,n) if (!vis[2*i-1]&&vis[2*i]) printf("%d ",i);
	return 0;
}