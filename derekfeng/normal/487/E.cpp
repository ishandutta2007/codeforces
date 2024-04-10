#include<bits/stdc++.h>
using namespace std;
void write(int x){if(x>9)write(x/10);putchar(x%10+'0');}
int n,m,Q,w[100004];
int p[200004],tms,cnt,low[100004],vis[100004];
vector<int>g[100004],G[200004];
stack<int>st;
void tarjan(int x){
	vis[x]=low[x]=++tms;
	st.push(x);
	for(int i=0;i<g[x].size();i++){
		if(vis[g[x][i]])low[x]=min(low[x],vis[g[x][i]]);
		else{
			tarjan(g[x][i]),low[x]=min(low[x],low[g[x][i]]);
			if(low[g[x][i]]==vis[x]){
				++cnt;
				p[cnt]=x,G[x].push_back(cnt);
				while(1){
					int u=st.top();st.pop();
					p[u]=cnt,G[cnt].push_back(u);
					if(u==g[x][i])break;
				}
			}
		}
	}
}
int cnt1,h[200004],siz[200004],cmp[200004],nxt[200004];
void dfs(int x){
	siz[x]=1;
	int maxx=0;
	for(int i=0;i<G[x].size();i++){
		dfs(G[x][i]),siz[x]+=siz[G[x][i]];
		if(maxx<siz[G[x][i]])h[x]=G[x][i],maxx=siz[G[x][i]];
	}
}
void dfs1(int x,int H){
	cmp[x]=++cnt1,nxt[x]=H;
	if(h[x])dfs1(h[x],H);
	for(int i=0;i<G[x].size();i++)if(G[x][i]!=h[x])
		dfs1(G[x][i],G[x][i]); 
}
int cmp1[200004],L[200004],R[200004],cnt2;
void bfs(){
	queue<int>que;
	que.push(1),cmp1[1]=1,cnt2=1;
	while(!que.empty()){
		int u=que.front();que.pop();
		L[u]=cnt2+1;
		for(int i=0;i<G[u].size();i++)
			cmp1[G[u][i]]=++cnt2,que.push(G[u][i]);
		R[u]=cnt2;
	}
}
int cnt_=1,dat[525000],dat1[525000]; 
void upd(int *d,int id,int x){
	d[id]=x;
	while(id){
		id=(id-1)/2;
		d[id]=min(d[id*2+1],d[id*2+2]);
	}
}
int got(int *d,int l,int r,int id,int a,int b){
	if(r<a||b<l)return 1e9;
	if(a<=l&&r<=b)return d[id];
	return min(got(d,l,(l+r)/2,id*2+1,a,b),got(d,(l+r)/2+1,r,id*2+2,a,b));
}
void built(int *d,int l,int r,int id){
	if(l>cnt)return;
	if(l==r)return;
	built(d,l,(l+r)/2,id*2+1),built(d,(l+r)/2+1,r,id*2+2);
	d[id]=min(d[id*2+1],d[id*2+2]); 
}
char opt[3];
bool isans(int l,int r,int x){
	return cmp[l]<=cmp[x]&&cmp[x]<=cmp[r];
}
int fans(int u,int v){
	int ret=1e9;
	while(1){
		if(cmp[u]>cmp[v])swap(u,v);
		int L=nxt[v];
		if(isans(L,v,u)){
			ret=min(ret,got(dat1,1,cnt_,0,cmp[u],cmp[v]));
			if(u>n)ret=min(w[p[u]],ret);
			return ret;
		}
		ret=min(ret,got(dat1,1,cnt_,0,cmp[L],cmp[v]));
		v=p[L];
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	for(int i=0;i<m;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
	}
	cnt=n;
	tarjan(1);
	dfs(1);
	dfs1(1,1);
	bfs();
	while(cnt_<cnt)cnt_<<=1;
	for(int i=1;i<=n;i++)dat[cmp1[i]+cnt_-2]=dat1[cmp[i]+cnt_-2]=w[i];
	built(dat,1,cnt_,0);
	for(int i=n+1;i<=cnt;i++){
		int ret=got(dat,1,cnt_,0,L[i],R[i]);
		dat1[cmp[i]+cnt_-2]=ret;
	}
	built(dat1,1,cnt_,0);
	while(Q--){
		int u,v;scanf("%s%d%d",opt,&u,&v);
		if(*opt=='C'){
			w[u]=v;
			upd(dat,cmp1[u]+cnt_-2,v);
			upd(dat1,cmp[u]+cnt_-2,v);
			if(u>1){
				int par=p[u];
				int ret=got(dat,1,cnt_,0,L[par],R[par]);
				upd(dat1,cmp[par]+cnt_-2,ret);
			}                                                                                                                                                               
		}else write(fans(u,v)),puts("");
	}
}