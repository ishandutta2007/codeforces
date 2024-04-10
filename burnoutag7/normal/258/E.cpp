#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> g[100005];
int dfn[100005],dfc,fin[100005];
vector<pair<int,int>> qs[100005];

void dfs(const int &x,const int &p){
    dfn[x]=++dfc;
    for(int &y:g[x])if(y!=p){
        dfs(y,x);
    }
    fin[x]=dfc;
}

int ans[100005];

struct SegTree{
    struct node{
        int min,cnt,laz;
        node(){
            min=laz=0;
            cnt=1;
        }
        node(const int &_min,const int &_cnt){
            min=_min;
            cnt=_cnt;
            laz=0;
        }
        void pushdown(node &l,node &r){
            l.min+=laz;
            l.laz+=laz;
            r.min+=laz;
            r.laz+=laz;
            laz=0;
        }
        void pullup(const node &l,const node &r){
            if(l.min==r.min){
                min=l.min;
                cnt=l.cnt+r.cnt;
            }else if(l.min<r.min){
                min=l.min;
                cnt=l.cnt;
            }else{
                min=r.min;
                cnt=r.cnt;
            }
        }
    };
    int sz;
    vector<node> dat;
    void build(const int &id,const int &l,const int &r){
        dat[id].cnt=r-l+1;
        if(l==r)return;
        build(id<<1,l,l+r>>1);
        build(id<<1|1,(l+r>>1)+1,r);
    }
    SegTree(){
        sz=1<<17;
        dat.resize(sz<<1);
        build(1,1,sz);
    }
    void upd(const int &id,const int &l,const int &r,const int &ql,const int &qr,const int &val){
        if(qr<l||r<ql)return;
        if(ql<=l&&r<=qr){
            dat[id].laz+=val;
            dat[id].min+=val;
            return;
        }
        dat[id].pushdown(dat[id<<1],dat[id<<1|1]);
        upd(id<<1,l,l+r>>1,ql,qr,val);
        upd(id<<1|1,(l+r>>1)+1,r,ql,qr,val);
        dat[id].pullup(dat[id<<1],dat[id<<1|1]);
    }
    node qry(const int &id,const int &l,const int &r,const int &ql,const int &qr){
        if(qr<l||r<ql)return node(0,0);
        if(ql<=l&&r<=qr){
            return dat[id];
        }
        dat[id].pushdown(dat[id<<1],dat[id<<1|1]);
        node res;
        res.pullup(qry(id<<1,l,l+r>>1,ql,qr),qry(id<<1|1,(l+r>>1)+1,r,ql,qr));
        return res;
    }
    int positive(){
        node res=qry(1,1,sz,1,n);
        return res.min==0?n-res.cnt:n;
    }
}tree;

void get(const int &x,const int &p){
    for(pair<int,int> &p:qs[x]){
        tree.upd(1,1,tree.sz,p.first,p.second,1);
    }
    tree.upd(1,1,tree.sz,dfn[x],dfn[x],1);
    ans[x]=tree.positive()-1;
    tree.upd(1,1,tree.sz,dfn[x],dfn[x],-1);
    for(int &y:g[x])if(y!=p){
        get(y,x);
    }
    for(pair<int,int> &p:qs[x]){
        tree.upd(1,1,tree.sz,p.first,p.second,-1);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<n;i++){
        static int u,v;
        cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1,-1);
    while(m--){
        static int u,v;
        cin>>u>>v;
        qs[u].emplace_back(dfn[u],fin[u]);
        qs[v].emplace_back(dfn[u],fin[u]);
        qs[u].emplace_back(dfn[v],fin[v]);
        qs[v].emplace_back(dfn[v],fin[v]);
    }
    get(1,-1);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;

    return 0;
}