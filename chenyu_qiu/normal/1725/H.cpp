#include <bits/stdc++.h>
 
using i64 = long long;
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::array<int, 2> cnt{};
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        a[i] = x % 3 ? 1 : 0;
        cnt[a[i]]++;
    }
    
    int Z;
    std::string s;
    if (cnt[0] >= cnt[1]) {
        Z = 2;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0 && cur < n / 2) {
                cur++;
                s += '0';
            } else {
                s += '1';
            }
        }
    } else {
        Z = 0;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1 && cur < n / 2) {
                cur++;
                s += '0';
            } else {
                s += '1';
            }
        }
    }
    
    std::cout << Z << "\n";
    std::cout << s << "\n";
    
    return 0;
}