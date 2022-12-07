#include <bits/stdc++.h>  
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
using namespace std;
typedef long long ll;
 
ll n,m;
 
ll check(ll x, vector<ll> &arr){
    multiset <ll> nums;
    for(int i = 0; i <= n - x; i++) nums.insert(arr[i]);
    int prev = (*--nums.end());
    nums.erase(nums.find(prev));
    while(!nums.empty()) {
        auto it = nums.upper_bound(m - prev);
        if(it == nums.begin()) return 0;
        --it;
        prev = (*it);
        nums.erase(nums.find(prev));
    }
    return 1;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    vector<ll> arr(n);
    for(auto &x:arr)
        cin>>x;
    ll sum = 0;
    for(auto i: arr)
        sum += i;
    sort(arr.begin(), arr.end());
    ll l = 1, r = n;
    ll ans = sum + n;
    while(l <= r){
        ll mid = (l + r)/2;
        if(check(mid, arr)){
            ans = min(ans, sum + mid);
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout<<ans<<'\n';
    return 0;
}