#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> g[500005];
int hson[500005],fa[500005],dep[500005],sz[500005],top[500005],bottom[500005],dfn[500005],dfncnt,fin[500005],rnk[500005];

int hldprec(int x,int p,int d){
    dep[x]=d;
    sz[x]=1;
    for(int &y:g[x])if(y!=p){
        sz[x]+=hldprec(y,x,d+1);
        fa[y]=x;
        if(sz[y]>sz[hson[x]]){
            hson[x]=y;
        }
    }
    return sz[x];
}

void hlddec(int x,int head){
    top[x]=head;
    bottom[head]=x;
    dfn[x]=++dfncnt;
    rnk[dfncnt]=x;
    if(hson[x]){
        hlddec(hson[x],head);
        for(int &y:g[x])if(y!=fa[x]&&y!=hson[x]){
            hlddec(y,y);
        }
    }
    bottom[x]=bottom[head];
    fin[x]=dfncnt;
}

int lca(int u,int v){
    while(top[u]!=top[v]){
        if(dep[top[u]]>dep[top[v]]){
            u=fa[top[u]];
        }else{
            v=fa[top[v]];
        }
    }
    return dep[u]<dep[v]?u:v;
}

int dat[2000005];
int laz[2000005];

void upd(int bk,int l,int r,int ql,int qr,int val){
    if(qr<l||r<ql)return;
    if(ql<=l&&r<=qr){
        laz[bk]=val;
        dat[bk]=val*(r-l+1);
        return;
    }
    if(laz[bk]!=-1){
        laz[bk<<1]=laz[bk];
        dat[bk<<1]=laz[bk]*((r-l+1)>>1);
        laz[bk<<1|1]=laz[bk];
        dat[bk<<1|1]=laz[bk]*((r-l+1)>>1);
        laz[bk]=-1;
    }
    upd(bk<<1,l,l+r>>1,ql,qr,val);
    upd(bk<<1|1,(l+r>>1)+1,r,ql,qr,val);
    dat[bk]=dat[bk<<1]+dat[bk<<1|1];
}

int qry(int bk,int l,int r,int ql,int qr){
    if(qr<l||r<ql)return 0;
    if(ql<=l&&r<=qr){
        return dat[bk];
    }
    if(laz[bk]!=-1){
        laz[bk<<1]=laz[bk];
        dat[bk<<1]=laz[bk]*((r-l+1)>>1);
        laz[bk<<1|1]=laz[bk];
        dat[bk<<1|1]=laz[bk]*((r-l+1)>>1);
        laz[bk]=-1;
    }
    return qry(bk<<1,l,l+r>>1,ql,qr)+qry(bk<<1|1,(l+r>>1)+1,r,ql,qr);
}

int q,tsz;

void add(int x){
    upd(1,1,tsz,dfn[x],fin[x],1);
}

void sub(int x){
    while(x){
        upd(1,1,tsz,dfn[top[x]],dfn[x],0);
        x=fa[top[x]];
    }
}

int get(int x){
    return qry(1,1,tsz,dfn[x],dfn[x]);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(laz,-1,sizeof(laz));
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    hldprec(1,-1,0);
    hlddec(1,1);
    tsz=1;
    while(tsz<n)tsz<<=1;
    cin>>q;
    while(q--){
        int typ,x;
        cin>>typ>>x;
        if(typ==1){
            add(x);
        }else if(typ==2){
            sub(x);
        }else{
            cout<<get(x)<<'\n';
        }
    }

    return 0;
}