#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
void stanebear(){
	puts("unfair");exit(0);
}
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,b,q;
pii x[10004];
int cmp[10004],num[10004],vis[100004];
struct edge{
	int to,cap,rev;
};
int level[20010],iter[20010];
vector<edge>g[20010];
void add_edge(int from,int to,int cap){
	g[from].push_back((edge){to,cap,g[to].size()}); 
	g[to].push_back((edge){from,0,g[from].size()-1});
}
void bfs(int s){
	queue <int> que;
	memset (level,-1,sizeof(level));
	level[s]=0;
	que.push(s);
	while (!que.empty()){
		int u=que.front();que.pop();
		for (int i=0;i<g[u].size();i++){
			edge e=g[u][i];
			if (e.cap>0 && level[e.to]<0){
				level[e.to]=level[u]+1;
				que.push(e.to);
			}
		}
	}
}
int dfs(int v,int t,int f){
	if (v==t) return f;
	for (int &i=iter[v];i<g[v].size();i++){
		edge &e=g[v][i];
		if (e.cap>0 && level[v]<level[e.to]){
			int d=dfs(e.to,t,min(f,e.cap));
			if (d>0){
				e.cap-=d;
				g[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int maxflow(int s,int t){
	int flow=0;
	for (;;){
		bfs(s);
		if (level[t]<0) return flow;
		memset (iter,0,sizeof(iter));
		int f;
		while ((f=dfs(s,t,5e4))>0) flow+=f;
	}
}
int main(){
	read(n),read(b),read(q),q++;
	for (int i=1;i<q;i++)
		read(x[i].fi),read(x[i].se);
	x[q].fi=b,x[q].se=n;
	sort (x+1,x+1+q);
	cmp[x[1].fi+1]=1;
	num[x[1].fi]=x[1].se;
	for (int i=2;i<=q;i++){
		if (x[i].se<x[i-1].se) stanebear();
		if (x[i].fi==x[i-1].fi && x[i].se!=x[i-1].se) stanebear();
		if (x[i].fi==x[i-1].fi) continue;
		cmp[x[i].fi+1]=1;
		num[x[i].fi]=x[i].se-x[i-1].se;
	}
	cmp[1]=1;
	for (int i=2;i<=b;i++) cmp[i]=cmp[i-1]+cmp[i];
	for (int i=1;i<=b;i++) vis[cmp[i]]=num[i];
	for (int i=0;i<5;i++) add_edge(5,i,n/5);
	for (int i=1;i<=b;i++) add_edge(i%5,i+5,1);
	for (int i=1;i<=b;i++) add_edge(i+5,cmp[i]+b+5,1);
	for (int i=1;i<=cmp[b];i++) add_edge(i+b+5,cmp[b]+b+6,vis[i]); 
	if (maxflow(5,cmp[b]+b+6)!=n) stanebear();
	puts("fair");
}