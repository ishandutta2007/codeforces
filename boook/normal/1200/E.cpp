/*input
2
ab ab
*/
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn 100090
#define inf 0x3f3f3f3f
#define mod 1000000009
#define ac 10430579
#define bc 37
#define nn 1000000000

int n;
string s[maxn], ans;
cc_hash_table<long long, int> cc;

int ppow(int v, int k) {
    if (k == 0) return 1;
    else if ((k & 1) == 0) return ppow(1ll * v * v % mod, k >> 1);
    else if ((k & 1) == 1) return ppow(1ll * v * v % mod, k >> 1) * 1ll * v % mod;
}

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> s[i];
    int h[2] = {1, 0}, invh = ppow(ac, mod - 2);
    int m[2] = {1, 0}, invm = ppow(bc, mod - 2);
    for (int i = 1; i <= n; ++ i) {
        int len = 0, val[2] = {0, 0};
        long long now;
        for (int j = 0; j < s[i].size(); ++ j) {
            val[0] = (1ll * val[0] * ac + s[i][j]) % mod;
            val[1] = (1ll * val[1] * bc + s[i][j]) % mod;
            now = (1ll * val[0] * h[0] + h[1]) % mod * nn + (1ll * val[1] * m[0] + m[1]) % mod;
            if (cc.find(now) != cc.end()) len = j + 1;
        }
        for (int j = len; j < s[i].size(); ++ j)
            ans += s[i][j];
        for (int j = len; j < s[i].size(); ++ j) {
            h[0] = 1ll * h[0] * invh % mod;
            m[0] = 1ll * m[0] * invm % mod;
            h[1] = (h[1] - 1ll * s[i][j] * h[0] % mod + mod) % mod;
            m[1] = (m[1] - 1ll * s[i][j] * m[0] % mod + mod) % mod;

            int v1 = (1ll * s[i][j] * h[0] + h[1]) % mod;
            int v2 = (1ll * s[i][j] * m[0] + m[1]) % mod;
            cc[1ll * v1 * nn + v2] = 1;
        }
    }
    cout << ans << "\n";
    return 0;
}