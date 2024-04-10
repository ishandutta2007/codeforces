#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int ans = 0;
    bool pl = false;
    for (int i=0; i < n; i++){
        if (a[i] == b[i]){
            pl = false;
            continue;
        }
        if (pl){
            pl = false;
            ans++;
            continue;
        }
        if (i > 0){
            if (a[i-1] != b[i-1] && (a[i-1] != a[i])){
                pl = true;
                continue;
            }
        }
        ans++;
    }
    cout << ans;
}