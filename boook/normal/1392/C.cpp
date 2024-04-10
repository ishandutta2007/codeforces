// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define int long long
#define maxn 200900
#define inf 0x3f3f3f3f

int t, n, x[maxn];

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> t;
    while (t --) {
        cin >> n;
        for (int i = 1; i <= n; ++ i) cin >> x[i];
        int ans = 0;
        for (int i = 2; i <= n; ++ i) ans += max(0ll, x[i - 1] - x[i]);
        cout << ans << "\n";
    }
    return 0;
}