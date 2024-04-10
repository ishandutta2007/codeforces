#include<bits/stdc++.h>
using namespace std;

int n;

struct bracket{
    int l,r;
    bracket(int v=n+1){
        if(v<=n){
            l=1;r=0;
        }else if(v==n+1){
            l=0;r=0;
        }else{
            l=0;r=1;
        }
    }
    bracket operator+(const bracket &b)const{
        bracket res;
        res.l=l;
        res.r=b.r;
        if(r>=b.l)res.r+=r-b.l;
        else res.l+=b.l-r;
        return res;
    }
    bool valid()const{
        return l==0&&r==0;
    }
};

struct len{
    int l,r;
    len(int v=n+1){
        if(v>=1&&v<=n){
            l=r=v;
        }else{
            l=r=-1;
        }
    }
    len operator+(const len &b)const{
        if(l==-1)return b;
        if(b.l==-1)return *this;
        len res;
        if(r+1!=b.l)return res;
        res.l=l;
        res.r=b.r;
        return res;
    }
    bool valid()const{
        return l==1&&r==n;
    }
};

struct gn{
    int l,r;
    gn(int v=n+1){
        if(v>n+1&&v<=2*n+1){
            l=r=v;
        }else{
            l=r=-1;
        }
    }
    gn operator+(const gn &b)const{
        if(l==-1)return b;
        if(b.l==-1)return *this;
        gn res;
        if(r+1!=b.l)return res;
        res.l=l;
        res.r=b.r;
        return res;
    }
    bool valid()const{
        return l==n+2&&r==2*n+1;
    }
};

struct node{
    bracket b;
    len le;
    gn g;
    node(int v=n+1){
        b=bracket(v);
        le=len(v);
        g=gn(v);
    }
    node operator+(const node &a)const{
        node res;
        res.b=b+a.b;
        res.le=le+a.le;
        res.g=g+a.g;
        return res;
    }
};

int sz,p[400005];
node dat[1<<20];

void upd(int id,int val){
    id+=sz-1;
    dat[id]=val;
    while(id>1){
        id>>=1;
        dat[id]=dat[id<<1]+dat[id<<1|1];
    }
}

node qry(int id,int l,int r,int ql,int qr){
    if(qr<l||r<ql)return node();
    if(ql<=l&&r<=qr)return dat[id];
    return qry(id<<1,l,l+r>>1,ql,qr)+qry(id<<1|1,(l+r>>1)+1,r,ql,qr);
}

node qry(int l,int r){
    return qry(1,1,sz,l,r);
}

struct segtree{
    int sz;
    vector<int> laz;
    vector<pair<int,int>> dat;

    segtree(int _sz=1<<19){
        sz=1;
        while(sz<_sz)sz<<=1;
        dat.resize(sz<<1);
        laz.resize(sz<<1);
        for(int i=1;i<=sz;i++)dat[i+sz-1].second=i;
    }

    void upd(int id,int l,int r,int ql,int qr,int val){
        if(qr<l||r<ql)return;
        if(ql<=l&&r<=qr){
            laz[id]+=val;
            dat[id].first+=val;
            return;
        }
        laz[id<<1]+=laz[id];
        dat[id<<1].first+=laz[id];
        laz[id<<1|1]+=laz[id];
        dat[id<<1|1].first+=laz[id];
        laz[id]=0;
        upd(id<<1,l,l+r>>1,ql,qr,val);
        upd(id<<1|1,(l+r>>1)+1,r,ql,qr,val);
        dat[id]=min(dat[id<<1],dat[id<<1|1]);
    }

    void upd(int l,int r,int val){
        upd(1,1,sz,l,r,val);
    }

    pair<int,int> qry(int id,int l,int r,int ql,int qr){
        if(qr<l||r<ql)return {1e9,0};
        if(ql<=l&&r<=qr){
            return dat[id];
        }
        laz[id<<1]+=laz[id];
        dat[id<<1].first+=laz[id];
        laz[id<<1|1]+=laz[id];
        dat[id<<1|1].first+=laz[id];
        laz[id]=0;
        return min(qry(id<<1,l,l+r>>1,ql,qr),qry(id<<1|1,(l+r>>1)+1,r,ql,qr));
    }

    pair<int,int> qry(int l,int r){
        return qry(1,1,sz,l,r);
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q,crit;
    cin>>n>>q;
    for(int i=1;i<=2*n+1;i++){
        cin>>p[i];
        p[i+2*n+1]=p[i];
        if(p[i]==n+1)crit=i;
    }
    sz=1;
    while(sz<2*(2*n+1))sz<<=1;
    for(int i=1;i<=2*(2*n+1);i++)dat[i+sz-1]=p[i];
    for(int i=sz-1;i>=1;i--)dat[i]=dat[i<<1]+dat[i<<1|1];
    segtree s(2*n+1);
    for(int i=1,ps=0;i<=2*n+1;i++){
        ps+=(p[i]>n+1)-(p[i]<=n);
        s.dat[i+s.sz-1].first=ps;
    }
    for(int i=s.sz-1;i>=1;i--)s.dat[i]=min(s.dat[i<<1],s.dat[i<<1|1]);
    while(q--){
        int u,v;
        cin>>u>>v;
        if(u>v)swap(u,v);
        if(p[u]==n+1)crit=v;
        if(p[v]==n+1)crit=u;
        s.upd(u,v-1,(p[u]<=n)-(p[u]>n+1)+(p[v]>n+1)-(p[v]<=n));
        swap(p[u],p[v]);
        swap(p[u+2*n+1],p[v+2*n+1]);
        upd(u,p[u]);
        upd(v,p[v]);
        upd(u+2*n+1,p[u+2*n+1]);
        upd(v+2*n+1,p[v+2*n+1]);
        node res=qry(crit+1,crit+n*2);
        if(!res.b.valid()){
            cout<<s.qry(1,2*n+1).second%(2*n+1)<<'\n';
        }else if(!res.le.valid()){
            cout<<crit%(2*n+1)<<'\n';
        }else if(!res.g.valid()){
            cout<<crit-1<<'\n';
        }else cout<<"-1\n";
    }

    return 0;
}