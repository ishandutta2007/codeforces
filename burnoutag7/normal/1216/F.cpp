#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct SegTree{
    int sz;
    vector<ll> dat;

    SegTree(int _sz){
        _sz++;
        sz=1;while(sz<_sz)sz<<=1;
        dat.resize(sz<<1,1e18);
    }

    void upd(int pos,ll val){
        pos++;
        pos+=sz-1;
        dat[pos]=min(dat[pos],val);
        while(pos>1){
            pos>>=1;
            dat[pos]=min(dat[pos<<1],dat[pos<<1|1]);
        }
    }

    ll qry(int id,int l,int r,int ql,int qr){
        if(qr<l||r<ql)return 1e18;
        if(ql<=l&&r<=qr)return dat[id];
        return min(qry(id<<1,l,l+r>>1,ql,qr),qry(id<<1|1,(l+r>>1)+1,r,ql,qr));
    }

    ll qry(int l,int r){
        l++;
        r++;
        return qry(1,1,sz,l,r);
    }
};

int n,k;
char s[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>s+1;
    SegTree st(n);
    st.upd(0,0);
    for(int i=1;i<=n;i++)if(s[i]=='1'){
        st.upd(min(i+k,n),st.qry(i-k-1,n)+i);
    }else{
        st.upd(i,st.qry(i-1,n)+i);
    }
    cout<<st.qry(n,n);

    return 0;
}