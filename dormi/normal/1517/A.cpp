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
    while(t--){
        ll n;
        cin>>n;
        if(n%ll(2050)==0){
            n/=2050;
            string a=to_string(n);
            ll ans=0;
            for(auto x:a){
                ans+=x-'0';
            }
            printf("%lli\n",ans);
        }
        else printf("-1\n");
    }
    return 0;
}