// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn 200000 + 10
#define inf 0x3f3f3f3f

int t, n, x[maxn];

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> t;
    while (t --) {
        cin >> n;
        for (int i = 1; i <= n; ++ i) cin >> x[i];
        set<int> ans;
        for (int i = 1; i <= n; ++ i) {
            int now = x[i];
            while (now % 2 == 0) ans.insert(now), now >>= 1;
        }
        cout << ans.size() << endl;
    }
    return 0;
}