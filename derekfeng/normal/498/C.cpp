#include <bits/stdc++.h>
using namespace std;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,m,cnt;
int id[104][9],d[904],gd[104];
struct edge{
	int to,cap,rev;
};
int level[905],iter[905];
vector<edge>g[905];
void add_edge(int from,int to,int cap){
	g[from].push_back((edge){to,cap,g[to].size()}); 
	g[to].push_back((edge){from,0,g[from].size()-1});
}
void got(int num,int x){
	for (int i=2;i*i<=num;i++) if(num%i==0){
		++cnt;
		id[x][gd[x]++]=cnt;
		d[cnt]=i;
		int ok=0;
		while(num%i==0) ok++,num/=i; 
		if (x%2==1)add_edge(0,cnt,ok);
		if (x%2==0)add_edge(cnt,9*n+1,ok);
	}
	if (num>1){
		++cnt;
		id[x][gd[x]++]=cnt;
		d[cnt]=num;
		int ok=1;
		if (x%2==1)add_edge(0,cnt,ok);
		if (x%2==0)add_edge(cnt,9*n+1,ok);
	}
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
	read(n),read(m);
	for (int i=1;i<=n;i++){
		int x;read(x);got(x,i);
	}
	for (int i=0;i<m;i++){
		int x,y;read(x),read(y);
		for (int i=0;i<gd[x];i++) for (int j=0;j<gd[y];j++) if (d[id[x][i]]==d[id[y][j]]){
			if (x%2==1)add_edge(id[x][i],id[y][j],5e5);
			else add_edge(id[y][j],id[x][i],5e5);
		}
	}
	write(maxflow(0,n*9+1));
}