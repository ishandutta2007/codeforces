#include <bits/stdc++.h>

using namespace std;

const int max_n = -1;
const long long inf = 1000111222000111222LL;

int t;
long long n, s;

long long get_sum(long long x) {
    long long res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        vector<int> v;
        long long x = n;
        while (x) {
            v.push_back(x % 10);
            x /= 10;
        }
        reverse(v.begin(), v.end());
        if (v.size() == 19) {
            puts("0");
            continue;
        }
        long long ans = inf, pw = 1;
        for (int i = 0; i < v.size(); ++i) {
            pw *= 10;
        }
        long long cur = 0;
        if (get_sum(n) <= s) {
            ans = 0;
        }
        for (int i = 0; i <= v.size(); ++i) {
            long long x = cur * pw + pw;
            if (x >= n && get_sum(x) <= s) {
                ans = min(ans, x - n);
            }
            pw /= 10;
            if (i < v.size()) {
                cur = cur * 10 + v[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}