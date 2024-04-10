#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
bool cmp(int a, int b) {
    return (a % 2) > (b % 2);
}
void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string s;
    cin >> s;
    int cnta = 0, cntb = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'A')
            cnta++;
        else
            cntb++;
    }
    if (cnta != a + c + d) {
        cout << "NO\n";
        return;
    }
    if (cntb != b + c + d) {
        cout << "NO\n";
        return;
    }
    vector<int> aba, bab;
    int ccc = 0;
    for (int i = 0; i + 1 < s.size(); ++i) {
        if (s[i] == 'A' and s[i+1] == 'B') {
            int cnt = 2;
            i += 1;
            while (i + 1 < s.size() and s[i+1] == s[i-1]) {
                cnt++;
                i++;
            }
            if (cnt % 2 == 0)
                aba.push_back(cnt);
            else
                ccc += cnt / 2;
            continue;
        }
        if (s[i] == 'B' and s[i+1] == 'A') {
            int cnt = 2;
            i += 1;
            while (i + 1 < s.size() and s[i+1] == s[i-1]) {
                cnt++;
                i++;
            }
            if (cnt % 2 == 0)
                bab.push_back(cnt);
            else
                ccc += cnt / 2;
        }
    }
    sort(all(aba));
    sort(all(bab));
    reverse(all(aba));
    reverse(all(bab));
    while (!aba.empty() and c != 0) {
        aba.back() -= 2;
        c--;
        if (aba.back() <= 1)
            aba.pop_back();
    }
    while (!bab.empty() and d != 0) {
        bab.back() -= 2;
        d--;
        if (bab.back() <= 1)
            bab.pop_back();
    }
    if (!bab.empty())
        bab.back()--;
    while (!bab.empty() and c != 0) {
        if (bab.back() >= 2) {
            bab.back() -= 2;
            c--;
        }
        if (bab.back() <= 1) {
            bab.pop_back();
            if (!bab.empty())
                bab.back()--;
        }
    }
    if (!aba.empty())
        aba.back()--;
    while (!aba.empty() and d != 0) {
        if (aba.back() >= 2) {
            aba.back() -= 2;
            d--;
        }
        if (aba.back() <= 1) {
            aba.pop_back();
            if (!aba.empty())
                aba.back()--;
        }
    }
    if (c + d <= ccc) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}