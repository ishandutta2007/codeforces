#include<bits/stdc++.h>
using namespace std;
const int MAX_N=2005;
struct Graph{
	struct Edge{ int to,nxt; }edge[MAX_N*2];
	int head[MAX_N],top;
	Graph(){memset(head,-1,sizeof(head)),top=-1;}
	inline void add(int x,int y){
		edge[++top]=(Edge){y,head[x]};
		head[x]=top;
	}
}G;
int a[MAX_N],c[MAX_N],sz[MAX_N];
void dfs1(int x){
	sz[x]=1;
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		dfs1(y); sz[x]+=sz[y];
	}
}
vector<int> s;
void dfs2(int x){
	if(c[x]>=sz[x]){
		puts("NO");
		exit(0);
	}
	a[x]=s[c[x]];
	s.erase(s.begin()+c[x]);
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		dfs2(y);
	}
}
int main(){
	int n,rt=0; scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int p; scanf("%d%d",&p,&c[i]);
		if(p==0) rt=i;
		else G.add(p,i);
		s.push_back(i);
	}
	dfs1(rt);
	dfs2(rt);
	puts("YES");
	for(int i=1;i<=n;++i) printf("%d ",a[i]);
	return 0;
}