#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=2e5+1;
ll arr[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll a;
        for(int i=0;i<n;i++)cin>>arr[i];
        reverse(arr,arr+n);
        ll last=arr[0];
        ll ans=0;
        for(int i=1;i<n;i++){
            a=arr[i];
            ans+=max(ll(0),a-last);
            last=a;
        }
        printf("%lli\n",ans);
    }
    return 0;
}