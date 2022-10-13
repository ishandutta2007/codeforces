#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

struct FenwickTree {
    int n; vector<int> data;
    FenwickTree(int n) : n(n), data(n + 1, 0) {}

    void Add(int pos) {
        for (++pos; pos > 0; pos -= (pos & -pos))
            data[pos] += 1;    
    }
    int Query(int pos) {
        int ans = 0;
        for (++pos; pos < (int)data.size(); pos += (pos & -pos))
            ans += data[pos];
        return ans;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n), b(n), pos_b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; --a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i]; --b[i];
        pos_b[b[i]] = i;
    }

    FenwickTree fw(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (fw.Query(pos_b[a[i]])) ans += 1;
        fw.Add(pos_b[a[i]]);
    }
    cout << ans << endl;

    return 0;
}