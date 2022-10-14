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
        ll k;
        cin>>n>>k;
        for(int i=0;i<n;i++)cin>>arr[i];
        ll ma=*max_element(arr,arr+n);
        for(int i=0;i<n;i++)arr[i]=ma-arr[i];
        k-=ll(1);
        if(k%2==1){
            ma=*max_element(arr,arr+n);
            for(int i=0;i<n;i++)arr[i]=ma-arr[i];
        }
        for(int i=0;i<n;i++)printf("%lli ",arr[i]);
        printf("\n");
    }
    return 0;
}