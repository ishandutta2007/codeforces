#include <bits/stdc++.h>
using namespace std;

const int N = 550000;

int f[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s, t; cin >> s >> t;
    int n = t.length();
    int m = s.length();
    if (m < n) {
        cout << s << endl;
        return 0;
    }
    f[1] = 0;
    for (int i = 1, j = 0; i < n; i++) {
        while (j && t[i] != t[j]) j = f[j];
        if (t[i] == t[j]) j++;
        f[i + 1] = j;
    }
    int add = 0, cur = 0;
    for (int i = f[n]; i < n; i++) add += t[i] - '0';
    for (int i = 0; i < f[n]; i++) cur += t[i] - '0';
    int tot = 0;
    for (int i = 0; i < m; i++) tot += s[i] - '0';
    if (tot < add + cur) {
        cout << s << endl;
        return 0;
    }
    int now = cur, len = f[n];
    int k = (m - len) / (n - f[n]);
    while (k > 0 && (now + k * add > tot || tot - now - k * add + f[n] + (n - f[n]) * k > m)) k--;
    if (!k) {
        cout << s << endl;
        return 0;
    }
    string ans(t.begin(), t.begin() + f[n]);
    for (int i = 0; i < k; i++) ans.insert(ans.end(), t.begin() + f[n], t.end());
    int rem = tot - now - k * add;
    for (int i = 0; i < rem; i++) ans.push_back('1');
    while (ans.size() < m) ans.push_back('0');
    cout << ans << endl;
    return 0;
}