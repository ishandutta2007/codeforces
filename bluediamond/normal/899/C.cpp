#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    ll val=n*(n+1)/4;
    ll ans=n*(n+1)/2-2*val;
    cout<<ans<<"\n";
    vector<ll>a;
    for(ll i=n;i>=1;i--) {
        if(val>=i) {
            a.push_back(i);
            val-=i;
        }
    }
    cout<<a.size()<<" ";
    for(auto itr:a) {
        cout<<itr<<" ";
    }
    cout<<"\n";
    return 0;
}
/**

**/