#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    if (v[n/2] == s){
        cout << 0;
        return 0;
    }
    if (v[n/2] > s){
        int ans = 0;
        for (int i=n/2; i >= 0; i--){
            if (v[i] > s){
                ans += v[i]-s;
            }
        }
        cout << ans;
    }
    else{
        int ans = 0;
        for (int i=n/2; i < n; i++){
            if (v[i] < s){
                ans += s-v[i];
            }
        }
        cout << ans;
    }
}