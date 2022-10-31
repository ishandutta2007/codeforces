#include<bits/stdc++.h>
#define int long long
const int N=500500;
using namespace std;

int n,k;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
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


struct sgt{
    #define ls k<<1
    #define rs k<<1|1
    #define mid ((l+r)>>1)
    pair<int,int> mx[N<<2];int tg[N<<2];
    void pshtg(int k,int p){
    	tg[k]+=p,mx[k].first+=p;
    }
    void pshdn(int k){
    	pshtg(ls,tg[k]),pshtg(rs,tg[k]);
    	tg[k]=0;
    }
    void pshup(int k){
        mx[k]=max(mx[ls],mx[rs]);
    }
    void build(int k,int l,int r){
    	if(l^r)build(ls,l,mid),build(rs,mid+1,r),pshup(k);
    	else mx[k]={dp[bc[l]],bc[l]};
	}
    void chg(int k,int l,int r,int x,int y,int p){
        if(y<l||x>r)return ;
        if(y>=r&&x<=l)return pshtg(k,p);
        pshdn(k);
        chg(ls,l,mid,x,y,p),chg(rs,mid+1,r,x,y,p);
        pshup(k);
    }
}T;

int v[N];

int calc(int k){
	return k/2*(k-k/2);
}

main(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		add(x,y),add(y,x);
	} 
	dfs(1,0);
	df5(1,0);
	T.build(1,1,n);
	int ans=n,res=-calc(n);
	for(int i=1;i<=k;i++){
		auto nw=T.mx[1];
		ans-=nw.first;
		for(int j=nw.second;j!=0&&!v[j];j=fa[j])
			T.chg(1,1,n,sg[j],sg[j]+sz[j]-1,-1),v[j]=1;
		int rst=n-i;
		if(k*2<=n&&ans*2>=n)res=max(res,-calc(n-2*k));
		else res=max(res,(rst-ans)*(i-ans));
	}
	
	cout<<res<<endl;
}