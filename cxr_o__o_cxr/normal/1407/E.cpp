//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=5e5+4;
struct edge{
	int u,v,w,nxt;
}E[N],e[N];
int first[N],cnt;
inline void add(int u,int v,int w){
//	cerr<<u<<" "<<v<<" "<<w<<" edge\n";
	e[++cnt].v=v;e[cnt].w=w;
	e[cnt].nxt=first[u];first[u]=cnt;
}
inline bool comp_e(const edge &a,const edge &b){
	return a.u==b.u?a.v<b.v:a.u<b.u;
}
int n,m,dis[N],col[N];
queue<int>q;
int main(){
	n=read();m=read();
	for(int i=1;i<=m;i++){
		E[i].u=read();E[i].v=read();E[i].w=read()+1;
	}
	sort(E+1,E+m+1,comp_e);
	for(int i=1,w=0;i<=m;i++){
		w|=E[i].w;
		if(E[i].u!=E[i+1].u||E[i].v!=E[i+1].v){
			add(E[i].v,E[i].u,w);
			w=0;
		}
	}
	memset(dis,-1,sizeof(dis));
	dis[n]=0;
	q.push(n);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=first[x],v;i;i=e[i].nxt){
			v=e[i].v;
			if(col[v]==e[i].w||e[i].w==3){
				if(dis[v]>=0)continue;
				dis[v]=dis[x]+1;
				q.push(v);
			}
			else col[v]=3-e[i].w;
		}
	}
	cout<<dis[1]<<"\n";
//	for(int i=1;i<=n;i++)cerr<<dis[i]<<" ";puts("");
	for(int i=1;i<=n;i++){
		if(!col[i])col[i]=1;
		cout<<col[i]-1;
	}
	return (0-0);
}