#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct tree{
    int n;
    vector<int> bit;
    tree(int _n){
        n = _n;
        bit.assign(n, -1e9);
    }
    void upd(int pos, int val){
        for(; pos<n; pos=(pos|(pos+1)))
            bit[pos] = max(bit[pos], val);
    }
    int query(int r){
        int ans = -1e9;
        for(; r>=0; r=(r&(r+1))-1)
            ans = max(ans, bit[r]);
        return ans;
    }
};

void solve(){
    int n; cin >> n;
    vector<int> arr(n+1, 0);
    for(int i = 1; i<=n; ++i)
        cin >> arr[i];
    vector<pair<ll, ll>> stuff(n+1);
    stuff[0] = {0, 0};
    for(int i = 1; i<=n; ++i)
        stuff[i] = {stuff[i-1].first+arr[i], i};
    sort(stuff.begin(), stuff.end());
    tree t(n+1);
    vector<int> dp(n+1, -1e9);
    ll cur = 0;
    for(int i = 0; i<=n; ++i){
        cur += arr[i];
        if(i==0){
            dp[i] = 0;
        } else{
            dp[i] = dp[i-1]+(arr[i]<0?-1:0);
            int bruh = lower_bound(stuff.begin(), stuff.end(), pair<ll, ll>{cur, -1})-stuff.begin()-1;
            dp[i] = max(dp[i], t.query(bruh)+i);
        }
        int pos = lower_bound(stuff.begin(), stuff.end(), pair<ll, ll>{cur, i})-stuff.begin();
        t.upd(pos, dp[i]-i);
    }
    cout << dp[n] << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}