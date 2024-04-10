#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        ll n,r;
        cin>>n>>r;
        r=min(r,n);
        printf("%lli\n",r*(r+ll(1))/ll(2)-(r==n?ll(n-1):ll(0)));
    }
    return 0;
}