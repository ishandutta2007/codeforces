#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = (int)1E18;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    int n = s.length();
    int ans[10][10];
    memset(ans, 0, sizeof(ans));
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            vector <int> mn(105, INF);
            mn[i] = 1;
            mn[j] = 1;
            vector <int> diff(10, INF);
            for(int k = 0; k < 105; k++) {
                if(k >= i) {
                    mn[k] = min(mn[k], mn[k - i] + 1);
                }
                if(k >= j) {
                    mn[k] = min(mn[k], mn[k - j] + 1);
                }
                diff[k % 10] = min(diff[k % 10], mn[k]);
            }
            for(int k = 1; k < n; k++) {
                int a = s[k];
                int b = s[k - 1];
                int d = (a - b + 10) % 10;
                if(diff[d] == INF) {
                    ans[i][j] = -INF; 
                    break;
                }
                ans[i][j] += diff[d] - 1;
            }
        }
    }
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(ans[i][j] < 0) cout << -1 << " ";
            else cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}