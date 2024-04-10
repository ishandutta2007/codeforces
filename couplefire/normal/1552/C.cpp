#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k; cin >> n >> k; n *= 2;
    vector<array<int, 2>> arr(k);
    int ans = 0;
    for(int i = 0; i<k; i++)
        cin >> arr[i][0] >> arr[i][1],
        --arr[i][0], --arr[i][1];
    for(int i = 0; i<k; i++)
        if(arr[i][0]>arr[i][1])
            swap(arr[i][0], arr[i][1]);
    vector<bool> used(2*n, 0);
    for(int i = 0; i<k; i++)
        used[arr[i][0]] = used[arr[i][1]] = 1;
    for(int i = 0; i<n; i++)
        used[i+n] = used[i];
    for(int i = 0; i<k; i++)
        for(int j = i+1; j<k; j++){
            auto [a, b] = arr[i];
            auto [c, d] = arr[j];
            if(b < a) b += n;
            if(d < c) d += n;
            if(a > c) swap(a, c), swap(b, d);
            if(c < b && d > b) ++ans;
        }
    int tot = 0;
    for(int i = 0; i<n; i++)
        if(!used[i]) ++tot;
    for(int i = 0; i<k; i++){
        auto [a, b] = arr[i];
        if(b < a) b += n;
        int stuff = 0;
        for(int j = a+1; j<b; ++j)
            if(!used[j]) ++stuff;
        ans += min(stuff, tot-stuff);
    }
    ans += (tot/2)*((tot/2)-1)/2;
    cout << ans << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    int t; cin >> t;
    while(t--) solve();
}