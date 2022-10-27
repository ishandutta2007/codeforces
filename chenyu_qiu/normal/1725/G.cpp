#include <bits/stdc++.h>
 
using i64 = long long;
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    if (n == 1) {
        std::cout << 3 << "\n";
        return 0;
    }
    
    n += 2;
    
    if (n % 3 == 0) {
        std::cout << n / 3 * 4 << "\n";
    } else if (n % 3 == 1) {
        std::cout << n / 3 * 4 + 1 << "\n";
    } else {
        std::cout << n / 3 * 4 + 3 << "\n";
    }
    
    return 0;
}