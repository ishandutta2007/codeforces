#include <bits/stdc++.h>
 
using i64 = long long;
template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    Fenwick(int n) : n(n), a(n) {}
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    T sum(int x) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
};
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        a[i] += a[i - 1];
    }
    
    for (int i = 0; i <= n; i++) {
        if (a[i] < 0 || a[i] > a[n]) {
            std::cout << "-1\n";
            return 0;
        }
    }
    
    std::vector<std::array<i64, 2>> b;
    for (int i = 1; i < n; i++) {
        b.push_back({a[i], i});
    }
    std::sort(b.begin(), b.end());
    
    Fenwick<int> fen(n);
    i64 ans = 0;
    for (auto [_, i] : b) {
        ans += fen.rangeSum(i + 1, n);
        fen.add(i, 1);
    }
    std::cout << ans << "\n";
    
    return 0;
}