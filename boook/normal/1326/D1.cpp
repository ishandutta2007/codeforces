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
#define AC 10430579
#define mod 1000'000'009

int t, h[maxn], m[maxn], b[maxn], v[maxn], ok;
string s, f;

int ppow(int a, int k) {
    if (k == 0) return 1;
    else if (k % 2 == 0) return ppow(a * a % mod, k >> 1);
    else if (k % 2 == 1) return ppow(a * a % mod, k >> 1) * a % mod;
}

void InitHash() {
    m[0] = v[0] = 1, v[1] = ppow(AC, mod - 2);
    for (int i = 0; i < s.size(); ++ i) h[i + 1] = (h[i] * AC + s[i]) % mod;
    for (int i = 0; i < s.size(); ++ i) m[i + 1] = (m[i] * AC) % mod;
    for (int i = 0; i < s.size(); ++ i) b[i + 1] = (b[i] + s[i] * m[i]) % mod;
    for (int i = 0; i < s.size(); ++ i) v[i + 1] = v[i] * v[1] % mod;
}

int Query(int l, int r) {
    return (h[r + 1] - h[l] * m[r - l + 1] % mod + mod) % mod;
}

int QueryRev(int l, int r) {
    return (b[r + 1] - b[l] + mod) * v[l] % mod;
}

int Solve() {
    InitHash();
    string pre, suf;
    int base = 0, ans = 0, v1 = 0, v2 = s.size() - 1;
    while (v1 < v2 && s[v1] == s[v2]) v1 ++, v2 --, base += 2, ans += 2;

    for (int i = 0; i < v1; ++ i) pre += s[i];
    suf = pre, reverse(suf.begin(), suf.end());
    if (ok == base) ok = -1, f = pre + suf;
    for (int i = v1; i <= v2; ++ i) {
        if (Query(v1, i) == QueryRev(v1, i)) {
            ans = max(ans, base + i - v1 + 1);
            if (ok == base + i - v1 + 1) {
                f += pre;
                for (int j = v1; j <= i; ++ j) f += s[j];
                f += suf;
                ok = -1;
            }
        }
    }
    return ans;
}

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> t;
    while (t --) {
        cin >> s, f = "";
        int ans = 1;
        ans = max(ans, Solve());
        reverse(s.begin(), s.end());
        ans = max(ans, Solve());
        ok = ans;
        Solve();
        reverse(s.begin(), s.end());
        Solve();
        cout << f << "\n";
    }
    return 0;
}