#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int mn = (int)1E18;
    for(int i = 0; i < n; i++) {
        // assume x[i] = 0.
        int curr = 0;
        int ans = 0;
        for(int j = i + 1; j < n; j++) {
            int temp = (curr/v[j]) * v[j];
            while(temp <= curr) temp += v[j];
            ans += (temp/v[j]);
            curr = temp;
        }
        curr = 0;
        for(int j = i - 1; j >= 0; j--) {
            int temp = (curr/v[j]) * v[j];
            while(temp <= curr) temp += v[j];
            ans += (temp/v[j]);
            curr = temp;
        }
        mn = min(mn, ans);
    }
    cout << mn;
    
    return 0;
}