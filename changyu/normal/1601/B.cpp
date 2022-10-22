#include<bits/stdc++.h>
const int N=3e5+3,D=1<<19;
struct edge{int v,c;};
std::vector<edge>g[N+D*2];
//xunhuan queue
int dis[N+D*2],n,a[N],b[N],la[N+D*2];
typedef std::pair<int,int> P;
std::deque<P>q;
inline void Init(){
	for(int k=n+D;k>1;k--)g[k>>1].push_back((edge){k,0});//,printf(" edge %d %d %d\n",k>>1,k,0);
} 
inline void Edge(int u,int l,int r){
	for(l+=D-1,r+=D+1;l^r^1;l>>=1,r>>=1){
		if(~l&1)g[u].push_back((edge){l^1,1});//,printf("edge %d %d %d\n",u,l^1,1);
		if( r&1)g[u].push_back((edge){r^1,1});//,printf("edge %d %d %d\n",u,r^1,1);
	}
}
void Out(int u){
	if(u==n+D*2)return; 
	Out(la[u]);
	if(u>=D&&u<D*2)printf("%d ",u-D); 
}
int main(){
	int u,v;
	scanf("%d",&n);
	Init(); 
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		Edge(i+D*2,i-a[i],i);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",b+i);
		b[i]+=i;
		g[i+D].push_back((edge){b[i]+D*2,0});//,printf("edge %d %d %d\n",i+D,b[i]+D*2,0);
		//printf("%d %d\n",i+D,b[i]+D*2);
	}
	for(u=1;u<=n+D*2;u++)dis[u]=N; 
	q.push_back(P(dis[n+D*2]=0,n+D*2));
	for(;!q.empty();){
		u=q.front().second;
		if(q.front().first!=dis[u]){q.pop_front();continue;}
		q.pop_front();
		for(int i=0;i<g[u].size();i++)
			if(dis[v=g[u][i].v]>dis[u]+g[u][i].c){
				dis[v]=dis[u]+g[u][i].c;
				la[v]=u;
				if(g[u][i].c)
					q.push_back(P(dis[v],v));
				else
					q.push_front(P(dis[v],v));
			}
	}
	if(dis[0+D]==N)return 0*puts("-1"); 
	printf("%d\n",dis[0+D]);
	Out(0+D),puts(""); 
	return 0;
}