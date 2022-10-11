#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int ui32;
const long long INFLL = 1e18;

using namespace std;

int cnt[30], n;
string s, t;

bool check(int x) {
    t = "";
    for (int i = 0; i < 26; i++) {
        int k = (cnt[i] + x - 1) / x;
        while (t.size() <= n && k > 0) {
            t += 'a' + i;
            --k;
        }
        if (t.size() > n) {
            return false;
        }
    }
    while (t.size() < n) {
        t += 'a';
    }
    return t.size() == n;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> s;
    cin >> n;
    int res = 0;
    for (auto ch : s) {
        ++cnt[ch - 'a'];
        if (cnt[ch - 'a'] == 1) {
            ++res;
        }
    }
    if (res > n) {
        cout << "-1\n";
        return 0;
    }
    int l = 0, r = 1e9 + 1;
    while (r > l + 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    check(r);
    cout << r << "\n";
    cout << t << "\n";
    return 0;
}