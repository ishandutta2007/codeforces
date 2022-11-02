#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    cin.tie(0), cout.sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    string a[100], b[100];

    for (int i = 0; i < n; ++ i) cin >> a[i];
    for (int i = 0; i < m; ++ i) cin >> b[i];
    
    int q;
    cin >> q;
    while (q --) {
        int now;
        cin >> now;
        string ans;
        now = (now - 1) % (n * m);
        int p1 = 0, p2 = 0;

        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < m; ++ j) {
                if (ans.size() != 0) break;
//                cout << p1 << " - " << p2 << endl;
                if (now == 0) {
                    ans = a[p1] + b[p2];
                }
                else {
                    now --;
                    p1 = (p1 + 1) % n;
                    p2 = (p2 + 1) % m;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}