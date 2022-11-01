#include<bits/stdc++.h>
using namespace std;

struct SegTree{
    int sz;
    vector<int> dat,laz;

    SegTree(int _sz=1<<17){
        sz=1;
        while(sz<_sz)sz<<=1;
        dat.resize(sz<<1);
        laz.resize(sz<<1);
    }

    void upd(int id,int l,int r,int ql,int qr,int val){
        if(qr<l||r<ql)return;
        if(ql<=l&&r<=qr){
            laz[id]+=val;
            dat[id]+=val;
            return;
        }
        laz[id<<1]+=laz[id];
        dat[id<<1]+=laz[id];
        laz[id<<1|1]+=laz[id];
        dat[id<<1|1]+=laz[id];
        laz[id]=0;
        upd(id<<1,l,l+r>>1,ql,qr,val);
        upd(id<<1|1,(l+r>>1)+1,r,ql,qr,val);
        dat[id]=max(dat[id<<1],dat[id<<1|1]);
    }

    void upd(int l,int r,int val){
        upd(1,1,sz,l,r,val);
    }

    int qry(int id,int l,int r,int ql,int qr){
        if(qr<l||r<ql)return 0;
        if(ql<=l&&r<=qr){
            return dat[id];
        }
        laz[id<<1]+=laz[id];
        dat[id<<1]+=laz[id];
        laz[id<<1|1]+=laz[id];
        dat[id<<1|1]+=laz[id];
        laz[id]=0;
        return max(qry(id<<1,l,l+r>>1,ql,qr),qry(id<<1|1,(l+r>>1)+1,r,ql,qr));
    }

    int qry(int l,int r){
        return qry(1,1,sz,l,r);
    }
};

int n,k,a[35005],prv[35005],pc[35005],sav[35005],pos[35005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        prv[i]=pos[a[i]];
        pos[a[i]]=i;
        pc[i]=pc[i-1]+i-prv[i];
        sav[i]=sav[i-1]+(prv[i]?0:i);
    }
    for(int j=2;j<=k;j++){
        SegTree st(n);
        for(int i=1;i<=n;i++){
            st.upd(i,i,sav[i]);
            st.upd(prv[i],i-1,i-prv[i]);
            sav[i]=st.qry(1,i-1);
        }
    }
    cout<<pc[n]-sav[n];

    return 0;
}