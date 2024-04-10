#include<bits/stdc++.h>
using namespace std;
int T=1,n,a[100003],b[100003],idx1[100003],idx2[100003];
bool cmpa(int x,int y){return a[x]>a[y];}
bool cmpb(int x,int y){return b[x]>b[y];}
vector<int>g[100003],rg[100003],V;
void add_edge(int x,int y){
	g[x].push_back(y);
	rg[y].push_back(x);
}
bool vis[100003];
void dfs(int x){
	vis[x]=1;
	for(int i=0;i<g[x].size();i++)
		if(!vis[g[x][i]])
			dfs(g[x][i]);
	V.push_back(x);
}
int cmp[100003];
void rdfs(int x,int col){
	vis[x]=1;cmp[x]=col;
	for(int i=0;i<rg[x].size();i++)
		if(!vis[rg[x][i]])
			rdfs(rg[x][i],col);
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)
			scanf("%d",a+i),idx1[i]=i,g[i].clear(),rg[i].clear();
		for(int i=0;i<n;i++)
			scanf("%d",b+i),idx2[i]=i;
		sort(idx1,idx1+n,cmpa);
		sort(idx2,idx2+n,cmpb);
		for(int i=1;i<n;i++){
			add_edge(idx1[i-1],idx1[i]);
			add_edge(idx2[i-1],idx2[i]);
		}
		memset(vis,0,sizeof(vis));
		V.clear();
		for(int i=0;i<n;i++)
			if(!vis[i])
				dfs(i);
		memset(vis,0,sizeof(vis));
		int cnt=0;
		for(int i=n-1;i>=0;i--)	
			if(!vis[V[i]])
				rdfs(V[i],cnt++);
		for(int i=0;i<n;i++)
			if(cmp[i])
				putchar('0');
			else
				putchar('1');
		cout<<endl;
	}
}