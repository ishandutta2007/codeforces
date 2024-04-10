#include<bits/stdc++.h>
using namespace std;

struct unionfind{
    int n;
    vector<int> fa;

    unionfind(int _n=0){
        fa.resize((n=_n)+1);
        iota(fa.begin(),fa.end(),0);
    }

    int find(int x){
        return fa[x]==x?x:fa[x]=find(fa[x]);
    }

    void unite(int x,int y){
        x=find(x);
        y=find(y);
        fa[x]=y;
    }
};

typedef long long ll;
const ll ninf=-1e18;

struct segment{
    ll lv,rv,ans;
    segment(){
        lv=rv=ans=ninf;
    }
    segment(ll h,ll p){
        lv=h-p;
        rv=h+p;
        ans=ninf;
    }
    segment operator+(const segment& rhs)const{
        segment res;
        res.lv=max(lv,rhs.lv);
        res.rv=max(rv,rhs.rv);
        res.ans=max(lv+rhs.rv,max(ans,rhs.ans));
        return res;
    }
};

struct segtree{
    int sz;
    vector<segment> dat;

    segtree(int n){
        sz=1;while(sz<n)sz<<=1;
        dat.resize(sz<<1);
    }

    segtree(int n,ll *a,ll *b){
        sz=1;while(sz<n)sz<<=1;
        dat.resize(sz<<1);
        for(int i=1;i<=n;i++)dat[i+sz-1]=segment(a[i],b[i]);
        for(int i=sz-1;i>=1;i--)dat[i]=dat[i<<1]+dat[i<<1|1];
    }

    segment qry(int id,int l,int r,int ql,int qr){
        if(qr<l||r<ql)return segment();
        if(ql<=l&&r<=qr)return dat[id];
        return qry(id<<1,l,l+r>>1,ql,qr)+qry(id<<1|1,(l+r>>1)+1,r,ql,qr);
    }

    ll qry(int l,int r){
        return qry(1,1,sz,l,r).ans;
    }
};

int n,m;
ll h[400005],p[400005];

void solve(ll dia){
    ll ans=1e18;
    segtree s(2*m,h,p);
    for(int i=1;i<=m;i++)ans=min(ans,s.qry(i,i+m-1));
    ans=max(ans,dia);
    cout<<ans<<'\n';
}

int st,ed,se;
vector<pair<int,int>> g[200005];
vector<int> cyc;

bool getc(int x,int p){
    if(x==ed){
        cyc.emplace_back(x);
        return true;
    }
    bool res=false;
    for(auto &e:g[x])if(e.first!=p){
        res|=getc(e.first,x);
    }
    if(res){
        cyc.emplace_back(x);
    }
    return res;
}

ll realh[200005],reald[200005];
int elen[200005];
bool ban[200005];

pair<ll,int> getfar(int x,int p){
    pair<ll,int> res{0,x};
    for(auto &e:g[x])if(e.first!=p&&!ban[e.first]){
        auto cur=getfar(e.first,x);
        cur.first+=e.second;
        res=max(res,cur);
    }
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    unionfind uf(n);
    for(int i=1;i<=n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        if(uf.find(u)!=uf.find(v)){
            g[u].emplace_back(v,w);
            g[v].emplace_back(u,w);
            uf.unite(u,v);
        }else{
            st=u;ed=v;se=w;
        }
    }
    getc(st,-1);
    g[st].emplace_back(ed,se);
    g[ed].emplace_back(st,se);
    m=cyc.size();
    for(int x:cyc)ban[x]=true;
    int prv=cyc.back();
    ll d=0;
    for(int x:cyc){
        ban[x]=false;
        auto dep=getfar(x,-1);
        realh[x]=dep.first;
        auto dia=getfar(dep.second,-1);
        d=max(d,dia.first);
        for(auto &e:g[x])if(e.first==prv)elen[x]=e.second;
        prv=x;
        ban[x]=true;
    }
    int cnt=0;
    for(int x:cyc){
        ++cnt;
        h[cnt]=h[cnt+m]=realh[x];
        p[cnt]=p[cnt+m]=elen[x];
    }
    for(int i=1;i<=2*m;i++)p[i]+=p[i-1];
    solve(d);

    return 0;
}