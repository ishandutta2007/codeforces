#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e4+1;
ll arr[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll sum=0;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        if(sum%ll(n)!=0){
            printf("-1\n");
        }
        else{
            vector<pair<pii,ll>> ops;
            ll sameam=sum/ll(n);
            for(ll i=2;i<=n;i++){
                ll needed=(i-(arr[i]%i))%i;
                ops.push_back({{1,i},needed});
                ops.push_back({{i,1},(arr[i]+needed)/i});
            }
            for(ll i=2;i<=n;i++){
                ops.push_back({{1,i},sameam});
            }
            printf("%d\n", sz(ops));
            for (auto x:ops)printf("%d %d %lli\n", x.first.first, x.first.second, x.second);
        }
    }
    return 0;
}