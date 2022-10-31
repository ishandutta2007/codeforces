#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = (long long)1e16;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;
    FenwickTree(){}
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

void solve(){
    int n; cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> arr(n), brr(n);
    for(int i = 0; i<n; ++i)
        arr[i] = s[i]-'a';
    for(int i = 0; i<n; ++i)
        brr[i] = t[i]-'a';
    vector<vector<int>> pos(26);
    for(int i = 0; i<n; ++i)
        pos[arr[i]].push_back(i);
    for(int i = 0; i<26; ++i)
        reverse(pos[i].begin(), pos[i].end());
    int ans = INF, cur = 0;
    FenwickTree tree(n+5);
    for(int i = 0; i<n; ++i){
        int c = brr[i];
        int mn = INF;
        for(int j = 0; j<c; ++j)
            if(!pos[j].empty())
                mn = min(mn, pos[j].back());
        if(mn!=INF)
            ans = min(ans, cur+mn+tree.sum(mn+1, n-1)-i);
        if(!pos[c].size()) break;
        int id = pos[c].back(); 
        pos[c].pop_back();
        cur += id+tree.sum(id+1, n-1)-i;
        tree.add(id, 1);
    }
    cout << (ans==INF?-1:ans) << '\n';
}

signed main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}