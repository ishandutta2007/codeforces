#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=500000;
const ll ninf=-1e18;

struct segtreevial{
    int sz;
    vector<ll> dat;

    segtreevial(int n){
        sz=1;while(sz<n)sz<<=1;
        dat.resize(sz<<1,ninf);
    }

    segtreevial(int n,ll *a){
        sz=1;while(sz<n)sz<<=1;
        dat.resize(sz<<1,ninf);
        for(int i=1;i<=n;i++)dat[i+sz-1]=a[i];
        for(int i=sz-1;i>=1;i--)dat[i]=max(dat[i<<1],dat[i<<1|1]);
    }

    void upd(int pos,ll val){
        pos+=sz-1;
        if(dat[pos]>=val)return;
        dat[pos]=val;
        while(pos>1){
            pos>>=1;
            dat[pos]=max(dat[pos<<1],dat[pos<<1|1]);
        }
    }

    ll qry(int id,int l,int r,int ql,int qr){
        if(qr<l||r<ql)return ninf;
        if(ql<=l&&r<=qr)return dat[id];
        return max(qry(id<<1,l,l+r>>1,ql,qr),qry(id<<1|1,(l+r>>1)+1,r,ql,qr));
    }

    ll qry(int l,int r){
        return qry(1,1,sz,l,r);
    }

    ll get(int q){
        return dat[q+sz-1];
    }
};

struct segment{
    ll lv,rv,ans;
    segment(ll l=ninf,ll r=ninf){
        lv=l;
        rv=r;
        ans=lv+rv;
    }
    segment operator+(const segment& rhs)const{
        segment res(max(lv,rhs.lv),max(rv,rhs.rv));
        res.ans=max(lv+rhs.rv,max(ans,rhs.ans));
        return res;
    }
};

struct segtree{
    int sz;
    vector<segment> dat;

    segtree(int n){
        sz=1;while(sz<n)sz<<=1;
        dat.resize(sz<<1);
    }

    segtree(int n,ll *a,ll *b){
        sz=1;while(sz<n)sz<<=1;
        dat.resize(sz<<1);
        for(int i=1;i<=n;i++)dat[i+sz-1]=segment(a[i],b[i]);
        for(int i=sz-1;i>=1;i--)dat[i]=dat[i<<1]+dat[i<<1|1];
    }

    segment qry(int id,int l,int r,int ql,int qr){
        if(qr<l||r<ql)return segment();
        if(ql<=l&&r<=qr)return dat[id];
        return qry(id<<1,l,l+r>>1,ql,qr)+qry(id<<1|1,(l+r>>1)+1,r,ql,qr);
    }

    ll qry(int l,int r){
        return qry(1,1,sz,l,r).ans;
    }
};

int n,q,a[N+5],b[N+5],c[N+5];
ll sa[N+5],sb[N+5],sc[N+5],s[N+5],f[N+5],dp[N+5];
vector<pair<int,int>> lb[N+5];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sa[i]=sa[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        sb[i]=sb[i-1]+b[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
        sc[i]=sc[i-1]+c[i];
    }
    for(int i=1;i<=q;i++){
        int l,r,k;
        cin>>l>>r>>k;
        lb[r].emplace_back(l,k);
    }
    for(int i=1;i<=n;i++){
        s[i]=sa[i]-sb[i-1];
        f[i]=sb[i]+sc[n]-sc[i-1];
    }
    segtreevial ss(n,s),sdp(n);
    for(int r=1;r<=n;r++){
        for(auto &[l,k]:lb[r]){
            sdp.upd(r,max(ss.qry(l,r),sdp.qry(l-1,r-1))-k);
        }
    }
    for(int i=1;i<=n;i++)dp[i]=sdp.get(i);
    segtree cross(n,dp,f),single(n,s,f);
    ll ans=ninf;
    for(int r=1;r<=n;r++){
        for(auto &[l,k]:lb[r]){
            ans=max(ans,single.qry(l,r)-k);
            ans=max(ans,cross.qry(l-1,r)-k);
        }
    }
    cout<<ans<<'\n';

    return 0;
}