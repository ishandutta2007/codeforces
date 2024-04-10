#include<bits/stdc++.h>
using namespace std;

struct node{
    int mn,add;
    node(){
        mn=add=0;
    }
    void set(int x){
        mn=x;add=0;
    }
    void upd(int x){
        mn+=x;add+=x;
    }
    void pushdown(node &l,node &r){
        l.upd(add);
        r.upd(add);
        add=0;
    }
    void pullup(const node &l,const node &r){
        mn=min(l.mn,r.mn);
    }
};

struct segtree{
    int sz;
    vector<node> dat;

    segtree(int _sz=1<<17){
        sz=1;
        while(sz<_sz)sz<<=1;
        dat.resize(sz<<1);
    }

    void build(int *a,int n){
        for(int i=1;i<=n;i++)dat[i+sz-1].set(a[i]);
        for(int i=sz-1;i>=1;i--)dat[i].pullup(dat[i<<1],dat[i<<1|1]);
    }

    void upd(int id,int l,int r,int ql,int qr,int val){
        if(qr<l||r<ql)return;
        if(ql<=l&&r<=qr){
            dat[id].upd(val);
            return;
        }
        dat[id].pushdown(dat[id<<1],dat[id<<1|1]);
        upd(id<<1,l,l+r>>1,ql,qr,val);
        upd(id<<1|1,(l+r>>1)+1,r,ql,qr,val);
        dat[id].pullup(dat[id<<1],dat[id<<1|1]);
    }

    void upd(int l,int r,int val){
        upd(1,1,sz,l,r,val);
    }
};

const int V=1e5;
typedef long long ll;

int n,m,a[100005],len[100005];
vector<int> g[100005];
ll sum[100005];

void mian(){
    for(int i=1;i<=m;i++)g[i].clear();
    memset(a+1,0,V*4);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int v;
        cin>>v;
        a[v]++;
    }
    for(int i=V-1;i>=1;i--)a[i]+=a[i+1];
    segtree st(V);
    st.build(a,V);
    for(int i=1;i<=m;i++){
        int k;
        cin>>k;
        sum[i]=0;
        while(k--){
            int b;
            cin>>b;
            g[i].emplace_back(b);
            sum[i]+=b;
        }
        len[i]=g[i].size();
        st.upd(1,(sum[i]+len[i]-1)/len[i],-1);
    }
    for(int i=1;i<=m;i++){
        st.upd(1,(sum[i]+len[i]-1)/len[i],1);
        for(int x:g[i]){
            st.upd(1,(sum[i]-x+len[i]-2)/(len[i]-1),-1);
            cout<<(st.dat[1].mn>=0);
            st.upd(1,(sum[i]-x+len[i]-2)/(len[i]-1),1);
        }
        st.upd(1,(sum[i]+len[i]-1)/len[i],-1);
    }
    cout<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}