#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {
    int n; cin >> n;

    vector<int> can_be_zero(10, true);
    vector<int> contrib(10, 0);
    while (n--) {
        string s; cin >> s;
        can_be_zero[s[0] - 'a'] = false;
        reverse(s.begin(), s.end());
        
        int coef = 1;
        for (auto c : s) {
            contrib[c - 'a'] += coef;
            coef *= 10;
        }    
    }
    
    vector<int> taken(10, false);
    int ans = 0;

    for (int dig = 0; dig < 10; ++dig) {
        pair<int, int> take = {-1, -1};
        for (int i = 0; i < 10; ++i) {
            if (taken[i]) continue;
            if (can_be_zero[i] == false && dig == 0) continue;

            take = max(take, make_pair(contrib[i], i));
        }
        // cerr << char(take.second + 'a') << " -> " << dig << endl;
        taken[take.second] = true;
        ans += dig * take.first;
    }
    cout << ans << endl;

    return 0;
}