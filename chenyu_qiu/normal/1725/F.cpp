#include <bits/stdc++.h>
 
using i64 = long long;
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> ans(30);
    
    std::vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        std::cin >> l[i] >> r[i];
        l[i]--;
    }
    
    for (int j = 0; j < 30; j++) {
        std::vector<std::array<int, 2>> events;
        for (int i = 0; i < n; i++) {
            if (r[i] - l[i] >= (1 << j)) {
                events.push_back({0, 1});
            } else {
                int L = l[i] % (1 << j);
                int R = r[i] % (1 << j);
                if (L < R) {
                    events.push_back({L, 1});
                    events.push_back({R, -1});
                } else {
                    events.push_back({0, 1});
                    events.push_back({L, 1});
                    events.push_back({R, -1});
                }
            }
        }
        
        int cur = 0;
        std::sort(events.begin(), events.end());
        for (auto [_, v] : events) {
            cur += v;
            ans[j] = std::max(ans[j], cur);
        }
    }
    
    int q;
    std::cin >> q;
    
    for (int i = 0; i < q; i++) {
        int x;
        std::cin >> x;
        std::cout << ans[__builtin_ctz(x)] << "\n";
    }
    
    return 0;
}