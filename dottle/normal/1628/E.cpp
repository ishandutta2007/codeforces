#include<bits/stdc++.h>
const int N=600005,P=21;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx;
}e[N];int hd[N],S;
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S;
}

vector<vector<int>>a;
int n,m,q,cnt;
int fa[N],w[N];
int sg[N],bc[N],c; 
int f[P][N],dp[N];
int gf(int k){return k==fa[k]?k:fa[k]=gf(fa[k]);}

void dfs(int k,int fa){
	f[0][k]=fa;
	dp[k]=dp[fa]+1;
	for(int i=1;i<P;i++)f[i][k]=f[i-1][f[i-1][k]];
	if(k<=n){
		++c;
		sg[k]=c;
		bc[c]=k;
	}else fore(k)dfs(_to,k);
}

int lca(int x,int y){
	if(dp[x]<dp[y])swap(x,y);
	for(int i=P-1;~i;i--)
		if(dp[f[i][x]]>=dp[y])
			x=f[i][x];
	if(x==y)return x;
	for(int i=P-1;~i;i--)
		if(f[i][x]!=f[i][y])
			x=f[i][x],y=f[i][y];
	return f[0][x];
}

struct sgt{
    #define ls k<<1
    #define rs k<<1|1
    #define mid ((l+r)>>1)
    int wx[N<<2],wi[N<<2],mx[N<<2],mn[N<<2],tg[N<<2];
    void pshtg(int k,int p){
    	if(p==0)mx[k]=0,mn[k]=N;
    	else mx[k]=wx[k],mn[k]=wi[k];
    	tg[k]=p;
    }
    void pshdn(int k){
    	if(~tg[k])pshtg(ls,tg[k]),pshtg(rs,tg[k]);
		tg[k]=-1;
    }
    void pshup(int k){
        mx[k]=max(mx[ls],mx[rs]);
        mn[k]=min(mn[ls],mn[rs]);
    }
    void build(int k,int l,int r){
    	mx[k]=0,mn[k]=N;
    	if(l^r)build(ls,l,mid),build(rs,mid+1,r),wx[k]=max(wx[ls],wx[rs]),wi[k]=min(wi[ls],wi[rs]);
    	else wx[k]=wi[k]=sg[l];
	}
    void pshtg(int k,int l,int r,int x,int y,int p){
        if(y<l||x>r)return ;
        if(y>=r&&x<=l)return pshtg(k,p);
        pshdn(k);
        pshtg(ls,l,mid,x,y,p),pshtg(rs,mid+1,r,x,y,p);
        pshup(k);
    }
}T;

void solve(){
	cin>>n>>q;
	for(int i=1;i<=2*n;i++)fa[i]=i;
	for(int i=1;i<=n;i++)cnt++,w[i]=-1;
	for(int i=1;i<n;i++){
		vector<int>b(3);
		cin>>b[1]>>b[2]>>b[0];
		a.push_back(b);
	}
	sort(a.begin(),a.end());
	for(auto x:a){
		int fx=gf(x[1]),fy=gf(x[2]);
		if(fx!=fy){
			++cnt;
			w[cnt]=x[0];
			fa[fx]=fa[fy]=cnt;
			add(cnt,fx),add(cnt,fy);
		}
	}
	dfs(cnt,0);
	T.build(1,1,n);
	for(int i=1;i<=q;i++){
		int x;cin>>x;
		if(x<=2){
			int a,b;cin>>a>>b;
			T.pshtg(1,1,n,a,b,2-x);
		}else{
			int a;cin>>a;
			int fx=T.mx[1],fy=T.mn[1];
			if(fx==0)fx=sg[a];
			if(fy==N)fy=sg[a];
			int l=lca(lca(bc[fx],bc[fy]),a);
			cout<<w[l]<<'\n';
		}
	}
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;//cin>>_T;
	while(_T--)solve();
}