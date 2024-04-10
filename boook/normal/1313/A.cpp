#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn 
#define inf 0x3f3f3f3f

int t, n, a, b;

int32_t main(){
    cin.tie(0), cout.sync_with_stdio(0);
    cin >> t; 
    while (t --) {
        cin >> n >> a >> b;
        int ans = 0;
        for (int i = 0; i < (1 << 7); ++ i) {
            int v1 = 0, v2 = 0, v3 = 0, cnt = 0;
            for (int j = 0; j < 7; ++ j) if (i & (1 << j)) {
                int pat = j + 1;
                cnt ++;
                if (pat & (1 << 0)) v1 ++;
                if (pat & (1 << 1)) v2 ++;
                if (pat & (1 << 2)) v3 ++;
            }
            if (v1 <= n && v2 <= a && v3 <= b) ans = max(ans, cnt);
        }
        cout << ans << "\n";
    }
    return 0;
}