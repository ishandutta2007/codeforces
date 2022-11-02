#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll MAXN = 300000;
pair<ll,ll> arr[MAXN];
vector<pair<ll,ll>> v;
int main(){
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    for(ll i=0;i<n;++i){
        cin>>arr[i].first>>arr[i].second;
    }
    ll ct=0;
    for(ll i=0;i<n;++i){
        if(arr[i].first<arr[i].second){
            ++ct;
        }
    }
    if(ct*2>=n){
        for(ll i=0;i<n;++i){
            if(arr[i].first<arr[i].second){
                v.push_back({arr[i].second,i});
            }
        }
        sort(v.begin(),v.end(),greater<pair<ll,ll>>());
    }
    else{
        for(ll i=0;i<n;++i){
            if(arr[i].first>=arr[i].second){
                v.push_back({arr[i].second,i});
            }
        }
        sort(v.begin(),v.end(),less<pair<ll,ll>>());
    }
    cout<<v.size()<<'\n';
    for(const auto x:v){
        cout<<x.second+1<<' ';
    }
    cout<<'\n';
}