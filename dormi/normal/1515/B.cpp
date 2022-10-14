#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    set<ll> good;
    for(ll i=1;;i++){
        good.insert(i*i*2);
        good.insert(i*i*4);
        if(i*i*2>ll(1e9))break;
    }
    while(t--){
        int n;
        cin>>n;
        if(good.count(n)){
            printf("YES\n");
        }
        else printf("NO\n");
    }
    return 0;
}