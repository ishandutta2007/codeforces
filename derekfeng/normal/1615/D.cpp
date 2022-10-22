#include<bits/stdc++.h>
using namespace std;
int T,n,m,u[200004],v[200004],fa[200004];
vector<int>g[200004],tr[400004];
int ans[200004],res[200004],fin[200004];
int tot,cnt,dfn[400004],low[400004],cmp[400004];
stack<int>st;
bool ins[400004];
void tarjan(int x){
	dfn[x]=low[x]=++tot;
	st.push(x),ins[x]=1;
	for(auto y:tr[x]){
		if(!dfn[y])tarjan(y);
		if(ins[y])low[x]=min(low[x],low[y]);
	}
	if(dfn[x]==low[x]){
		++cnt;
		for(;;){
			int u=st.top();st.pop();
			cmp[u]=cnt,ins[u]=0;
			if(u==x)break;
		}
	}
}
void dfs(int x,int pa){
	for(auto y:g[x])if(y!=pa){
		fa[y]=x,res[y]=res[x]^(ans[x]^ans[y]);
		dfs(y,x);
	}
}
void sol(){
	tot=cnt=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)g[i].clear(),tr[i].clear(),tr[i+n].clear();
	for(int i=1;i<=n+n;i++)dfn[i]=low[i]=cmp[i]=0;
	for(int i=1;i<n;i++){
		scanf("%d%d",&u[i],&v[i]),g[u[i]].push_back(v[i]),g[v[i]].push_back(u[i]);
		int w;scanf("%d",&w);
		fin[i]=-1;
		if(w>=0){
			fin[i]=w;
			w=__builtin_parity(w);
			int a=u[i],b=v[i];
			if(w==1){
				tr[a].push_back(b+n),tr[a+n].push_back(b);
				tr[b+n].push_back(a),tr[b].push_back(a+n);
			}else{
				tr[a].push_back(b),tr[a+n].push_back(b+n);
				tr[b].push_back(a),tr[b+n].push_back(a+n);
			}
		}
	}
	for(int i=0;i<m;i++){
		int a,b,v;scanf("%d%d%d",&a,&b,&v);
		if(v==1){
			tr[a].push_back(b+n),tr[a+n].push_back(b);
			tr[b+n].push_back(a),tr[b].push_back(a+n);
		}else{
			tr[a].push_back(b),tr[a+n].push_back(b+n);
			tr[b].push_back(a),tr[b+n].push_back(a+n);
		}
	}
	for(int i=1;i<=n+n;i++)if(!dfn[i])tarjan(i);
	for(int i=1;i<=n;i++){
		ans[i]=0;
		if(cmp[i+n]==cmp[i]){
			puts("NO");
			return;
		}
		if(cmp[i+n]<cmp[i])ans[i]=1;
	}
	puts("YES");
	res[1]=0,dfs(1,0);
	for(int i=1;i<n;i++){
		printf("%d %d ",u[i],v[i]);
		if(fa[u[i]]==v[i])swap(u[i],v[i]);
		if(fin[i]==-1)fin[i]=res[v[i]]^res[u[i]];
		printf("%d\n",fin[i]);
	}
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}