#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,sz;
ll a[400005];
ll dat[1600005];
bool lazy[1600005];

void build(int bk,int l,int r){
    if(l==r){
        if(l<=n){
            dat[bk]=a[l];
        }
        return;
    }
    build(bk<<1,l,(l+r)>>1);
    build(bk<<1|1,((l+r)>>1)+1,r);
    dat[bk]=dat[bk<<1]|dat[bk<<1|1];
}

void upd(int bk,int l,int r,int ql,int qr,ll val){
    if(qr<l||r<ql)return;
    if(ql<=l&&r<=qr){
        lazy[bk]=1;
        dat[bk]=val;
        return;
    }
    if(lazy[bk]){
        lazy[bk<<1]=1;
        dat[bk<<1]=dat[bk];
        lazy[bk<<1|1]=1;
        dat[bk<<1|1]=dat[bk];
        lazy[bk]=0;
    }
    upd(bk<<1,l,(l+r)>>1,ql,qr,val);
    upd(bk<<1|1,((l+r)>>1)+1,r,ql,qr,val);
    dat[bk]=dat[bk<<1]|dat[bk<<1|1];
}

ll qry(int bk,int l,int r,int ql,int qr){
    if(qr<l||r<ql)return 0;
    if(ql<=l&&r<=qr){
        return dat[bk];
    }
    if(lazy[bk]){
        lazy[bk<<1]=1;
        dat[bk<<1]=dat[bk];
        lazy[bk<<1|1]=1;
        dat[bk<<1|1]=dat[bk];
        lazy[bk]=0;
    }
    return qry(bk<<1,l,(l+r)>>1,ql,qr)|qry(bk<<1|1,((l+r)>>1)+1,r,ql,qr);
}

int m;
vector<int> g[400005];
int topo_cnt;
int cl[400005],cr[400005],col[400005];

void topo(int x,int p){
    cl[x]=++topo_cnt;
    a[topo_cnt]=1ll<<(col[x]-1);
    for(int i=0;i<g[x].size();i++){
        int &y=g[x][i];
        if(y!=p)topo(y,x);
    }
    cr[x]=topo_cnt;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>col[i];
    }
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    topo(1,-1);
    sz=1;
    while(sz<n)sz<<=1;
    build(1,1,sz);
    while(m--){
        int typ,v,c;
        cin>>typ;
        if(typ==1){
            cin>>v>>c;
            upd(1,1,sz,cl[v],cr[v],1ll<<(c-1));
        }else{
            cin>>v;
            cout<<__builtin_popcount(qry(1,1,sz,cl[v],cr[v])>>32)+__builtin_popcount(qry(1,1,sz,cl[v],cr[v])&(-1))<<'\n';
        }
    }

    return 0;
}