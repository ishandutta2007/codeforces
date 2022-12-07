#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> occ(26);
    vector<vector<int>> cnt(26, vector<int>(n, 0));
    vector<int> good;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0 && i + 1 < n && s[i] == s[i + 1]) {
            good.push_back(i);
        }
        occ[s[i] - 'a'].push_back(i);
        if(i == 0) {
            cnt[s[i] - 'a'][0] = 1;
        } else {
            for(int j = 0; j < 26; j++) {
                cnt[j][i] = cnt[j][i - 1];
            }
            cnt[s[i] - 'a'][i] += 1;
        }
    }
    int ans = 0;
    vector <bool> marked(n, false);
    for(int i = 0; i < n; i++) {
        if(marked[i]) continue;
        if(i == n - 1) {
            ans++;
            continue;
        }
        if(s[i] == s[i + 1]) {
            marked[i + 1] = true;
            continue;
        }
        int c = s[i] - 'a';
        if(cnt[c][i] == cnt[c][n - 1]) {
            ans++;
            continue;
        }
        int nx = *upper_bound(occ[c].begin(), occ[c].end(), i);
        int found_repeat = false;
        for(int j = 0; j < 26; j++) {
            if(j == c) continue;
            int count = cnt[j][nx] - (i == 0 ? 0 : cnt[j][i - 1]);
            if(count >= 2) {
                found_repeat = true;
                break;
            }
        }
        if(found_repeat) {
            ans++;
        } else {
            ans += (nx - i - 1);
            for(int j = i; j <= nx; j++) {
                marked[j] = true;
            }
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}