#include <bits/stdc++.h>
using namespace std;
#define int long long

char query(int x) {
    cout << "? 1 " << x + 1 << endl;
    char c; cin >> c; return c;
}

int query2(int l, int r) {
    cout << "? 2 " << l + 1 << " " << r + 1 << endl;
    int c; cin >> c; return c;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, char>> occ;
    int prev = 0;
    for(int i = 0; i < n; i++) {
        int curr = query2(0, i);
        if(curr > prev) {
            occ.push_back({i, '0'});
        }
        prev = curr;
    }
    int m = occ.size();
    for(int i = 0; i < m; i++) {
        occ[i].second = query(occ[i].first);
    }
    vector <char> a(n);
    for(int i = 0; i < n; i++) {
        // binary search to find the current character.
        sort(occ.begin(), occ.end(), [&](pair<int, char> a, pair<int, char> b) {
            return a.first > b.first;
        });
        // cout << "DEBUG: " << i << ",-- ";
        // for(auto i : occ) cout << i.first << "," << i.second << " ";
        // cout << '\n';
        bool pos = false;
        for(int j = 0; j < m; j++) {
            if(occ[j].first == i) {
                a[i] = occ[j].second;
                pos = true;
            }
        }
        if(pos) continue;
        int l = 0;
        int r = m - 1;
        while(occ[l].first > i) {
            l++;
        }
        int lf = l;
        int ans;
        char c;
        while(l <= r) {
            int x = (l + r)/2;
            if(query2(occ[x].first, i) == x + 1 - lf) {
                c = occ[x].second;
                ans = x;
                r = x - 1;
            } else {
                l = x + 1;
            }
        }
        a[i] = c;
        occ[ans].first = i;
    }
    cout << "! ";
    for(auto i : a) cout << i;
    cout << endl;
    return 0;
}