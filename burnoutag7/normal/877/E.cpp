#include<bits/stdc++.h>
using namespace std;

int n,topo,q,sz;
int a[200005];
int dat[800005];
int laz[800005];

void build(int bk,int l,int r){
    if(l==r){
        if(l<=n){
            dat[bk]=a[l];
        }
        return;
    }
    build(bk<<1,l,(l+r)>>1);
    build(bk<<1|1,((l+r)>>1)+1,r);
    dat[bk]=dat[bk<<1]+dat[bk<<1|1];
}

void upd(int bk,int l,int r,int ql,int qr){
    if(qr<l||r<ql)return;
    if(ql<=l&&r<=qr){
        laz[bk]^=1;
        dat[bk]=r-l+1-dat[bk];
        return;
    }
    if(laz[bk]){
        laz[bk<<1]^=1;
        dat[bk<<1]=((r-l+1)>>1)-dat[bk<<1];
        laz[bk<<1|1]^=1;
        dat[bk<<1|1]=((r-l+1)>>1)-dat[bk<<1|1];
        laz[bk]=0;
    }
    upd(bk<<1,l,(l+r)>>1,ql,qr);
    upd(bk<<1|1,((l+r)>>1)+1,r,ql,qr);
    dat[bk]=dat[bk<<1]+dat[bk<<1|1];
}

int qry(int bk,int l,int r,int ql,int qr){
    if(qr<l||r<ql)return 0;
    if(ql<=l&&r<=qr){
        return dat[bk];
    }
    if(laz[bk]){
        laz[bk<<1]^=1;
        dat[bk<<1]=((r-l+1)>>1)-dat[bk<<1];
        laz[bk<<1|1]^=1;
        dat[bk<<1|1]=((r-l+1)>>1)-dat[bk<<1|1];
        laz[bk]=0;
    }
    return qry(bk<<1,l,(l+r)>>1,ql,qr)+qry(bk<<1|1,((l+r)>>1)+1,r,ql,qr);
}

vector<int> g[200005];
int vl[200005];
int vr[200005];

void dfs(int x){
    vl[x]=++topo;
    for(int &y:g[x])dfs(y);
    vr[x]=topo;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=2;i<=n;i++){
        int t;
        cin>>t;
        g[t].push_back(i);
    }
    dfs(1);
    sz=1;while(sz<n)sz<<=1;
    for(int i=1;i<=n;i++){
        cin>>a[vl[i]];
    }
    build(1,1,sz);
    cin>>q;
    while(q--){
        string com;
        int v;
        cin>>com>>v;
        if(com.front()=='g')cout<<qry(1,1,sz,vl[v],vr[v])<<endl;
        else upd(1,1,sz,vl[v],vr[v]);
    }

    return 0;
}