/*input

*/
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
#define mod 998244353

int n, m, gi[maxn], ni[maxn];

int C(int a, int b) {
    if (a < b) return 0;
    return gi[a] * ni[b] % mod * ni[a - b] % mod;
}
void getcountmath() {
    gi[0] = ni[0] = ni[1] = 1;
    for (int i = 1; i < maxn; ++ i) {
        gi[i] = gi[i - 1] * i % mod;
    }
    for (int i = 2; i < maxn; ++ i) {
        ni[i] = ni[mod % i] * (mod - mod / i) % mod;
    }
    for (int i = 1; i < maxn; ++ i) {
        ni[i] = ni[i] * ni[i - 1] % mod;
    }
}

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
    getcountmath();
    cin >> n >> m;
    if (n == 2) return cout << 0 << "\n", 0;
    int ans = 0, base = 1;
    for (int i = 1; i <= n - 3; ++ i) {
        base = base * 2 % mod;
    }
    for (int i = 2; i <= m; ++ i) {
        int tmp = n - 2;
        int val = C(i - 1, n - 3) * base % mod * (i - 1 - (n - 3)) % mod;
//        cout << C(i - 1, n - 3) << endl;
//        if (m != 4) exit(0);
        ans = (ans + val) % mod;
    }
    cout << ans << "\n";
    return 0;
}