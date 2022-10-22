#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x){
	register char ch=getchar();x=0;
	for(;ch==' '||ch=='\n';ch=getchar());
	for(;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,m,K,tms,cnt,rt,maxx,u[400004],v[400004];
int vis[400004],low[400004],cmp[400004],siz[400004];
stack<int>st;
vector<int>g[400004],num[400004];
void dfs(int x,int par){
	vis[x]=low[x]=++tms,st.push(x);
	bool parnum=0;
	for(int i=0;i<g[x].size();i++)if(g[x][i]!=par){
		if(!vis[g[x][i]])dfs(g[x][i],x),low[x]=min(low[x],low[g[x][i]]);
		else low[x]=min(low[x],vis[g[x][i]]);
	}
	if(low[x]==vis[x]){
		++cnt;
		while(1){
			int u=st.top();
			cmp[u]=cnt,siz[cnt]++;
			st.pop();
			if(u==x)break;
		}
		if(maxx<siz[cnt])maxx=siz[cnt],rt=cnt;
	}
}
queue<int>que,que1;
bool used[400004],vis1[400004];
int ans[400004];
void dfs1(int x,int par,int w){
	vis1[x]=1;
	for(int i=0;i<g[x].size();i++)if(g[x][i]!=par){
		if(w!=cmp[g[x][i]]&&!used[cmp[g[x][i]]]){
			ans[num[x][i]]=g[x][i];
			que.push(cmp[g[x][i]]),que1.push(g[x][i]);
			continue;
		}
		if(vis1[g[x][i]]){
			if(ans[num[x][i]]<1)ans[num[x][i]]=x;continue;
		}
		ans[num[x][i]]=x,dfs1(g[x][i],x,w);
	}
}
void ansmake(int x,int root){
	que.push(x),que1.push(root);
	while(!que.empty()){
		int uu=que.front(),rt_=que1.front();que.pop(),que1.pop();used[uu]=1;
		dfs1(rt_,-1,uu);
	}
}
int main(){
	//
	read(n),read(m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&u[i],&v[i]);
		g[u[i]].push_back(v[i]);
		g[v[i]].push_back(u[i]); 
		num[u[i]].push_back(i);
		num[v[i]].push_back(i); 
	}
	dfs(1,-1);
	write(maxx),puts("");
	int root;
	for(int i=1;i<=n;i++)if(rt==cmp[i]){
		root=i;break;
	}
	ansmake(rt,root);
	for(int i=0;i<m;i++)write(ans[i]),putchar(' '),write(u[i]+v[i]-ans[i]),puts("");
}