#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[503][503],qaq[503][503];
struct node {
	int to,net;
	long long val;
} e[520010];
long long ans,dis[520010],s,t;
int tot=1,vis[520010],pre[520010],head[520010],flag[2510][2510];
inline void add(int u,int v,long long w) {
	e[++tot].to=v;
	e[tot].val=w;
	e[tot].net=head[u];
	head[u]=tot;
	e[++tot].to=u;
	e[tot].val=0;
	e[tot].net=head[v];
	head[v]=tot;
}

inline int bfs() {  //bfs 
	for(register int i=1;i<=1003;i++) vis[i]=0;
	queue<int> q;
	q.push(s);
	vis[s]=1;
	dis[s]=2005020600;
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		for(register int i=head[x];i;i=e[i].net) {
			if(e[i].val==0) continue;  //>0 
			int v=e[i].to;
			if(vis[v]==1) continue;  // 
			dis[v]=min(dis[x],e[i].val);
			pre[v]=i;  // 
			q.push(v);
			vis[v]=1;
			if(v==t) return 1;  // 
		}
	}
	return 0;
}

inline void update() {  // 
	int x=t;
	while(x!=s) {
		int v=pre[x];
		e[v].val-=dis[t];
		e[v^1].val+=dis[t];
		x=e[v^1].to;
	}
	ans+=dis[t];   // 
}
string T[503];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>T[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(T[i][j]=='B')
				a[i][j]=1;
			else
				a[i][j]=0;
	long long ret=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			qaq[i][j]=a[i][j]^a[i][j+1]^a[i+1][j]^a[i+1][j+1],ret+=qaq[i][j]; 
	s=0;t=1003;
	for(int i=0;i<n;i++)
		if(qaq[i][m-1])
			add(0,i+1,1);
	for(int i=0;i<m;i++)
		if(qaq[n-1][i])
			add(n+i+1,1003,1);
	for(int i=0;i<n-1;i++)
		for(int j=0;j<m-1;j++)
			if(qaq[i][j])
				add(i+1,n+j+1,1);
	while(bfs()!=0)update();
	if(qaq[n-1][m-1])
		ret-=int((ans+1)/2)*2;
	else
		ret-=int(ans/2)*2;
	cout<<ret;
}