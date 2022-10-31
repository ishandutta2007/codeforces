#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> arr(n), brr(n);
    for(int i = 0; i<n; i++)
        cin >> arr[i];
    for(int i = 0; i<n; i++)
        cin >> brr[i];
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());
    reverse(arr.begin(), arr.end());
    reverse(brr.begin(), brr.end());
    int lo = 0, hi = 1e9;
    auto check = [&](int mid)->bool{
        int best = (mid+n)-(mid+n)/4;
        int need1 = min(best, mid), take1 = best-need1;
        int take2 = min(best, n), need2 = best-take2;
        long long res1 = 0, res2 = 0;
        for(int i = 0; i<take1; i++)
            res1 += arr[i];
        res1 += 100ll*need1;
        for(int i = 0; i<take2; i++)
            res2 += brr[i];
        return res1 >= res2;
    };
    while(lo < hi){
        int mid = lo+(hi-lo)/2;
        if(check(mid)) hi = mid;
        else lo = mid+1;
    }
    cout << lo << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}