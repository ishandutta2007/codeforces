#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int mx = *max_element(arr.begin(), arr.end());

    vector<int> prv(n);
    stack<int> prv_st;
    for (int i = 0; i < n; ++i) {
        while (prv_st.size() && arr[prv_st.top()] < arr[i]) {
            prv_st.pop();
        }
        prv[i] = prv_st.size() ? prv_st.top() : -1;
        prv_st.push(i);
    }
    
    vector<int> nxt(n);
    stack<int> nxt_st;
    for (int i = n-1; i >= 0; --i) {
        while (nxt_st.size() && arr[nxt_st.top()] <= arr[i]) {
            nxt_st.pop();
        }
        nxt[i] = nxt_st.size() ? nxt_st.top() : n;
        nxt_st.push(i);
    }

    vector<pair<int, int>> ranges(n);
    for (int i = 0; i < n; ++i) {
        ranges[i] = {prv[i]+1, nxt[i]-1};
    }
    
    vector<vector<int>> pos(mx+1);
    for (int i = 0; i < n; ++i) {
        pos[arr[i]].push_back(i);
    }

    long long ans = 0;
    set<pair<int, int>> sections;
    sections.insert({0, n-1});
    for (int mn = 1; mn <= mx; ++mn) {
        if (pos[mn].empty()) {
            continue;
        }
        for (int val = mn; val <= mx; val += mn) {
            for (int x : pos[val]) {
                if (arr[x] < mn) {
                    continue;
                }
                int l = ranges[x].first;
                int r = ranges[x].second;
                auto it1 = prev(sections.lower_bound(pair<int, int>{x+1, -1}));
                l = max(l, (*it1).first);
                r = min(r, (*it1).second);
                auto it2 = lower_bound(pos[mn].begin(), pos[mn].end(), x);
                int bad_l = it2 == pos[mn].begin() ? l : max((*prev(it2))+1, l);
                int bad_r = it2 == pos[mn].end() ? r : min((*it2)-1, r);
                ans += 1ll*(x-l+1)*(r-x+1)-1ll*(x-bad_l+1)*(bad_r-x+1);
            }
        }
        for (int x : pos[mn]) {
            auto it = prev(sections.lower_bound(pair<int, int>{x+1, -1}));
            int l = (*it).first, r = (*it).second;
            sections.erase(it);
            if (l != x) {
                sections.insert({l, x-1});
            }
            if (r != x) {
                sections.insert({x+1, r});
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}