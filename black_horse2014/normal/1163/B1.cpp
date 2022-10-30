#include <bits/stdc++.h>
using namespace std;

int cnt[110000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int ans = 1;
    set<pair<int, int> > S;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        int &y = cnt[x];
        if (y) S.erase({y, x});
        y++;
        S.insert({y, x});
        if (S.size() == 1) {
            ans = i;
            continue;
        }
        auto it = S.begin();
        auto jt = --S.end();
        if (it->first == 1) {
            if (i - 1 == (S.size() - 1) * jt->first) {
                ans = i;
                continue;
            }
        }
        if (jt->first == it->first + 1) {
            if (i - 1 == S.size() * it->first) {
                ans = i;
                continue;
            }
        }
    }
    cout << ans << endl;
    return 0;
}