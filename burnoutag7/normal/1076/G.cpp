#include<bits/stdc++.h>
using namespace std;

int m;

struct node{
    int len,tag,cnt[2][6];
    node(){
        len=tag=0;
        memset(cnt,0,sizeof(cnt));
    }
    node(int x){
        len=1;
        tag=0;
        memset(cnt,0,sizeof(cnt));
        cnt[x][0]=1;
    }
    void flip(){
        tag^=1;
        swap(cnt[0],cnt[1]);
    }
    void pushdown(node &l,node &r){
        if(tag){
            l.flip();
            r.flip();
            tag=0;
        }
    }
    void merge(const node &l,const node &r){
        len=l.len+r.len;
        tag=0;
        for(int v=0;v<2;v++)
            for(int i=0;i<m;i++){
                cnt[v][i]=r.cnt[v][i]+l.cnt[v][(m-(r.len-i-r.cnt[v][i])%m)%m];
            }
    }
    bool win(){
        return (len-cnt[0][0])%m!=1;
    }
};

typedef long long ll;

struct SegTree{
    int sz;
    vector<node> dat;

    void build(ll *a,int n,int id,int l,int r){
        if(l==r){
            if(l<=n){
                dat[id]=node(a[l]&1);
            }
            return;
        }
        build(a,n,id<<1,l,l+r>>1);
        build(a,n,id<<1|1,(l+r>>1)+1,r);
        dat[id].merge(dat[id<<1],dat[id<<1|1]);
    }

    SegTree(int _sz,ll *a){
        sz=1;
        while(sz<_sz)sz<<=1;
        dat.resize(sz<<1);
        build(a,_sz,1,1,sz);
    }

    void upd(int id,int l,int r,int ql,int qr){
        if(qr<l||r<ql)return;
        if(ql<=l&&r<=qr){
            dat[id].flip();
            return;
        }
        dat[id].pushdown(dat[id<<1],dat[id<<1|1]);
        upd(id<<1,l,l+r>>1,ql,qr);
        upd(id<<1|1,(l+r>>1)+1,r,ql,qr);
        dat[id].merge(dat[id<<1],dat[id<<1|1]);
    }

    void upd(int l,int r){
        upd(1,1,sz,l,r);
    }

    node qry(int id,int l,int r,int ql,int qr){
        if(qr<l||r<ql)return node();
        if(ql<=l&&r<=qr){
            return dat[id];
        }
        dat[id].pushdown(dat[id<<1],dat[id<<1|1]);
        node res;
        res.merge(qry(id<<1,l,l+r>>1,ql,qr),qry(id<<1|1,(l+r>>1)+1,r,ql,qr));
        return res;
    }

    bool qry(int l,int r){
        return qry(1,1,sz,l,r).win();
    }
};

int n,q;
ll a[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>q;
    m++;
    for(int i=1;i<=n;i++)cin>>a[i];
    SegTree st(n,a);
    while(q--){
        int t,l,r;
        ll x;
        cin>>t>>l>>r;
        if(t==1){
            cin>>x;
            if(x&1)st.upd(l,r);
        }else{
            cout<<(st.qry(l,r)?"1\n":"2\n");
        }
    }

    return 0;
}