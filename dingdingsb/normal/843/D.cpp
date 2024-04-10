// Problem: CF843D Dynamic Shortest Path
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF843D
// Memory Limit: 500 MB
// Time Limit: 10000 ms
// Author: Juruo_cjl
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
const int N=1e5+100;
int n,m,q;
vector<pair<int,int>>e[N];
pair<int,int>id[N];
typedef long long ll;
ll dis[N],d[N];bool vis[N];
void dij(){
	memset(dis,0x3f,sizeof dis);
	priority_queue<pair<ll,int>>q;q.push({0,1});dis[1]=0;
	memset(vis,0,sizeof vis);
	while(q.size()){
		int u=q.top().second;q.pop();
		if(vis[u])continue;vis[u]=1;
		for(auto[v,w]:e[u])if(dis[v]>dis[u]+w){
			dis[v]=dis[u]+w;
			q.push({-dis[v],v});
		}
	}
}
queue<int>Q[N];
void upd(){
	int c,l;read(c);
	for(int SJYAK=1;SJYAK<=c;SJYAK++){
		read(l);
		e[id[l].first][id[l].second].second++;
	}
	for(int i=1;i<=n;i++)
		d[i]=min(dis[i]+c+1,0x3f3f3f3f3f3f3f3f),vis[i]=0;
	d[1]=0;Q[0].push(1);
	for(int i=0;i<=n&&i<=c;i++){
		while(Q[i].size()){
			int u=Q[i].front();Q[i].pop();
			if(vis[u])continue;vis[u]=1;
			for(auto [v,w]:e[u])if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				Q[d[v]-dis[v]].push(v);
			}
		}
	}
	for(int i=1;i<=n;i++)dis[i]=d[i];
}
signed main(){
	read(n,m,q);
	for(int i=1;i<=m;i++){
		int u,v,w;read(u,v,w);
		e[u].push_back({v,w});
		id[i]={u,e[u].size()-1};
	}
	dij();
	while(q--){
		int op,v;read(op);
		if(op==1){
			read(v);
			if(dis[v]==0x3f3f3f3f3f3f3f3f)puts("-1");
			else write(dis[v]),putchar('\n');
		}else upd();
	}
}