#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end(), [&](int a, int b){return a%2 < b%2;});
    int ans = 0;
    for(int i = 0; i<n; i++)
        for(int j = i+1; j<n; j++)
            if(__gcd(arr[i], 2*arr[j])>1) ans++;
    cout << ans << endl;
}

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}