#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
#define ll long long
 
void solve(){
    ll n,x;cin>>n>>x;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans=0,mx=a[0],mn=a[0];
    for(ll i=1;i<n;i++){
        mx=max(mx,a[i]);
        mn=min(mn,a[i]);
        if(mx-mn > 2*x){
            ans+=1;
            mx=a[i];
            mn=a[i];
        }
    }
    cout<<ans<<endl;
}
int main() {
    ll t;cin>>t;
    while(t--){
       solve();
    }
}