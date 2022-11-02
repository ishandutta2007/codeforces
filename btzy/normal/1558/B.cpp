#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=4000000;
int mod;
struct fenwick {
    constexpr static int FWSIZE=MAXN+2;
    int arr[FWSIZE];
    int query(int index){
        long long ans=0;
        for(;index>0;index-=index&-index){
            ans+=arr[index];
        }
        return static_cast<int>(ans%mod);
    }
    void update(int index, int inc){
        for(;index<FWSIZE;index+=index&-index){
            arr[index]+=inc;
            if(arr[index]>=mod)arr[index]-=mod;
        }
    }
};
struct ru_fenwick {
    fenwick fw;
    int query(int index){
        return fw.query(index);
    }
    void update(int first, int last, int inc){
        fw.update(first,inc);
        int neg=mod-inc;
        if(neg>=mod)neg-=mod;
        fw.update(last,neg);
    }
} fw;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n>>mod;
    int drag=1;
    for(int j=2;j<=n;++j){
        int jj=min(j*2,n+1);
        fw.update(j,jj,1);
    }
    for(int i=2;i<n;++i){
        int total=drag+fw.query(i);
        if(total>=mod)total-=mod;
        drag+=total;
        if(drag>=mod)drag-=mod;
        for(int j=2*i,q=2;j<=n;j+=i,++q){
            int jj=min(j+q,n+1);
            fw.update(j,jj,total);
        }
        //cout<<i<<' '<<total<<'\n';
    }
    int ans=drag+fw.query(n);
    if(ans>=mod)ans-=mod;
    cout<<ans<<'\n';
}