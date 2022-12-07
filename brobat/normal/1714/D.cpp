#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        int n = s.length();
        int m;
        cin >> m;
        vector <string> t(m);
        for(int i = 0; i < m; i++) {
            cin >> t[i];
        }
        vector <vector<int>> v;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int cnt_same = 0;
                for(int k = 0; k < (int)t[j].size(); k++) {
                    if(i + k >= n) break;
                    if(s[i + k] == t[j][k]) cnt_same++;
                }
                if(cnt_same == (int)t[j].size()) {
                    v.push_back({i, i + cnt_same - 1, j});
                }
            }
        }
        sort(v.begin(), v.end(), [&](vector <int> a, vector <int> b) {
            return a[0] > b[0];
        });
        int l = 0;
        int r = -1;
        int curr = -1;
        vector<pair<int, int>> ans;
        bool pos = true;
        while(l < n) {
            int temp_l = -1;
            r = -1;
            curr = -1;
            while(!v.empty() && v.back()[0] <= l) {
                if(v.back()[1] > r) {
                    r = v.back()[1];
                    curr = v.back()[2];
                    temp_l = v.back()[0];
                }
                v.pop_back();
            }
            if(r == -1) {
                pos = false;
                break;
            }
            ans.push_back({curr, temp_l});
            l = r + 1;
        }
        if(!pos) {
            cout << -1 << '\n';
            continue;
        }
        cout << (int)ans.size() << '\n';
        for(auto i : ans) cout << i.first + 1 << " " << i.second + 1 << '\n';
    }
    
    return 0;
}