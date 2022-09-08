#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 100111, mod = 1000000007;

int pw[max_n], sumpw[max_n];
string s;

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    pw[0] = sumpw[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        pw[i] = mul(pw[i - 1], 10);
        sumpw[i] = (sumpw[i - 1] + pw[i]) % mod;
    }
    cin >> s;
    int x = 0;
    long long ans = 0;
    for (int i = 0; i + 1 < s.length(); ++i) {
        x = mul(x, 10);
        x += s[i] - '0';
        x %= mod;
        ans += mul(x, sumpw[s.length() - i - 2]);
    }
    x = 0;
    for (int i = s.length() - 1; i; --i) {
        x += mul(pw[s.length() - i - 1], s[i] - '0');
        x %= mod;
        ans += mul(x, i);
    }
    ans %= mod;
    cout << ans << "\n";
    return 0;
}