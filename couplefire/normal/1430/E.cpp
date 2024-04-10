#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

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

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    queue<int> pos[26];
    for(int i = 0; i<n; i++) pos[s[i]-'a'].push(i);
    reverse(s.begin(), s.end());
    FenwickTree tree(n);
    long long ans = 0;
    for(int i = 0; i<n; i++){
        int p = pos[s[i]-'a'].front(); pos[s[i]-'a'].pop();
        // cout << p << endl;
        ans += p-i+tree.sum(p, n-1);
        tree.add(p, 1);
    }
    cout << ans << endl;
}