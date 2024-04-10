#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define maxn 200009
#define maxm 200009
using namespace std;
int n,m,w[maxn],c[maxn],p[maxn],dep[maxn];
int T[maxn],P[maxn][20],E[maxn],Q[maxn][20];
bool mark[maxm];
long long cost=0;
vector<pair<int,int> >G[maxn];
struct Edge{
	int u,v,id;
	int replace;
	Edge(int _u=0,int _v=0,int _id=0){
		u=_u;v=_v;id=_id;
	}
	bool operator<(const Edge &rhs)const{
		return w[id]<w[rhs.id];
	}
}edge[maxm];


int findset(int x){
	return x==p[x]?x:p[x]=findset(p[x]);
}

void unionset(int x,int y){
	p[findset(x)]=findset(y);
}

void MST(){
	for(int i=1;i<=n;i++)
		p[i]=i;
	sort(edge+1,edge+m+1);
	for(int i=1;i<=m;i++){
		int u=edge[i].u;
		int v=edge[i].v;
		if(findset(u)==findset(v))
			continue;
		G[u].push_back(make_pair(v,edge[i].id));
		G[v].push_back(make_pair(u,edge[i].id));
		cost+=w[edge[i].id];
		unionset(u,v);
		mark[edge[i].id]=1;
	}
}

void dfs(int u,int fa,int eg,int d){
	T[u]=fa;
	E[u]=eg;
	dep[u]=d;
	for(auto it:G[u]){
		int v=it.first;
		if(v==fa) continue;
		dfs(v,u,it.second,d+1);
	}
}

void init(){
	for(int i=1;i<=n;i++)
		P[i][0]=T[i];

	for(int j=1;j<=19;j++)
		for(int i=1;i<=n;i++)
			if(P[i][j-1]!=-1)
				P[i][j]=P[P[i][j-1]][j-1];
			else
				P[i][j]=-1;

	for(int i=1;i<=n;i++){
		Q[i][0]=E[i];
	}

	for(int j=1;j<=19;j++){
		for(int i=1;i<=n;i++){
			if(P[i][j]==-1)
				Q[i][j]=-1;
			else if(w[Q[i][j-1]]>w[Q[P[i][j-1]][j-1]])
				Q[i][j]=Q[i][j-1];
			else
				Q[i][j]=Q[P[i][j-1]][j-1];
		}
	}
}

int lca(int p,int q){
	if(dep[q]>dep[p])
		swap(p,q);
	int ans=0,pos=-1;
	for(int i=19;i>=0;i--){
		if(dep[p]-(1<<i)>=dep[q]){
			if(w[Q[p][i]]>ans){
				ans=w[Q[p][i]];
				pos=Q[p][i];
			}
			p=P[p][i];
		}
	}

	//printf("lca %d %d\n",p,q);

	if(p==q){
		return pos;
	}

	for(int i=19;i>=0;i--){
		if(P[p][i]==-1||P[p][i]==P[q][i])
			continue;
		if(w[Q[p][i]]>ans){
			ans=w[Q[p][i]];
			pos=Q[p][i];
		}
		if(w[Q[q][i]]>ans){
			ans=w[Q[q][i]];
			pos=Q[q][i];
		}
		p=P[p][i];
		q=P[q][i];	
	}

	if(w[E[p]]>ans){
		ans=w[E[p]];
		pos=E[p];
	}

	if(w[E[q]]>ans){
		ans=w[E[q]];
		pos=E[q];
	}

	return pos;
}

bool cmp(Edge a,Edge b){
	return a.id<b.id;
}
int main(){
	int S;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&edge[i].u,&edge[i].v);
		edge[i].id=i;
	}
	scanf("%d",&S);

	MST();
	
	dfs(1,-1,-1,0);

	init();

	int ans=1e9,pos=-1;
	for(int i=1;i<=m;i++){
		int u=edge[i].u;
		int v=edge[i].v;
		edge[i].replace=lca(u,v);
		int gen=w[edge[i].id]-w[edge[i].replace]-S/c[edge[i].id];
		if(gen<ans){
			ans=gen;
			pos=i;
		}
	}


	cout<<cost+ans<<endl;
	mark[edge[pos].replace]=0;
	mark[edge[pos].id]=1;
	w[edge[pos].id]-=S/c[edge[pos].id];
	for(int i=1;i<=m;i++){
		if(!mark[i]) continue;
		printf("%d %d\n",i,w[i]);
	}
	//system("pause");
	return 0;
}