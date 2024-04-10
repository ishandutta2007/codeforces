#include <bits/stdc++.h>	
using namespace std;
void read(short &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(short x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
struct edge{
	short to,cap,rev;
};
short level[205],iter[205];
vector<edge>g[205];
bool isp[20004];
short n,a[205];
void add_edge(short from,short to,short cap){
	g[from].push_back((edge){to,cap,g[to].size()}); 
	g[to].push_back((edge){from,0,g[from].size()-1});
}
void bfs(short s){
	queue <short> que;
	memset (level,-1,sizeof(level));
	level[s]=0;
	que.push(s);
	while (!que.empty()){
		short u=que.front();que.pop();
		for (short i=0;i<g[u].size();i++){
			edge e=g[u][i];
			if (e.cap>0 && level[e.to]<0){
				level[e.to]=level[u]+1;
				que.push(e.to);
			}
		}
	}
}
short dfs(short v,short t,short f){
	if (v==t) return f;
	for (short &i=iter[v];i<g[v].size();i++){
		edge &e=g[v][i];
		if (e.cap>0 && level[v]<level[e.to]){
			short d=dfs(e.to,t,min(f,e.cap));
			if (d>0){
				e.cap-=d;
				g[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
short maxflow(short s,short t){
	short flow=0;
	for (;;){
		bfs(s);
		if (level[t]<0) return flow;
		memset (iter,0,sizeof(iter));
		short f;
		while ((f=dfs(s,t,5e4))>0) flow+=f;
	}
}
bool vis[203];
vector<short>G[203];
vector<short> ans[203];
void dfs(short x,short now){
	vis[x]=1;
	ans[now].push_back(x);
	for (int i=0;i<G[x].size();i++) if (!vis[G[x][i]])
		dfs(G[x][i],now);
}
int main(){
	isp[1]=1;
	for (short i=2;i*i<=20000;i++)
		if (!isp[i])
			for (short j=i*i;j<=20000;j+=i) isp[j]=1;
	read(n);
	for (short i=1;i<=n;i++) read(a[i]);
	for (short i=1;i<=n;i++){
		if (a[i]%2==0){
			for (short j=1;j<=n;j++) if (!isp[a[i]+a[j]])
				add_edge(i,j,1);
			add_edge(0,i,2);
		}else add_edge(i,n+1,2);
	}
	if (maxflow(0,n+1)!=n){
		puts("Impossible");return 0;
	}
	for (short i=1;i<=n;i++) if (a[i]%2==0)
		for (short j=0;j<g[i].size();j++){
			edge e=g[i][j];
			if (e.to==0) continue;
			if (e.cap==0){
				G[i].push_back(e.to);
				G[e.to].push_back(i);
			}
		}
	short cnt=0;
	for (short i=1;i<=n;i++) if (!vis[i])
		dfs(i,++cnt);
	write(cnt);puts("");
	for (short i=1;i<=cnt;i++,puts("")){
		write(ans[i].size());
		for (short j=0;j<ans[i].size();j++) putchar(' '),write(ans[i][j]);
	}
}