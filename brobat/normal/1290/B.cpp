#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> cnt(1, vector<int>(26, 0));
    cnt[0][s[0] - 'a']++;
    for(int i = 1; i < n; i++) {
        cnt.push_back(cnt.back());
        cnt.back()[s[i] - 'a']++;
    }
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        if(l == r || s[l] != s[r]) {
            cout << "Yes" << '\n';
            continue;
        }
        int c = 0;
        for(int i = 0; i < 26; i++) {
            int x = cnt[r][i] - (l == 0 ? 0 : cnt[l - 1][i]);
            if(x > 0) c++;
        }
        if(c >= 3) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    
    return 0;
}