#include<bits/stdc++.h>
using namespace std;

template<typename T> struct bitsum{
    int sz;
    vector<T> bit;

    bitsum(int _sz){
        sz=_sz;
        bit.resize(sz+1);
    }

    T sum(int pos){
        T res=0;
        while(pos>0){
            res+=bit[pos];
            pos-=pos&-pos;
        }
        return res;
    }

    void add(int pos,T val){
        while(pos<=sz){
            bit[pos]+=val;
            pos+=pos&-pos;
        }
    }

    void clear(){
        bit.assign(sz+1,0);
    }
};

template<typename T> struct bitmin{
    int sz;
    T inf;
    vector<T> bit;

    bitmin(int _sz,T _inf){
        sz=_sz;
        inf=_inf;
        bit.resize(sz+1,inf);
    }

    T get(int pos){
        T res=inf;
        while(pos>0){
            res=min(res,bit[pos]);
            pos-=pos&-pos;
        }
        return res;
    }

    void upd(int pos,T val){
        while(pos<=sz){
            bit[pos]=min(bit[pos],val);
            pos+=pos&-pos;
        }
    }

    void clear(){
        bit.assign(sz+1,inf);
    }
};

template<typename T> struct bitmax{
    int sz;
    T inf;
    vector<T> bit;

    bitmax(int _sz,T _inf){
        sz=_sz;
        inf=_inf;
        bit.resize(sz+1,inf);
    }

    T get(int pos){
        T res=inf;
        while(pos>0){
            res=max(res,bit[pos]);
            pos-=pos&-pos;
        }
        return res;
    }

    void upd(int pos,T val){
        while(pos<=sz){
            bit[pos]=max(bit[pos],val);
            pos+=pos&-pos;
        }
    }

    void clear(){
        bit.assign(sz+1,inf);
    }
};

typedef long long ll;
const ll inf=1e12;

int n,V,a[100005],pid[100005];
ll k,psum[100005],psmn[100005];
vector<ll> vals;
pair<ll,ll> f[100005],g[100005];

int getle(ll val){
    return upper_bound(vals.begin(),vals.end(),val)-vals.begin();
}

pair<ll,ll> ask(ll thr){
    f[0]={0,0};
    g[0]={0,1};
    static bitmin<int> minpos(V,n+1);
    minpos.clear();
    minpos.upd(pid[0],0);
    static bitmax<pair<ll,ll>> suff(n+1,{-inf,0});
    suff.clear();
    suff.upd(n+1,f[0]);
    static bitsum<int> lowcnt(V);
    lowcnt.clear();
    lowcnt.add(pid[0],1);
    static bitsum<ll> lowsum(V);
    lowsum.clear();
    ll thrsum=0,thrcnt=0;
    for(int i=1;i<=n;i++){
        f[i]={-inf,0};
        int lowid=getle(psum[i]-thr),lft=minpos.get(lowid),lowc=lowcnt.sum(lowid);
        thrsum+=lowc*(psum[i]-thr)-lowsum.sum(lowid);
        thrcnt+=lowc;
        lft=min(lft,i);
        if(lft){
            f[i]=max(f[i],{g[lft-1].first+psum[i]-thr,g[lft-1].second});
        }
        f[i]=max(f[i],suff.get(n+1-lft));
        g[i]=max(g[i-1],{f[i].first-psmn[i],f[i].second+1});
        suff.upd(n+1-i,f[i]);
        minpos.upd(pid[i],i);
        lowcnt.add(pid[i],1);
        lowsum.add(pid[i],psum[i]);
    }
    return {f[n].first+thrsum,f[n].second+thrcnt};
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        psum[i]=psum[i-1]+a[i];
        psmn[i]=min(psmn[i-1],psum[i]);
    }
    vals=vector<ll>(psum,psum+1+n);
    sort(vals.begin(),vals.end());
    vals.erase(unique(vals.begin(),vals.end()),vals.end());
    V=vals.size();
    for(int i=0;i<=n;i++)pid[i]=lower_bound(vals.begin(),vals.end(),psum[i])-vals.begin()+1;
    ll l=-inf,r=inf,ans;
    while(l<=r){
        ll m=l+r>>1;
        if(ask(m).second>=k){
            l=m+1;
            ans=m;
        }else{
            r=m-1;
        }
    }
    cout<<ask(ans).first+ans*k;

    return 0;
}