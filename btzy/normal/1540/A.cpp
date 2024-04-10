#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MAXN = 100000;
int arr[MAXN];
int32_t main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int ct=0;ct<tc;++ct){
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int ans=arr[n-1];
        int currloc=0;
        int currweight=n-1;
        for(int i=1;i<n;++i){
            ans-=(arr[i]-currloc)*currweight;
            currloc=arr[i];
            currweight-=i;
            currweight+=(n-i-1);
        }
        cout<<ans<<'\n';
    }
}