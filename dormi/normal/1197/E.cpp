#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
const ll mod=1e9+7;
struct info{
    int extra;
    ll am;
    info(int a=INT_MAX, ll b=0){
        extra=a;
        am=b;
    }
};
info dp[MN];
vector<int> ins;
info merge(const info &a, const info &b){
    if(a.extra==b.extra)return info(a.extra,(a.am+b.am)%mod);
    else if(a.extra<b.extra) return a;
    return b;
}
struct seg{
    info t[2*MN];
    void update(int ind, int le, int ri, int loc, info val){
        if(loc<le||loc>ri)return;
        if(le==ri){
            t[ind]=merge(t[ind],val);
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,loc,val),update(right,mid+1,ri,loc,val);
        t[ind]=merge(t[left],info((t[right].extra==INT_MAX?INT_MAX:t[right].extra+ins[mid+1]-ins[le]),t[right].am));
    }
    info query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le)return info();
        if(le>=l&&ri<=r)return t[ind];
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        auto te=query(right,mid+1,ri,l,r);
        return merge(query(left,le,mid,l,r),info(te.extra==INT_MAX?INT_MAX:te.extra+max(0,ins[mid+1]-ins[max(le,l)]),te.am));
    }
}tree;
int first[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,a,b;
    cin>>n;
    int miout=INT_MAX;
    vector<pii> arr;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        miout=min(miout,a);
        ins.push_back(b);
        arr.push_back({b,a});
        first[i]=INT_MAX;
    }
    first[n]=INT_MAX;
    sort(ins.begin(),ins.end()),ins.erase(unique(ins.begin(),ins.end()),ins.end());
    sort(arr.begin(),arr.end(),greater<>());
    int last=INT_MAX,ind=sz(ins);
    for(auto x:arr){
        if(x.first!=last){
            if(ind<sz(ins))tree.update(0,0,sz(ins)-1,ind,dp[ind]);
            ind--;
        }
        int ne=lower_bound(ins.begin(),ins.end(),x.second)-ins.begin();
        first[ind]=min({first[ind],ne,first[ind+1]});
        info trans=tree.query(0,0,sz(ins)-1,ne,first[ne]-1);
        if(trans.extra==INT_MAX)trans=info(0,1);
        else trans.extra+=ins[ne]-x.second;
        if (dp[ind].extra == trans.extra)dp[ind].am = (dp[ind].am + trans.am) % mod;
        else dp[ind] = (dp[ind].extra<trans.extra?dp[ind]:trans);
        last=x.first;
    }
    if(ind<sz(ins))tree.update(0,0,sz(ins)-1,ind,dp[ind]);
    info best={INT_MAX,0};
    for(int i=0;i<sz(ins);i++){
        auto x=dp[i];
        if(ins[i]<miout){
            x.extra+=ins[i];
            if(x.extra==best.extra)best.am=(best.am+x.am)%mod;
            else best=(best.extra<x.extra?best:x);
        }
    }
    printf("%lli\n",best.am);
    return 0;
}