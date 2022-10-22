#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
int n,a[300004],N;
pii rg0[300004];
bool ocur[300004];
struct Kuhn{
	vector<int>g[605];
	int mch[150004];
	bool vs[150004];
	void init(){
		memset(mch,-1,sizeof(mch));
		for(int i=1;i<=600;i++)g[i].clear();
	}
	bool dfs(int x){
		for(auto to:g[x])if(!vs[to]){
			vs[to]=1;
			if(mch[to]<0||dfs(mch[to])){
				mch[to]=x;
				return 1;
			}
		}
		return 0;
	}
	void adde(int u,int v){
		g[u].push_back(v);
	}
	void solve(){
		for(int i=1;i<=600;i++)
			memset(vs,0,sizeof(vs)),dfs(i);
	}
}Gr1;
struct Edmonds{
	int n,nxt[1000000],hd[1300],t[1000000],cnte;
	void adde(int fr,int to){
		int id=++cnte;
		nxt[id]=hd[fr],hd[fr]=id,t[id]=to;
	}
	int f[1300];
	int F(int x){
		return f[x]==x?x:f[x]=F(f[x]); 
	}
	queue<int>que;
	int mch[1300],ans,col[1300],pre[1300],dfn[1300],cnt;
	int lca(int u,int v){
		++cnt;
		u=F(u),v=F(v);
		while(dfn[u]!=cnt){
			dfn[u]=cnt;
			u=F(pre[mch[u]]);
			if(v)swap(u,v);
		}
		return u;
	}
	void blossom(int u,int v,int L){
		while(F(u)!=L){
			pre[u]=v,v=mch[u];
			if(col[v]==2)col[v]=1,que.push(v);
			if(F(u)==u)f[u]=L;
			if(F(v)==v)f[v]=L;
			u=pre[v];
		}
	}
	bool bfs(int x){
		while(!que.empty())que.pop();
		for(int i=1;i<=n;i++)f[i]=i,col[i]=pre[i]=0;
		que.push(x),col[x]=1;
		while(!que.empty()){
			int u=que.front();que.pop();
			for(int i=hd[u];i;i=nxt[i]){
				int v=t[i];
				if(F(u)==F(v)||col[v]==2)continue;
				if(!col[v]){
					col[v]=2,pre[v]=u;
					if(!mch[v]){
						for(int j=v,p;j;j=p)
							p=mch[pre[j]],mch[j]=pre[j],mch[pre[j]]=j;
						return 1;
					}
					col[mch[v]]=1,que.push(mch[v]);
				}else{
					int L=lca(u,v);
					blossom(u,v,L);
					blossom(v,u,L);
				}
			}
		}
		return 0;
	}
	void init(){
		memset(hd,0,sizeof(hd));
		memset(nxt,0,sizeof(nxt));
		memset(t,0,sizeof(t));
		cnte=0;
		memset(mch,0,sizeof(mch));
	}
	void solve(){
		for(int i=1;i<=n;i++)if(!mch[i])bfs(i);
	}
}Gr2;
int main(){
	scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++)if(a[i]==a[i+1])ocur[a[i]]=1;
	for(int l=1,r;l<=n;l=r){
		if(a[l]!=0)r=l+1;
		else{
			for(r=l;r<=n&&a[r]==0;r++);
			rg0[++N]={l,r-1};
		}
	}
	Gr1.init();
	for(int i=1;i<=N;i++){
		int L=rg0[i].fi,R=rg0[i].se;
		if((R-L+1)&1){
			if(L!=1&&!ocur[a[L-1]])Gr1.adde(a[L-1],i);
			if(R!=n&&!ocur[a[R+1]])Gr1.adde(a[R+1],i);
		}
	}
	Gr1.solve();
	Gr2.init();
	int m=600;
	for(int i=1;i<=N;i++){
		int L=rg0[i].fi,R=rg0[i].se;
		if((R-L+1)&1){
			if(Gr1.mch[i]!=-1){
				++m;
				if(L!=1&&!ocur[a[L-1]])Gr2.adde(m,a[L-1]),Gr2.adde(a[L-1],m);
				if(R!=n&&!ocur[a[R+1]])Gr2.adde(m,a[R+1]),Gr2.adde(a[R+1],m);  
			}
		}else if(L!=1&&R!=n&&a[L-1]!=a[R+1]&&!ocur[a[L-1]]&&!ocur[a[R+1]])Gr2.adde(a[L-1],a[R+1]),Gr2.adde(a[R+1],a[L-1]);
	}
	Gr2.n=m;
	Gr2.solve();
	m=600;
	for(int i=1;i<=N;i++){
		int L=rg0[i].fi,R=rg0[i].se;
		if((R-L+1)&1){
			if(Gr1.mch[i]!=-1){
				++m;
				if(Gr2.mch[m]!=0){
					int x=Gr2.mch[m];
					if(L!=1&&a[L-1]==x)a[L]=x,L++;
					else a[R]=x,R--;
				}
			}
		}else{
			if(L!=1&&R!=n){
				if(Gr2.mch[a[L-1]]==a[R+1]){
					Gr2.mch[a[L-1]]=0;
					Gr2.mch[a[R+1]]=0;
					a[L]=a[L-1],a[R]=a[R+1];
					L++,R--;
				}
			}
		}
		rg0[i]={L,R};
	}
	vector<int>all;int it=0;
	memset(ocur,0,sizeof(ocur));
	for(int i=1;i<n;i++)if(a[i]==a[i+1])ocur[a[i]]=1;
	for(int i=1;i<=n;i++)if(!ocur[i])all.push_back(i);
	for(int i=1;i<=n;i++)if(a[i]==0){
		a[i]=all[it++];
		if(i<n&&a[i+1]==0)a[i+1]=a[i];
	}
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
}