#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        ll a;
        ll div2=1;
        cin>>n;
        vector<ll> vals;
        for(int i=0;i<n;i++){
            cin>>a;
            while(a%2==0){
                a/=2;
                div2*=2;
            }
            vals.push_back(a);
        }
        sort(vals.begin(),vals.end());
        ll ans=0;
        for(int i=0;i<sz(vals)-1;i++)ans+=vals[i];
        ans+=vals.back()*div2;
        printf("%lli\n",ans);
    }
    return 0;
}