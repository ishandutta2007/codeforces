#include<bits/stdc++.h>
using namespace std;

struct SegTree{
    int sz;
    vector<pair<int,int>> dat,laz;

    SegTree(int _sz=1){
        sz=1;
        while(sz<_sz)sz<<=1;
        dat.resize(sz<<1);
        laz.resize(sz<<1);
    }

    void upd(int id,int l,int r,int ql,int qr,pair<int,int> val){
        if(qr<l||r<ql)return;
        if(ql<=l&&r<=qr){
            laz[id]=max(laz[id],val);
            dat[id]=max(dat[id],val);
            return;
        }
        laz[id<<1]=max(laz[id<<1],laz[id]);
        dat[id<<1]=max(dat[id<<1],laz[id]);
        laz[id<<1|1]=max(laz[id<<1|1],laz[id]);
        dat[id<<1|1]=max(dat[id<<1|1],laz[id]);
        laz[id]={0,0};
        upd(id<<1,l,l+r>>1,ql,qr,val);
        upd(id<<1|1,(l+r>>1)+1,r,ql,qr,val);
        dat[id]=max(dat[id<<1],dat[id<<1|1]);
    }

    void upd(int l,int r,int val,int id){
        upd(1,1,sz,l,r,{val,id});
    }

    pair<int,int> qry(int id,int l,int r,int ql,int qr){
        if(qr<l||r<ql)return {0,0};
        if(ql<=l&&r<=qr){
            return dat[id];
        }
        laz[id<<1]=max(laz[id<<1],laz[id]);
        dat[id<<1]=max(dat[id<<1],laz[id]);
        laz[id<<1|1]=max(laz[id<<1|1],laz[id]);
        dat[id<<1|1]=max(dat[id<<1|1],laz[id]);
        laz[id]={0,0};
        return max(qry(id<<1,l,l+r>>1,ql,qr),qry(id<<1|1,(l+r>>1)+1,r,ql,qr));
    }

    pair<int,int> qry(int l,int r){
        return qry(1,1,sz,l,r);
    }
};

int n,m,fa[300005];
vector<pair<int,int>> seg[300005];
vector<int> vx;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<m;i++){
        int id,a,b;
        cin>>id>>a>>b;
        seg[id].emplace_back(a,b);
        vx.emplace_back(a);
        vx.emplace_back(b);
    }
    sort(vx.begin(),vx.end());
    vx.erase(unique(vx.begin(),vx.end()),vx.end());
    for(int i=1;i<=n;i++)for(auto &[a,b]:seg[i]){
        a=upper_bound(vx.begin(),vx.end(),a)-vx.begin();
        b=upper_bound(vx.begin(),vx.end(),b)-vx.begin();
    }
    SegTree st(vx.size());
    for(int i=1;i<=n;i++){
        int mx=0,&cfa=fa[i];
        for(auto &[a,b]:seg[i]){
            int val,id;
            tie(val,id)=st.qry(a,b);
            if(val>mx){
                mx=val;
                cfa=id;
            }
        }
        for(auto &[a,b]:seg[i]){
            st.upd(a,b,mx+1,i);
        }
    }
    stack<int> t;
    int x=n+1;
    fa[n+1]=st.qry(1,vx.size()).second;
    while(x){
        for(int i=x-1;i>fa[x];i--)t.emplace(i);
        x=fa[x];
    }
    cout<<t.size()<<'\n';
    while(!t.empty()){
        cout<<t.top()<<' ';
        t.pop();
    }

    return 0;
}