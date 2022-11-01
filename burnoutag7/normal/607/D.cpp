#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9+7;

ll qpow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

struct SegTree{
    int sz,p;
    vector<int> dat,add,mul;
    SegTree(int _sz,int _p){
        sz=1;
        p=_p;
        while(sz<_sz)sz<<=1;
        dat.resize(sz<<1);
        add.resize(sz<<1);
        mul.resize(sz<<1,1);
    }
    void pushdown(int id,int len){
        dat[id<<1]=((ll)mul[id]*dat[id<<1]+(ll)add[id]*(len>>1))%p;
        dat[id<<1|1]=((ll)mul[id]*dat[id<<1|1]+(ll)add[id]*(len>>1))%p;
        mul[id<<1]=((ll)mul[id<<1]*mul[id])%p;
        mul[id<<1|1]=((ll)mul[id<<1|1]*mul[id])%p;
        add[id<<1]=((ll)add[id<<1]*mul[id]+add[id])%p;
        add[id<<1|1]=((ll)add[id<<1|1]*mul[id]+add[id])%p;
        mul[id]=1;
        add[id]=0;
    }
    void pullup(int id){
        dat[id]=(dat[id<<1]+dat[id<<1|1])%p;
    }
    void upda(int id,int l,int r,int ql,int qr,int v){
        if(qr<l||r<ql)return;
        if(ql<=l&&r<=qr){
            add[id]=(add[id]+v)%p;
            dat[id]=(dat[id]+(ll)v*(r-l+1))%p;
            return;
        }
        pushdown(id,r-l+1);
        upda(id<<1,l,l+r>>1,ql,qr,v);
        upda(id<<1|1,(l+r>>1)+1,r,ql,qr,v);
        pullup(id);
    }
    void upda(int l,int r,int v){
        upda(1,1,sz,l,r,v);
    }
    void updm(int id,int l,int r,int ql,int qr,int v){
        if(qr<l||r<ql)return;
        if(ql<=l&&r<=qr){
            mul[id]=((ll)mul[id]*v)%p;
            add[id]=((ll)add[id]*v)%p;
            dat[id]=((ll)dat[id]*v)%p;
            return;
        }
        pushdown(id,r-l+1);
        updm(id<<1,l,l+r>>1,ql,qr,v);
        updm(id<<1|1,(l+r>>1)+1,r,ql,qr,v);
        pullup(id);
    }
    void updm(int l,int r,int v){
        updm(1,1,sz,l,r,v);
    }
    int qry(int id,int l,int r,int ql,int qr){
        if(qr<l||r<ql)return 0;
        if(ql<=l&&r<=qr)return dat[id];
        pushdown(id,r-l+1);
        return (qry(id<<1,l,l+r>>1,ql,qr)+qry(id<<1|1,(l+r>>1)+1,r,ql,qr))%p;
    }
    int qry(int l,int r){
        return qry(1,1,sz,l,r);
    }
};

int n,q,v[200005],d[200005],qs[200005];
vector<int> g[200005];
int dfn[200005],fin[200005],dfc,fa[200005];
SegTree st(200000,mod),stm(200000,mod);

void topo(int x){
    dfn[x]=++dfc;
    for(int& y:g[x])topo(y);
    fin[x]=dfc;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>v[1]>>q;
    n=1;
    for(int i=1;i<=q;i++){
        int typ;
        cin>>typ;
        if(typ==1){
            ++n;
            cin>>fa[n]>>v[n];
            g[fa[n]].emplace_back(n);
        }else cin>>qs[i];
    }
    topo(1);
    st.upda(1,1,v[1]);
    stm.upda(1,n,1);
    n=1;
    for(int i=1;i<=q;i++){
        if(qs[i]){
            cout<<st.qry(dfn[qs[i]],fin[qs[i]])*(qs[i]==1?1:qpow(stm.qry(dfn[fa[qs[i]]],dfn[fa[qs[i]]]),mod-2))%mod<<'\n';
        }else{
            ++n;
            d[fa[n]]++;
            st.updm(dfn[fa[n]],fin[fa[n]],qpow(d[fa[n]],mod-2)*(d[fa[n]]+1)%mod);
            stm.updm(dfn[fa[n]],fin[fa[n]],qpow(d[fa[n]],mod-2)*(d[fa[n]]+1)%mod);
            st.upda(dfn[n],dfn[n],(ll)v[n]*stm.qry(dfn[n],dfn[n])%mod);
        }
    }

    return 0;
}