#include<bits/stdc++.h>
using namespace std;
void outno(){puts("NO");exit(0);}
int n,m;
int d[53],u[2503],v[2503];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >L;
vector<int>g[53],cur;
int vis[53];
int dfs_sol1(int x){vis[x]=1;int ret=0;for(auto y:g[x])if(!vis[y]){ret=dfs_sol1(y);break;}return ret+1;}
void dfs_sol2(int x){cur.push_back(x);vis[x]=1;for(auto y:g[x])if(!vis[y])dfs_sol2(y);}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&u[i],&v[i]);d[u[i]]++,d[v[i]]++;g[u[i]].push_back(v[i]),g[v[i]].push_back(u[i]);  
		if(d[u[i]]>2||d[v[i]]>2)outno();
	}
	if(n==m){int tmp=dfs_sol1(1);if(tmp!=n)outno();memset(vis,0,sizeof(vis));puts("YES\n0");exit(0);}
	for(int i=1;i<=n;i++){
		if(d[i]==0){vis[i]=1;L.push(make_pair(i,i));}
		if(d[i]==1&&!vis[i]){cur.clear();dfs_sol2(i);if(cur[0]>cur.back())reverse(cur.begin(),cur.end());L.push(make_pair(cur[0],cur.back()));}
	}
	for(int i=1;i<=n;i++)if(!vis[i])outno();
	memset(vis,0,sizeof(vis));
	puts("YES");printf("%d\n",(int)L.size());
	while(L.size()>1){
		pair<int,int> u=L.top();L.pop();pair<int,int> v=L.top();L.pop();
		printf("%d %d\n",u.first,v.first);L.push(make_pair(min(u.second,v.second),max(u.second,v.second)));
	}
	printf("%d %d",L.top().first,L.top().second);
}