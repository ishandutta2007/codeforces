#include<bits/stdc++.h>
using namespace std;

const int N=1e5+100;
int n,m,fa[N],vis[N],dep[N],deg[N],val[N];
int head[N],ce;
struct edge { int to,nxt; } e[N<<1];

void lnk(int a,int b) { e[++ce]=(edge) {b,head[a]}, head[a]=ce, ++deg[a]; }

void Answer() {
	puts("YES");
	for(int i=1;i<=n;++i)
		printf("%d ",val[i]);
	puts("");
}

int A,B,ok;
void dfs_1(int u) {
	vis[u]=1;
	for(int i=head[u];i && !ok ;i=e[i].nxt) {
		int v=e[i].to;
		if(vis[v] && dep[v]>dep[u]) {
			ok=1; B=v, A=u; return;
		}
		if(!vis[v]) { fa[v]=u, dep[v]=dep[u]+1; dfs_1(v); }
	}
}
bool solve_loop() {
	ok=0, A=B=0;
	for(int i=1;i<=n && !A;++i)
		if(!vis[i]) dfs_1(i);
	if(!A) return 0;
	int cur=B; val[A]=1;
	while(cur != A) val[cur]=1, cur=fa[cur];
	return 1;
}

bool solve_deg4() {
	for(int i=1;i<=n;++i) if(deg[i] >= 4) {
		for(int j=head[i];j;j=e[j].nxt)
			val[e[j].to]=1;
		val[i]=2; return 1;
	}
	return 0;
}

vector<int> vec;
void dfs_2(int u,int lst) {
	fa[u]=lst, vis[u]=1;
	for(int i=head[u];i;i=e[i].nxt) {
		int v=e[i].to;
		if(v == lst) continue;
		dfs_2(v,u); vec.push_back(v);
	}
}
bool solve_2_deg3() {
	for(int i=1;i<=n;++i) vis[i]=0;
	for(int i=1;i<=n;++i) if(deg[i] == 3 && !vis[i]) {
		vec.clear(); dfs_2(i,0);
		for(auto x:vec) if(deg[x] == 3) {
			for(int j=head[x];j;j=e[j].nxt) val[e[j].to]=1;
			int cur=x; while(cur != i) val[cur]=2, cur=fa[cur];
			val[i]=val[x]=2;
			for(int j=head[i];j;j=e[j].nxt)
				if(!val[e[j].to]) val[e[j].to]=1;
			return 1;
		}
	}
	return 0;
}

int sz[3];
vector<int> pot[3];
bool solve_deg3() {
	for(int i=1;i<=n;++i) vis[i]=0;
	for(int i=1;i<=n;++i) if(deg[i] == 3) {
		vis[i]=1;
		for(int j=head[i],cnt=0,v;j;j=e[j].nxt) {
			v=e[j].to; pot[cnt].clear();
			while(!vis[v]) {
				pot[cnt].push_back(v), vis[v]=1;
			//	cout<<cnt<<" "<<v<<endl;
				for(int k=head[v];k;k=e[k].nxt) 
					if(!vis[e[k].to]) { v=e[k].to; break; }
			}
			sz[cnt]=pot[cnt].size(); ++cnt;
		}//cout<<sz[0]<<" "<<sz[1]<<" "<<sz[2]<<endl;
		if(1ll*(sz[0]+1)*(sz[1]+1)*(sz[2]+1) <
			1ll*(sz[0]+1)*(sz[1]+1)+1ll*(sz[0]+1)*(sz[2]+1)+1ll*(sz[1]+1)*(sz[2]+1))
				continue;
		if(sz[0]>sz[1]) swap(pot[0],pot[1]), swap(sz[0],sz[1]);
		if(sz[0]>sz[2]) swap(pot[0],pot[2]), swap(sz[0],sz[2]);
		if(sz[1]>sz[2]) swap(pot[1],pot[2]), swap(sz[1],sz[2]);
		
		if(sz[2] >= 5) {
			val[i]=6, val[pot[1][0]]=4, val[pot[1][1]]=2, val[pot[0][0]]=3;
			for(int j=0;j<5;++j) val[pot[2][j]]=5-j;
			return 1;
		}
		val[i]=(sz[0]+1)*(sz[1]+1)*(sz[2]+1);
		for(int k=0;k<3;++k)
			for(int j=0;j<sz[k];++j)
				val[pot[k][j]]=1ll*(sz[k]-j)*val[i]/(sz[k]+1);
		return 1;
	}
	return 0;
}

void init() {
	for(int i=1;i<=n;++i) head[i]=fa[i]=vis[i]=dep[i]=val[i]=deg[i]=0;
	ce=0;
}

int main() {
	int T; scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		init();
		for(int i=1,u,v;i<=m;++i)
			scanf("%d%d",&u,&v), lnk(u,v), lnk(v,u);
		if(solve_loop()) { Answer(); continue; }
		if(solve_deg4()) { Answer(); continue; }
		if(solve_2_deg3()) { Answer(); continue; }
		if(solve_deg3()) { Answer(); continue; }
		puts("NO");
	}
	return 0;
}