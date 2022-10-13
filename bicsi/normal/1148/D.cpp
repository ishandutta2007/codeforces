#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

vector<int> Solve(vector<pair<int, int>> v) {
    vector<int> order;
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        if (v[i].first > v[i].second) continue;
        order.push_back(i);
    }
    sort(order.begin(), order.end(), [&](int a, int b) {
        return v[a].second > v[b].second;         
    });
    return order;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
        --v[i].first; --v[i].second;
    }

    vector<int> ans1 = Solve(v);
    for (int i = 0; i < n; ++i) {
        v[i].first = 2 * n - v[i].first - 1;
        v[i].second = 2 * n - v[i].second - 1;
    }
    vector<int> ans2 = Solve(v);
    
    if (ans1.size() < ans2.size()) 
        swap(ans1, ans2);

    cout << ans1.size() << endl;
    for (auto x : ans1) cout << x + 1 << " ";
    cout << endl;

    return 0;
}