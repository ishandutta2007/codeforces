#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    while (TT--) {
        int n, x;
        cin >> n >> x;
        string s;
        cin >> s;
        map<int, int> cnt;
        int su = 0;
        for (auto& c : s) {
            cnt[su]++;
            su += (c == '1' ? -1 : 1);
        }
        if (su == 0) {
            if (cnt.count(x)) {
                cout << -1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else {
            if (su < 0) {
                map<int, int> q;
                for (auto& p : cnt) {
                    q[-p.first] = p.second;
                }
                cnt = q;
                x = -x;
            }
            int amt = 0;
            for (auto& p : cnt) {
                if (p.first <= x && (x-p.first)%su == 0) {
                    amt += p.second;
                }
            }
            cout << amt << "\n";
        }
    }
    return 0;
}