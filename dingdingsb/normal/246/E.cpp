#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chk(a,b) ((a)>=0&&(a)<(b).size())
using namespace std;
const int N=1e5+10;
int n,m,fa[N],w[N],dep[N];
vector<int>e[N];string s;
int tot;map<string,int>mAp;
int dfn[N],idfn[N],sz[N],cnt;
//C*F****
int t[N];
#define lowbit(x) ((x)&-(x))
void upd(int x,int val){
	x++;
	for(;x<=n+10;x+=lowbit(x))
		t[x]+=val;
}
int qry(int x){
	x++;
	int res=0;
	for(;x;x-=lowbit(x))
		res+=t[x];
	return res;
}
//asdasdasdasd
vector<int>c[N];
void dfs(int u){
	sz[u]=1;if(u)dep[u]=dep[fa[u]]+1;
	dfn[u]=++cnt;idfn[cnt]=u;c[dep[u]].pb(cnt);
	for(auto v:e[u])
		dfs(v),sz[u]+=sz[v];
}
int ans[N],buc[N];
vector<pair<int,int>>q[N];
//first second  
signed main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s>>fa[i];
		if(!mAp[s])mAp[s]=++tot;
		w[i]=mAp[s];
		e[fa[i]].pb(i);
	}
	dfs(0);
	cin>>m;
	for(int i=1;i<=m;i++){
		int p,k;cin>>p>>k;
		int ddep=dep[p]+k;
		int st=lower_bound(c[ddep].begin(),c[ddep].end(),dfn[p])-c[ddep].begin();
		int ed=lower_bound(c[ddep].begin(),c[ddep].end(),dfn[p]+sz[p])-c[ddep].begin()-1;
		if(!chk(st,c[ddep])||!chk(ed,c[ddep]))continue;
		if(st>ed)continue;
		q[idfn[c[ddep][ed]]].pb(mp(st,i));
	}
	memset(buc,-1,sizeof buc);
	for(int d=1;d<=n;d++)if(c[d].size()){
		for(int i=0;i<c[d].size();i++){
			int now=idfn[c[d][i]];
			if(buc[w[now]]!=-1)upd(buc[w[now]],-1);
			buc[w[now]]=i;upd(buc[w[now]],1);
			for(auto&[st,id]:q[now])
				ans[id]=qry(c[d].size())-qry(st-1);
		}
		for(int i=0;i<c[d].size();i++){
			int now=idfn[c[d][i]];
			if(buc[w[now]]!=-1)
				upd(buc[w[now]],-1),buc[w[now]]=-1;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<'\n';
    return 0;
}