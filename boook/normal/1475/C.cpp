#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 300000

int t, a, b, k, x[maxn][2], c[maxn][2];

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
    
    cin >> t;
    while (t --) {
        cin >> a >> b >> k;

        for (int i = 1; i <= a; ++ i) c[i][0] = 0;
        for (int i = 1; i <= b; ++ i) c[i][1] = 0;

        for (int i = 1; i <= k; ++ i) cin >> x[i][0];
        for (int i = 1; i <= k; ++ i) cin >> x[i][1];
        
        for (int i = 1; i <= k; ++ i) {
            c[x[i][0]][0] ++;
            c[x[i][1]][1] ++;
        }
        
        int ans = 0;
        for (int i = 1; i <= k; ++ i) {
            ans += k - c[x[i][0]][0] - c[x[i][1]][1] + 1;
        }
        cout << ans / 2 << "\n";
    }
    return 0;
}