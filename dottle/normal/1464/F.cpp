#include<bits/stdc++.h>
const int N=450050;
using namespace std;

int n,q,cntr;

multiset<pair<int,int>> s;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
#define fx tp[x]
#define fy tp[y]
struct edge{
    int to,nx;
}e[N];int hd[N],S;
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S;
}
int fa[N],dp[N],sg[N],bc[N],sz[N],sn[N],tp[N],cnt;
void dfs(int k,int f){
    fa[k]=f,dp[k]=dp[f]+1,sz[k]=1;
    fore(k)if(_to!=f)
        dfs(_to,k),sz[k]+=sz[_to],sn[k]=sz[sn[k]]<sz[_to]?_to:sn[k];
}
void df5(int k,int t){
    tp[k]=t,sg[k]=++cnt,bc[cnt]=k;
    if(sn[k])df5(sn[k],t);
    fore(k)if(_to!=fa[k]&&_to!=sn[k])df5(_to,_to);
}
int lca(int x,int y){
    while(fx!=fy){
        if(dp[fx]<dp[fy])swap(x,y);x=fa[fx];
    }
    if(dp[x]<dp[y])swap(x,y);
    return y;
}
int gf(int x,int d){
	if(dp[x]<=d)return 1;
	int t;
	while(d)
		if(x==fx)x=fa[x],d--;
		else t=min(d,dp[x]-dp[fx]),d-=t,x=bc[sg[x]-t];
	return x;
}
int dis(int x,int y){
	if(x<=0||y<=0)return -1;
	return dp[x]+dp[y]-dp[lca(x,y)]*2;
}
struct path{
	int x,y;
	path operator +(path b){
		int nx=0,by=0,d=-1;
		if(dis(x,y)>d)    nx=x,  by=y  ,d=dis(x,y);
		if(dis(x,b.x)>d)  nx=x,  by=b.x,d=dis(x,b.x);
		if(dis(x,b.y)>d)  nx=x,  by=b.y,d=dis(x,b.y);
		if(dis(y,b.x)>d)  nx=y,  by=b.x,d=dis(y,b.x);
		if(dis(y,b.y)>d)  nx=y,  by=b.y,d=dis(y,b.y);
		if(dis(b.y,b.x)>d)nx=b.y,by=b.x,d=dis(b.y,b.x);
		return {nx,by};
	}
};
struct BIT{
    int a[N];
    void add(int k,int p){while(k<=n)a[k]+=p,k+=k&-k;}
    int sum(int k){int ans=0;while(k)ans+=a[k],k-=k&-k;return ans;}
    int sum(int l,int r){return sum(r)-sum(l-1);}
}X;

struct sgt{
    #define ls k<<1
    #define rs k<<1|1
    #define mid ((l+r)>>1)
    path s[N<<2];int cnt[N];
    void bld(int k,int l,int r){
    	s[k]={-1,-1};
    	if(l^r)bld(ls,l,mid),bld(rs,mid+1,r);
	}
    void pshup(int k){
        s[k]=s[ls]+s[rs];
    }
    path qry(int k,int l,int r,int x,int y){
        if(y<l||x>r)return {-1,-1};
        if(y>=r&&x<=l)return s[k];
        return qry(ls,l,mid,x,y)+qry(rs,mid+1,r,x,y);
    }
    void updt(int k,int l,int r,int x,int p){
        if(l^r){
            if(x<=mid)updt(ls,l,mid,x,p);
            else updt(rs,mid+1,r,x,p);
            pshup(k);
        }else p?(s[k]={bc[x],bc[x]}):(s[k]={-1,-1});
    }
    void add(int k){if(!cnt[k])updt(1,1,n,sg[k],1);cnt[k]++;}
    void del(int k){cnt[k]--;if(!cnt[k])updt(1,1,n,sg[k],0);}
}T;

auto ask(int k){
	int x=gf(s.rbegin()->second,k),t=gf(x,k);
	if(X.sum(sg[t],sg[t]+sz[t]-1)!=cntr){
		cout<<"No";return ;
	}
	path ps=T.qry(1,1,n,sg[t],sg[t]+sz[t]-1);
	if(dis(x,ps.x)<=k&&dis(x,ps.y)<=k)cout<<"Yes";
	else cout<<"No";
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		add(x,y),add(y,x);
	}
	dfs(1,0),df5(1,1);
	for(int i=1;i<=q;i++){
		int x,y,z;cin>>x;
		if(x==1){
			cin>>y>>z;int l=lca(y,z);
			X.add(sg[y],1),X.add(sg[z],1),X.add(sg[l],-1);
			T.add(l);
			s.insert({dp[l],l});
			cntr++;
		}if(x==2){
			cin>>y>>z;int l=lca(y,z);
			X.add(sg[y],-1),X.add(sg[z],-1),X.add(sg[l],1);
			T.del(l);
			s.erase(s.lower_bound({dp[l],l}));
			cntr--;
		}if(x==3){
			cin>>y;
			ask(y);
			cout<<endl;
		}
	}
}