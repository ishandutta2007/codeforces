#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    
    int N;
    std::cin >> N;
    if(N < 4) std::cout << "NO";
    else if(N & 1) {
        std::cout << "YES\n5 + 4 = 9\n9 + 1 = 10\n10 - 2 = 8\n8 * 3 = 24\n";
        for(int i = 6; i < N; i += 2)
            std::cout << i + 1 << " - " << i << " = 1\n24 * 1 = 24\n";
    } else {
        std::cout << "YES\n2 * 3 = 6\n6 * 4 = 24\n 24 * 1 = 24\n";
        for(int i = 5; i < N; i += 2)
            std::cout << i + 1 << " - " << i << " = 1\n24 * 1 = 24\n";
    }
}