#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, need, k;

string get_min(int k) {
    if (!k) {
        return "";
    }
    int len = k / 9 + 1;
    string res;
    while (len > 1) {
        --len;
        int st = 0;
        if (res == "") {
            st = 1;
        }
        for (int x = st; x <= 9; ++x) {
            if (k - x <= 9 * len - 1) {
                res += '0' + x;;
                k -= x;
                break;
            }
        }
    }
    res += '0' + k;
    return res;
}

bool is_less(const string &a, const string &b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (0) {
        for (int i = 0; i <= 150; ++i) {
            cout << i << ": " << get_min(i) << endl;
        }
    }
    cin >> t;
    while (t--) {
        cin >> need >> k;
        string best;
        for (int d = 0; d < 10; ++d) {
            for (int cnt = 0; cnt <= 16; ++cnt) {
                int sum = 0;
                for (int i = 0; i <= k; ++i) {
                    sum += (d + i) % 10;
                    if (d + i >= 10) {
                        sum += 1;
                    } else {
                        sum += 9 * cnt;
                    }
                }
                if (sum <= need && (need - sum) % (k + 1) == 0) {
                    int x = (need - sum) / (k + 1);
                    string ans = get_min(x);
                    for (int i = 0; i < cnt; ++i) {
                        ans += '9';
                    }
                    ans += '0' + d;
                    if (best == "") {
                        best = ans;
                    } else {
                        if (is_less(ans, best)) {
                            best = ans;
                        }
                    }
                }
            }
        }
        if (best == "") {
            cout << -1 << "\n";
        } else {
            cout << best << "\n";
        }
    }
    return 0;
}