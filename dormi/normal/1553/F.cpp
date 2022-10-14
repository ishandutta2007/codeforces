#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1,MV=3e5+1;
ll bitcnt[MV];
ll bitval[MV];
void updatecnt(int loc, ll v){
    for(;loc<MV;loc+=loc&-loc)bitcnt[loc]+=v;
}
void updateval(int loc, ll v){
    for(;loc<MV;loc+=loc&-loc)bitval[loc]+=v;
}
ll querycnt(int loc){
    ll sum=0;
    for(;loc>0;loc-=loc&-loc)sum+=bitcnt[loc];
    return sum;
}
ll queryval(int loc){
    ll sum=0;
    for(;loc>0;loc-=loc&-loc)sum+=bitval[loc];
    return sum;
}
ll ans[MN];
ll arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll tot=0;
    for(int i=0;i<n;i++){
        ll larger=querycnt(arr[i]);
        ll smaller=i-larger;
        ll smallersum=queryval(arr[i]);
        tot+=larger*arr[i]+smaller*arr[i]-smallersum;
        ans[i]+=tot;
        updatecnt(1,1),updatecnt(arr[i],-1);
        for(ll j=1;j*arr[i]<MV;j++){
            ll val=j*arr[i];
            updateval(val,val);
            updateval(val+arr[i],-val);
        }
    }
    for(int i=0;i<MV;i++)bitcnt[i]=0,bitval[i]=0;
    tot=0;
    for(int i=0;i<n;i++){
        for(ll j=0;j*arr[i]<MV;j++){
            ll am=querycnt(min(ll(MV-1),arr[i]*(j+1)-1))-querycnt(arr[i]*j-1);
            ll totsum=queryval(min(ll(MV-1),arr[i]*(j+1)-1))-queryval(arr[i]*j-1);
            tot+=totsum-am*j*arr[i];
        }
        ans[i]+=tot;
        updatecnt(arr[i],1);
        updateval(arr[i],arr[i]);
    }
    for(int i=0;i<n;i++)printf("%lli%c",ans[i]," \n"[i==n-1]);
    return 0;
}