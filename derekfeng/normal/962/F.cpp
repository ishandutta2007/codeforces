#include<bits/stdc++.h>
using namespace std;
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,m,u[2100002],v[2100002];
vector<int>g[100004];
int cnt,tms,low[100004],vis[100004],p[200004];
stack<int>st;
int sizv[100004],sizg[100004];
void tarjan(int x,int par){
	vis[x]=low[x]=++tms;
	st.push(x);
	for(int i=0;i<g[x].size();i++){
		if(vis[g[x][i]])low[x]=min(low[x],vis[g[x][i]]);
		else{
			tarjan(g[x][i],x),low[x]=min(low[x],low[g[x][i]]);
			if(low[g[x][i]]==vis[x]){
				cnt++;
				sizv[cnt-n]++;
				p[cnt]=x;
				while(1){
					int u=st.top();st.pop();
					p[u]=cnt;
					sizv[cnt-n]++;
					if(u==g[x][i])break;
				}
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	cnt=n;
	for(int i=0;i<m;i++){
		scanf("%d%d",&u[i],&v[i]);
		g[u[i]].push_back(v[i]);
		g[v[i]].push_back(u[i]);
	}
	for(int i=1;i<=n;i++)if(!vis[i])tarjan(i,-1),st.pop();
	for(int i=0;i<m;i++){
		if(p[u[i]]==p[v[i]])sizg[p[u[i]]-n]++;
		else{
			if(p[p[u[i]]]!=v[i])swap(u[i],v[i]);
			sizg[p[u[i]]-n]++;
		}
	}
	vector<int>res;
	for(int i=0;i<m;i++)
		if(sizv[p[u[i]]-n]==sizg[p[u[i]]-n])res.push_back(i+1);
	write(res.size()),puts("");
	for(int i=0;i<res.size();i++)write(res[i]),putchar(' ');
}