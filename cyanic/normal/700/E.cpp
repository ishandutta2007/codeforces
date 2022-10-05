#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define pb push_back
using namespace std;
typedef vector<int> vi;
 
const int N=500005;
namespace seg{
	#define mid (l + r >> 1)
	int lc[N<<5],rc[N<<5],T[N<<5],size;
	int ins(int l,int r,int x){
		int o=++size;
		if(l==r)return T[o]=1,o;
		if(x<=mid)lc[o]=ins(l,mid,x);
		else rc[o]=ins(mid+1,r,x);
		return T[o]=T[lc[o]]|T[rc[o]],o;
	}
	int merge(int x,int y,int l,int r){
		if(!x||!y)return x|y;
		int o=++size;
		if(l==r)T[o]=T[x]|T[y];
		else{
			lc[o]=merge(lc[x],lc[y],l,mid);
			rc[o]=merge(rc[x],rc[y],mid+1,r);
		}
		return T[o]=T[lc[o]]|T[rc[o]],o;
	}
	int query(int o,int l,int r,int x,int y){
		if(!o)return 0;
		if(l==x&&y==r)return T[o];
		if(y<=mid)return query(lc[o],l,mid,x,y);
		if(mid<x)return query(rc[o],mid+1,r,x,y);
		if(query(lc[o],l,mid,x,mid))return 1;
		return query(rc[o],mid+1,r,mid+1,y);
	}
	#undef mid
}
int n;
namespace sam{
	int t[N][26],fa[N],mx[N],pos[N],rt[N];
	int dp[N],id[N],ans,size=1,tail=1;
	vi e[N];
	inline int nw(int x){
		return mx[++size]=x,size;
	}
	void ins(int c,int x){
		int p=tail,np=nw(mx[p]+1);pos[np]=x;
		rt[np]=seg::ins(1,n,x);
		for(;p&&!t[p][c];p=fa[p])t[p][c]=np;
		if(!p)return(void)(fa[np]=1,tail=np);
		int q=t[p][c];
		//printf("# %d %d\n",np,x);
		if(mx[q]==mx[p]+1)fa[np]=q;
		else{
			int nq=nw(mx[p]+1);pos[nq]=x;
			fa[nq]=fa[q],fa[q]=fa[np]=nq;
			REP(k,26)t[nq][k]=t[q][k];
			for(;t[p][c]==q;p=fa[p])t[p][c]=nq;
		}
		tail=np;
	}
	void dfs1(int u){
		//if(u>=2)rt[u]=seg::ins(1,n,pos[u]);
		for(auto v:e[u])
			dfs1(v),rt[u]=seg::merge(rt[u],rt[v],1,n);
	}
	void dfs2(int u){
		if(fa[u]==1)dp[u]=1,id[u]=u;
		else if(u>=2){
			if(seg::query(rt[id[fa[u]]],1,n,
						  pos[u]-mx[u]+mx[id[fa[u]]],pos[u]-1))
				dp[u]=dp[fa[u]]+1,id[u]=u;
			else
				dp[u]=dp[fa[u]],id[u]=id[fa[u]];
		}
		ans=max(ans,dp[u]);
		//printf("%d %d  %d %d\n",u,dp[u],fa[u],id[fa[u]]);
		for(auto v:e[u])dfs2(v);
	}
	int solve(){
		rep(i,2,size)e[fa[i]].pb(i);
		dfs1(1),dfs2(1);
		return ans;
	}
};
char s[N];
 
int main(){
	scanf("%d%s",&n,s+1);
	rep(i,1,n)sam::ins(s[i]-'a',i);
	cout<<sam::solve()<<endl;
	return 0;
}