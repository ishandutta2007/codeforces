#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        p[i] = {x, i};
    }
    sort(p.begin(), p.end());
    
    vector<int> c(n);
    for(auto&i : c) cin >> i;
    
    multiset<int> mx_coin;
    long long sum_coin = 0;
    vector<long long> ans(n);
    for (auto [x, id]: p) {
        sum_coin += c[id];
        ans[id] = sum_coin;
        mx_coin.insert(c[id]);
        while ((int)mx_coin.size() > k) {
            sum_coin -= *mx_coin.begin();
            mx_coin.erase(mx_coin.begin());
        }
    }
    
    for (auto i: ans) cout << i << ' ';
    
    return 0;
}