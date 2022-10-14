#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        ll a;
        ll m;
        cin>>n>>m;
        vector<pair<int,ll>> cnt;
        for(int i=1;i<=n;i++){
            cin>>a;
            ll am=1;
            while(a%m==0){
                a/=m;
                am*=m;
            }
            if(!sz(cnt)||cnt.back().first!=a)cnt.push_back({a,am});
            else cnt.back().second+=am;
        }
        int k;
        cin>>k;
        vector<pair<int,ll>> cnt2;
        for(int i=1;i<=k;i++){
            cin>>a;
            ll am=1;
            while(a%m==0){
                a/=m;
                am*=m;
            }
            if(!sz(cnt2)||cnt2.back().first!=a)cnt2.push_back({a,am});
            else cnt2.back().second+=am;
        }
        if(cnt!=cnt2){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
    return 0;
}