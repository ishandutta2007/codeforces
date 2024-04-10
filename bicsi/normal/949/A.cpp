#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str; cin >> str;
    vector<int> open_zeros;
    vector<int> ones;

    int n = str.size();
    
    vector<int> nxt(n, -1);
    for (int i = 0; i < n; ++i) {
        if (str[i] == '0') {
            open_zeros.push_back(i);
            if (ones.empty()) continue;
            int one = ones.back();
            ones.pop_back();
            nxt[one] = i;
        } else {
            if (open_zeros.empty()) { cout << -1 << endl; return 0; }
            int zero = open_zeros.back(); open_zeros.pop_back();
            nxt[zero] = i;
            ones.push_back(i);
        }
    } 

    vector<vector<int>> ans;
    vector<bool> viz(n, false);
    for (int i = 0; i < n; ++i) {
        if (viz[i]) continue;

        vector<int> now;
        for (int j = i; j != -1; j = nxt[j]) {
            viz[j] = true;
            now.push_back(j);
        }
        ans.push_back(now);
    }

    if (ones.size()) {
        cout << -1 << endl;
        return 0;
    }

    cout << ans.size() << '\n';
    for (auto x : ans) {
        cout << x.size() << " ";
        for (auto y : x) 
            cout << y + 1 << " ";
        cout << '\n';
    }
    return 0;

}