#include <bits/stdc++.h>
 
using i64 = long long;
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, d;
    std::cin >> n >> d;
    
    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }
    
    std::sort(p.begin(), p.end(), std::greater());
    
    int ans = 0;
    int r = n;
    for (int i = 0; i < r; i++) {
        int t = d / p[i] + 1;
        if (r - i < t) {
            break;
        }
        r -= t - 1;
        ans++;
    }
    
    std::cout << ans << "\n";
    
    return 0;
}