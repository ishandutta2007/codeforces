#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> d(m), h(m);
    for (int i = 0; i < m; ++i) {
        cin >> d[i] >> h[i];
    }
    
    for (int i = 0; i + 1 < m; ++i) {
        if (abs(h[i + 1] - h[i]) > d[i + 1] - d[i]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    
    int ans = d[0] - 1 + h[0];
    ans = max(ans, n - d[m - 1] + h[m - 1]);
    for (int i = 0; i + 1 < m; ++i) {
        if (h[i + 1] >= h[i]) {
            int delta = d[i + 1] - d[i];
            delta -= (h[i + 1] - h[i]);
            int k = delta / 2;
            ans = max(ans, h[i + 1] + k);
        } else {
            int delta = d[i + 1] - d[i];
            delta -= (h[i] - h[i + 1]);
            int k = delta / 2;
            ans = max(ans, h[i] + k);
        }
    }
    
    cout << ans << endl;
    
    
    return 0;
}