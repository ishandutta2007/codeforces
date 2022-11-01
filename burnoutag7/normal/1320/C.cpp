#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,p,sz;
ll init[1000005];
ll dat[4000005];
ll lazy[4000005];
pair<int,int> a[200005];
pair<int,int> b[200005];
pair<pair<int,int>,int> mon[200005];

void build(int bk,int l,int r){
    if(l==r){
        if(l<=b[m].first){
            dat[bk]=init[l];
        }else{
            dat[bk]=-1e18;
        }
        return;
    }
    build(bk<<1,l,(l+r)>>1);
    build(bk<<1|1,((l+r)>>1)+1,r);
    dat[bk]=max(dat[bk<<1],dat[bk<<1|1]);
}

void upd(int bk,int l,int r,int ql,int qr,ll val){
    if(qr<l||r<ql)return;
    if(ql<=l&&r<=qr){
        lazy[bk]+=val;
        dat[bk]+=val;
        return;
    }
    lazy[bk<<1]+=lazy[bk];
    dat[bk<<1]+=lazy[bk];
    lazy[bk<<1|1]+=lazy[bk];
    dat[bk<<1|1]+=lazy[bk];
    lazy[bk]=0;
    upd(bk<<1,l,(l+r)>>1,ql,qr,val);
    upd(bk<<1|1,((l+r)>>1)+1,r,ql,qr,val);
    dat[bk]=max(dat[bk<<1],dat[bk<<1|1]);
}

ll qry(int bk,int l,int r,int ql,int qr){
    if(qr<l||r<ql)return -1e18;
    if(ql<=l&&r<=qr){
        return dat[bk];
    }
    lazy[bk<<1]+=lazy[bk];
    dat[bk<<1]+=lazy[bk];
    lazy[bk<<1|1]+=lazy[bk];
    dat[bk<<1|1]+=lazy[bk];
    lazy[bk]=0;
    return max(qry(bk<<1,l,(l+r)>>1,ql,qr),qry(bk<<1|1,((l+r)>>1)+1,r,ql,qr));
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>p;

    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a+1,a+1+n);

    for(int i=1;i<=m;i++){
        cin>>b[i].first>>b[i].second;
    }
    sort(b+1,b+1+m);

    for(int i=1;i<=p;i++){
        cin>>mon[i].first.first>>mon[i].first.second>>mon[i].second;
    }
    sort(mon+1,mon+1+p);

    for(int i=1;i<=m;i++){
        if(b[i].first!=b[i-1].first)init[b[i].first]=-b[i].second;
        else init[b[i].first]=max(init[b[i].first],(ll)(-b[i].second));
    }
    for(int i=b[m].first-1;i>=1;i--){
        if(init[i]==0)init[i]=init[i+1];
        else init[i]=max(init[i],init[i+1]);
    }
    sz=1;while(sz<b[m].first)sz<<=1;
    build(1,1,sz);

    ll ans=-1e18;
    for(int i=1,j=1;i<=n;i++){
        while(j<=p&&mon[j].first.first<a[i].first){
            upd(1,1,sz,mon[j].first.second+1,b[m].first,mon[j].second);
            j++;
        }
        ll tmp=-a[i].second+qry(1,1,sz,1,b[m].first);
        ans=max(ans,tmp);
    }
    cout<<ans<<endl;

    return 0;
}