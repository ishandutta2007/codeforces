#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector <int> OPS(n, 0);
    int sub = 0;
    int ops = 0;
    int ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        sub -= ops;
        ops -= OPS[i];
        // Now sub stores the current value that has been subtracted.
        // Now find how many ops are needed at the current position.
        v[i] -= sub;
        // cout << i << " " << sub << " " << ops << " " << v[i] << endl;
        if(v[i] > 0) {
            int x = v[i]/min(k, i + 1);
            if(v[i] % min(k, i + 1) > 0) x++;
            // x ops are needed.
            ops += x;
            sub += x * min(k, i + 1);
            if(i >= k) {
                OPS[i - k] += x;
            }
            ans += x;
        }
    }
    cout << ans;
    return 0;
}