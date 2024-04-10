#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
ll arr[101];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    ll k;
    cin>>n>>k;
    vector<ll> newsum;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(ll j=1;j*j<=arr[i];j++){
            newsum.push_back(j);
            newsum.push_back((arr[i]+j-1)/j);
        }
        k+=arr[i];
    }
    sort(newsum.begin(),newsum.end());
    newsum.erase(unique(newsum.begin(),newsum.end()),newsum.end());
    ll ans=0;
    for(int cur=0;cur<sz(newsum);cur++){
        ll sum=0;
        for(int i=0;i<n;i++)sum+=(arr[i]+newsum[cur]-1)/newsum[cur];
        ll d=k/sum;
        if(d>=newsum[cur]&&d<(cur+1==sz(newsum)?LLONG_MAX:newsum[cur+1]))ans=d;
    }
    printf("%lli\n",ans);
    return 0;
}