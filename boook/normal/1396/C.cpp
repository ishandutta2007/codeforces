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
#define maxn 1000900
#define inf 0x3f3f3f3f


int n, r1, r2, r3, d, x[maxn], p[maxn], s[maxn];

int R2(int floor) {
    return min(r2, x[floor] * r1 + r1);
}

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> n >> r1 >> r2 >> r3 >> d;
    for (int i = 1; i <= n; ++ i) cin >> x[i];
    
    p[0] = -d;
    for (int i = 1; i <= n; ++ i) {
        p[i] = p[i - 1] + d + x[i] * r1 + r3;

        if (i >= 1) {
            p[i] = min(p[i], p[i - 2] + d + R2(i - 1) + d + R2(i) + d + r1 + d + r1);
        }
    }
    
    s[n] = min(x[n] * r1 + r3, R2(n) + d + d + r1);

    for (int i = n - 1; i >= 1; -- i) {
        s[i] = s[i + 1] + R2(i) + d + d + r1;
    }
    
//    for (int i = 1; i <= n; ++ i) cout << p[i] << " \n"[i == n];
//    for (int i = 1; i <= n; ++ i) cout << s[i] << " \n"[i == n];
    int ans = p[n];
    for (int i = 1; i < n; ++ i) {
        ans = min(ans, p[i] + d + s[i + 1]);
    }

    cout << ans << "\n";
    return 0;
}