#include<bits/stdc++.h>
using namespace std;
const long long  maxn=1e5+5;
struct rec{
	long long  val,cnt;
}dist[maxn],dep[maxn];   // val k      cnt l
long long  top,x,y,z,root,son[maxn],p[maxn],size,minn,pos,ans,tot,num,n,k,l,tree[maxn];
vector <rec> v[maxn]; 
long long  fir[maxn*2],nxt[maxn*2],gett[maxn*2],val[maxn*2],fa[maxn],a[maxn],f[maxn];
bool vis[maxn];
inline long long  max(long long  x,long long  y){if (x>y) return x; else return y;}
inline bool comp(const rec &x,const rec &y){return x.val<y.val;}
inline void add(long long  x,long long  y,long long  z){
	gett[++top]=y; val[top]=z;
	nxt[top]=fir[x]; fir[x]=top;
}
void dfs(long long  x,long long  fa){ 
	son[x]=1; a[++top]=x; f[x]=fa;
	for (long long  i=fir[x];i;i=nxt[i]){
		long long  v=gett[i];
		if (v==fa||vis[v]) continue;
		dfs(v,x); son[x]+=son[v];
	}
}
inline long long  get_focus(long long  x){
	top=0; dfs(x,0); 
	for (long long  i=1;i<=top;++i){
		long long  now=a[i];
		p[now]=max(p[now],top-son[now]);
		p[f[now]]=max(p[f[now]],son[now]);
	} 
	minn=1<<30;
	for (long long  i=1;i<=top;++i){
		if (p[a[i]]<minn){
			minn=p[a[i]]; pos=a[i];
		}
		p[a[i]]=0;
	}
	return pos;
}
void get_dist(long long  x,long long  fa){
	for (long long  i=fir[x];i;i=nxt[i]){
		long long  vv=gett[i];
		if (vv==fa||vis[vv]) continue;
		dep[vv].val=dep[x].val+val[i];  dep[vv].cnt=dep[x].cnt+1;
		dist[++num]=dep[vv]; 
		v[tot].push_back(dep[vv]); 
		get_dist(vv,x); 
	}
}
inline long long  lowbit(long long  x){return x&(-x);}
inline void t_add(long long  x,long long  y){while (x<n){tree[x]+=y;if (tree[x]<0) tree[x]=0; x+=lowbit(x);}}
inline long long  t_query(long long  x){long long  now=0;while (x>0){now+=tree[x];x-=lowbit(x);}return now;}
inline void t_clear(long long  x){while (x<n){tree[x]=0;x+=lowbit(x);}}
inline void get_ans(){
	for (long long  i=1;i<=tot;++i) sort(v[i].begin(),v[i].end(),comp);
	sort(dist+1,dist+1+num,comp);  long long  h,t;
	for (long long  i=1;i<=tot;++i){
		t=v[i].size()-1; if (v[i].size()<=1) continue;
		for (long long  j=0;j<v[i].size();++j) t_add(v[i][j].cnt,1);
		for (long long  h=0;h<v[i].size()-1;++h) {
			t_add(v[i][h].cnt,-1);
			while (v[i][h].val+v[i][t].val>k&&t>h){t_add(v[i][t].cnt,-1); --t; if (h>=t) break; }
			ans-=t_query(l-v[i][h].cnt); 
		}
		for (long long  j=1;j<v[i].size();++j) t_clear(v[i][j].cnt);
	}
	for (long long  i=1;i<=num;++i){
		if (dist[i].cnt<=l&&dist[i].val<=k) ++ans; 
	} 
	for (long long  i=1;i<=num;++i) t_add(dist[i].cnt,1); 
	t=num;
	for (long long  h=1;h<=num;++h){
		t_add(dist[h].cnt,-1);
		while (dist[h].val+dist[t].val>k&&t>h){
			t_add(dist[t].cnt,-1);--t; 
			if (h>=t) break; 
		}
		ans+=t_query(l-dist[h].cnt);
	} 
	for (long long  i=2;i<=num;++i) t_clear(dist[i].cnt);
}
void DFS(long long  x,long long  fa){
	dep[x].cnt=dep[x].val=0; tot=0; num=0; 
	for (long long  i=fir[x];i;i=nxt[i]){
		long long  vv=gett[i];
		if (vis[vv]||vv==fa) continue;
		++tot; v[tot].clear(); dep[vv].val=val[i]; dep[vv].cnt=1; 
		v[tot].push_back(dep[vv]); dist[++num]=dep[vv]; get_dist(vv,x);
	}  
	get_ans(); vis[x]=1; 
	for (long long  i=fir[x];i;i=nxt[i]){
		long long  v=gett[i];
		if (vis[v]||v==fa) continue;
		DFS(get_focus(v),x);
	}
}
int main(){
	scanf("%lld%lld%lld",&n,&l,&k); 
	for (long long  i=1;i<n;++i){
		scanf("%lld%lld",&x,&z);
		add(x,i+1,z); add(i+1,x,z); 
	}
	root=get_focus(1); 
	DFS(root,0); 
	printf("%lld",ans);
}