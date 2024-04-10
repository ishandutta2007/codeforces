#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll MAXN = 300000;
ll arr[MAXN];
ll inv[MAXN];
vector<pair<ll,ll>> ans;
void sw(ll i, ll j){
    ans.push_back({i,j});
    swap(inv[arr[i]],inv[arr[j]]);
    swap(arr[i],arr[j]);
}
int main(){
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    for(ll i=0;i<n;++i){
        cin>>arr[i];
        --arr[i];
        inv[arr[i]]=i;
    }
    const ll half=n/2;
    for(ll i=0;i*2+2<n;++i){
        {
            ll curr=half-1-i;
            if(inv[curr]>=half){
                sw(inv[curr],0);
            }
            sw(inv[curr],n-1);
            sw(n-1,curr);
        }
        {
            ll curr=half+i;
            if(inv[curr]<half){
                sw(inv[curr],n-1);
            }
            sw(inv[curr],0);
            sw(0,curr);
        }
    }
    if(arr[0]!=0){
        sw(0,n-1);
    }
    cout<<ans.size()<<'\n';
    for(const auto x:ans){
        cout<<x.first+1<<' '<<x.second+1<<'\n';
    }
}