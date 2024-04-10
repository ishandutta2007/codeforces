#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (auto& i: a) cin >> i;
    
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    
    map<ll, int> answer;
    auto upd_ans = [&](ll time, int cnt) {
        auto [it, is_new] = answer.try_emplace(time, cnt);
        if (!is_new) {
            it->second = min(it->second, cnt);
        }
    };
    
    upd_ans(sum, 1);
    ll cur_mx = 0;
    ll cur_sum = 0;
    for (int i = 1; i < n; ++i) {
        cur_sum += a[i - 1];
        cur_mx = max(cur_mx, (cur_sum + i - 1) / i);
        upd_ans(max((sum + i) / (i + 1), cur_mx), i + 1);
    }
    
    int q;
    cin >> q;
    while (q--) {
        ll t;
        cin >> t;
        auto it = answer.upper_bound(t);
        if (it == answer.begin()) {
            cout << "-1\n";
        } else {
            cout << prev(it)->second << '\n';
        }
    }
}