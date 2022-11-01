#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
using namespace std;
inline void read(int &x){
	scanf("%d",&x);
}
const int maxn=400005;
char s[maxn];
int n;
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
#define ls(x) ((x)<<1)
#define rs(x) (((x)<<1)|1)
#define dg(...) fprintf(stderr,__VA_ARGS__)
namespace seg{
	int son[maxn*20][2],sum[maxn*20],cnt;
	inline void upd(int x){
		sum[x]=sum[son[x][0]]+sum[son[x][1]];
	}
	inline int merge(int x,int y){
//		dg("%d %d\n",x,y);
		if(x==0||y==0)return x+y;
		int v=++cnt;
		rep(i,0,1)son[v][i]=merge(son[x][i],son[y][i]);
		upd(v);
		return v;
	}
	inline void add(int &x,int y,int lq,int rq,int pl){
		x=++cnt;rep(i,0,1)son[x][i]=son[y][i];sum[x]=sum[y]+1;if(lq==rq)return;
		int md=(lq+rq)>>1;
		if(pl<=md)
			add(son[x][0],son[y][0],lq,md,pl);
		else 
			add(son[x][1],son[y][1],md+1,rq,pl);
	}
	inline int query(int x,int l,int r,int lq,int rq){
		if(lq>rq)return 0;
		if(l>=lq&&r<=rq)return sum[x];int md=(l+r)>>1;
		int res=0;
		if(lq<=md)res+=query(son[x][0],l,md,lq,rq);
		if(rq>md)res+=query(son[x][1],md+1,r,lq,rq);
		return res;
	}
}bool tg[maxn];int len[maxn];
namespace tree{
	int fa[maxn][19],rt[maxn];
	vector<int> sons[maxn];
	inline void addson(int x,int y){
//		dg("%d %d\n",x,y);
		assert(x);
		sons[x].pb(y);fa[y][0]=x;
	}
	inline void dfs(int x){
		rep(i,1,18)fa[x][i]=fa[fa[x][i-1]][i-1];
		if(tg[x])seg::add(rt[x],rt[x],1,n,len[x]);
		for(int v:sons[x]){
			dfs(v);
			rt[x]=seg::merge(rt[x],rt[v]);//rt[x]=seg::merge(rt[x],rt[v]);
		}
//		dg("!%d %d\n",x,rt[x]);
	}
}
namespace sam{
	int trans[maxn][26],parent[maxn],cnt,last,root;
	int occ[maxn];
	inline void init(){root=last=++cnt;}
	inline void add(char c){
		c-='a';int p=++cnt;len[p]=len[last]+1;tg[p]=1;occ[p]=len[p];
		while(last&&!trans[last][c])trans[last][c]=p,last=parent[last];
		if(!last){parent[p]=root;last=p;return;}int q=trans[last][c];
		if(len[q]==len[last]+1)parent[p]=q;
		else{
			int nq=++cnt;memcpy(trans[nq],trans[q],sizeof(trans[q]));parent[nq]=parent[q];
			len[nq]=len[last]+1;parent[q]=parent[p]=nq;occ[nq]=occ[p];
			for(;last&&trans[last][c]==q;last=parent[last])trans[last][c]=nq;
		}last=p;
	}
}
int f[maxn],g[maxn],ans;
inline void printstr(int r,int l){
	rep(i,l,r)dg("%c",s[i]);
	dg("\n");
}
inline void solve(int x){
	using namespace tree;
	using namespace seg;
	using namespace sam;
	int v=x;
	int r=occ[x];
	int l=r-(len[x])+1;
	per(i,18,0){
		if(!fa[v][i]||(fa[v][i]==1))continue;
		int tm=fa[v][i];
		int whx=query(rt[tm],1,n,l+len[tm]-1,r-1);
		if(!whx)v=fa[v][i];
	}v=fa[v][0];
//	dg("%d %d\n",x,v);
//	printstr(occ[x],occ[x]-len[x]+1);
//	printstr(occ[v],occ[v]-len[v]+1);
	f[x]=max(g[v]+1,f[fa[x][0]]);
	if(x==1)f[x]=0;
	g[x]=max(g[fa[x][0]],f[x]);
	ans=max(ans,f[x]);
	for(int v:sons[x])solve(v);
}
int main(){
//	judge();
	read(n);scanf("%s",s+1);sam::init();
	using namespace sam;
	rep(i,1,n)add(s[i]);
	rep(i,2,cnt){using namespace tree;addson(parent[i],i);}
	tree::dfs(1);//dg("ok");
	solve(1);
	cout<<ans<<endl;
}