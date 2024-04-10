#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int n,m,q;
int dfn[N],low[N],scc[N],cnt,len;
stack<int> st;
bool ins[N];
vector<int> g[N],g2[N];
void tarjan(int u,int last){
	dfn[u]=low[u]=++cnt;
	st.push(u);ins[u]=1;
	for(auto v:g[u]){
		if(v==last) continue;
		if(dfn[v]){
			low[u]=min(low[u],dfn[v]);
		}
		else{
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				len++;
				scc[u]=len;
				g2[len].push_back(u);
				g2[u].push_back(len);
				while(!st.empty()){
					int x=st.top();st.pop();
					scc[x]=len;
					ins[x]=0;
					g2[x].push_back(len);
					g2[len].push_back(x);
					if(x==v) break;
				}
			}
		}
	}
}
int h[N],fa[N],top[N],sz[N],son[N],id[N],rk[N];
void dfs1(int u){
	h[u]=h[fa[u]]+1;
	sz[u]=1;
	for(auto v:g2[u]){
		if(v==fa[u]||g2[v].size()==1) continue;
		fa[v]=u;
		dfs1(v);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int tp){
	id[u]=++cnt;
	rk[cnt]=u;
	top[u]=tp;
	if(son[u]) dfs2(son[u],tp);
	for(auto v:g2[u]){
		if(v==fa[u]||v==son[u]||g2[v].size()==1) continue;
		dfs2(v,v);
	}
}
ll w[N];
multiset<ll> ms[N];
struct sgt{
	int ls,rs,l,r;
	ll mn;
}s[N<<1];
int rt,P;
inline void upd(int p){
	s[p].mn=min(s[s[p].ls].mn,s[s[p].rs].mn);
}
int build(int l,int r){
	int p=++P;
	s[p].l=l;s[p].r=r;
	if(l==r){
		s[p].mn=w[rk[l]];
		return p;
	}
	int mid=(l+r)>>1;
	s[p].ls=build(l,mid);
	s[p].rs=build(mid+1,r);
	upd(p);
	return p;
}
void chg(int p,int pos,ll x){
	if(s[p].l==s[p].r){
		s[p].mn=x;
		return;
	}
	int mid=(s[p].l+s[p].r)>>1;
	if(pos<=mid) chg(s[p].ls,pos,x);
	else chg(s[p].rs,pos,x);
	upd(p);
}
ll qry(int p,int l,int r){
	if(s[p].l==l&&s[p].r==r)
		return s[p].mn;
	int mid=(s[p].l+s[p].r)>>1;
	if(r<=mid) return qry(s[p].ls,l,r);
	else if(l>mid) return qry(s[p].rs,l,r);
	else return min(qry(s[p].ls,l,mid),qry(s[p].rs,mid+1,r));
}
ll query(int x,int y){
	ll ret=inf;
	while(top[x]!=top[y]){
		if(h[top[x]]>h[top[y]]){
			ret=min(ret,qry(rt,id[top[x]],id[x]));
			x=fa[top[x]];
		}
		else{
			ret=min(ret,qry(rt,id[top[y]],id[y]));
			y=fa[top[y]];
		}
	}
	if(id[x]>id[y]) swap(x,y);
	ret=min(ret,qry(rt,id[x],id[y]));
	if(x>n) ret=min(ret,w[fa[x]]);
	return ret;
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>m>>q;
	for(i=1;i<=n;i++) cin>>w[i];
	for(i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	len=n;
	tarjan(1,0);
	for(i=1;i<=n;i++)
		if(g2[i].size()>1) scc[i]=i;
//	for(i=1;i<=len;i++){
//		cout<<i<<": ";
//		for(auto v:g2[i]) cout<<v<<" ";
//		cout<<endl;
//	}
	cnt=0;
	int root=1;
	while(g2[root].size()==1) root++;
	dfs1(root);
	dfs2(root,root);
	for(i=n+1;i<=len;i++){
		w[i]=inf;
		for(auto v:g2[i]){
			if(g2[v].size()>1) continue;
			w[i]=min(w[i],w[v]);
			ms[i].insert(w[v]);
		}
	}
	for(i=1;i<=n;i++){
		if(!fa[i]) continue;
		w[fa[i]]=min(w[fa[i]],w[i]);
		ms[fa[i]].insert(w[i]);
	}
	rt=build(1,cnt);
	w[0]=inf;
	while(q--){
		char op;ll x,y;
		cin>>op>>x>>y;
		if(op=='C'){
			if(g2[x].size()>1){
				chg(rt,id[x],y);
				int v=fa[x];
				if(v){
					auto it=ms[v].find(w[x]);
					ms[v].erase(it);
					ms[v].insert(y);
					chg(rt,id[v],(*ms[v].begin()));
					//cout<<(*ms[v].begin())<<endl;					
				}
			}
			else{
				int v=g2[x][0];
				auto it=ms[v].find(w[x]);
				ms[v].erase(it);
				ms[v].insert(y);
				chg(rt,id[v],(*ms[v].begin()));
			}
			w[x]=y;
		}
		else{
			if(x==y) cout<<w[x]<<endl;
			else cout<<query(scc[x],scc[y])<<endl;
		}
		//cout<<qry(rt,1,cnt)<<endl;
	}
	return 0;
}