#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<string> s(n);
    vector<pair<int, int>> pos;
    for (int i = n; i--; ) {
        cin >> s[i];
        int k; cin >> k;
        while (k--) {
            int u; cin >> u;
            pos.emplace_back(u, i);
        }
    }
    
    sort(pos.begin(), pos.end());
    // for (auto i: pos) cout << i.first << ' ' << s[i.second] << endl;
    int u = 0, cur = -1;
    for (int i = 1; ; ++i) {
        while (u < (int)pos.size() and pos[u].first < i) ++u;
        for (; u < (int) pos.size() and pos[u].first == i; ++u) {
            if (cur == -1 or pos[cur].first + s[pos[cur].second].size() < pos[u].first + s[pos[u].second].size())
                cur = u;
        }
        
        // cout << i << ' ' << cur << endl;
        
        if (cur == -1 or pos[cur].first + s[pos[cur].second].size() <= i) {
            if (u == (int)pos.size()) break;
            cout << 'a';
        } else cout << s[pos[cur].second][i - pos[cur].first];
    }
}