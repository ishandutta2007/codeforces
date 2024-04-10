#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9+7;

struct BIT{
    int sz;
    vector<int> bit;

    BIT(int _sz=1){
        sz=_sz;
        bit.resize(sz+1);
    }

    int sum(int pos){
        ll res=0;
        while(pos>0){
            res+=bit[pos];
            pos-=pos&-pos;
        }
        return res%mod;
    }

    void add(int pos,int val){
        while(pos<=sz){
            bit[pos]=(bit[pos]+val)%mod;
            pos+=pos&-pos;
        }
    }

    void clear(){
        bit.assign(sz+1,0);
    }
}bit;

struct SegTree{
    int sz;
    vector<int> dat;

    SegTree(int _sz=1){
        sz=1;while(sz<_sz)sz<<=1;
        dat.resize(sz<<1);
    }

    void upd(int pos,int val){
        pos+=sz-1;
        dat[pos]=val;
        while(pos>1){
            pos>>=1;
            dat[pos]=max(dat[pos<<1],dat[pos<<1|1]);
        }
    }

    int qry(int id,int l,int r,int ql,int qr){
        if(qr<l||r<ql)return 0;
        if(ql<=l&&r<=qr)return dat[id];
        return max(qry(id<<1,l,l+r>>1,ql,qr),qry(id<<1|1,(l+r>>1)+1,r,ql,qr));
    }

    int qry(int l,int r){
        return qry(1,1,sz,l,r);
    }
}seg;

int n,q,nest[400005],nestmx[400005],lb[400005],id[400005],ans[400005];
bool ask[200005];
vector<pair<int,int>> nxt[400005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    bit=BIT(n*2);
    seg=SegTree(n*2);
    for(int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        lb[r]=l;
        id[r]=i;
    }
    cin>>q;
    for(int i=1;i<=q;i++){
        int x;
        cin>>x;
        ask[x]=true;
    }
    for(int i=1;i<=n*2;i++)if(lb[i]){
        nest[i]=(bit.sum(i)-bit.sum(lb[i])+mod+1)%mod;
        bit.add(lb[i],nest[i]);
        if(ask[id[i]]){
            nestmx[i]=seg.qry(lb[i],i);
            nxt[nestmx[i]].emplace_back(lb[i],i);
            seg.upd(lb[i],i);
        }
    }
    bit.clear();
    int rm=seg.qry(1,n*2);
    nxt[rm].emplace_back(0,n*2+1);
    id[n*2+1]=n+1;
    ask[n+1]=true;
    nestmx[n*2+1]=rm;
    for(int i=1;i<=n*2;i++)if(lb[i]){
        for(auto &[l,r]:nxt[i]){
            ans[r]=(bit.sum(i)-bit.sum(l)+mod)%mod;
        }
        bit.add(lb[i],nest[i]);
    }
    for(int i=1;i<=n*2+1;i++)if(ask[id[i]]){
        ans[i]=(ans[i]+ans[nestmx[i]]+1)%mod;
    }
    cout<<(ans[n*2+1]-1+mod)%mod;

    return 0;
}