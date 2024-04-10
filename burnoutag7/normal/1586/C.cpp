#include<bits/stdc++.h>
using namespace std;

struct SegTree{
    int sz;
    vector<int> dat;

    SegTree(int _sz){
        sz=1;while(sz<_sz)sz<<=1;
        dat.resize(sz<<1);
    }

    void build(int *a,int n){
        for(int i=1;i<=n;i++)dat[i+sz-1]=a[i];
        for(int i=sz-1;i;i--)dat[i]=max(dat[i<<1],dat[i<<1|1]);
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
};

int n,m,q,mx[1000005],L[1000005];
string g[1000005];
vector<int> pre[1000005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>g[i];
        pre[i].resize(m);
    }
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            if(g[i][j]=='.'){
                pre[i][j]=i?j+1:1;
                if(i&&g[i-1][j]=='.')pre[i][j]=min(pre[i][j],pre[i-1][j]);
                if(j&&g[i][j-1]=='.')pre[i][j]=min(pre[i][j],pre[i][j-1]);
                mx[j+1]=max(mx[j+1],pre[i][j]);
            }
            if(i&&j&&g[i-1][j]=='X'&&g[i][j-1]=='X'){
                L[j+1]=1;
            }
        }
        L[j+1]+=L[j];
    }
    SegTree st(m);
    st.build(mx,m);
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<(st.qry(l,r)<=l&&L[l]==L[r]?"YES\n":"NO\n");
    }

    return 0;
}