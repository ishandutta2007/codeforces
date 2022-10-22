#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, k;
	std::cin >> n >> k;
    --k;
    std::vector<int> a(n);
    auto query = [&](int x, int y) {
        std::cout << "or " << x + 1 << " " << y + 1 << std::endl;
        int sor;
        std::cin >> sor;
        std::cout << "and " << x + 1 << " " << y + 1 << std::endl;
        int sand;
        std::cin >> sand;
        return sor + sand;
    };
    int x = query(0, 1), y = query(0, 2), z = query(1, 2);
    long long s = (0ll + x + y + z) / 2;
    a[0] = s - z;
    a[1] = s - y;
    a[2] = s - x;
    for (int i = 3; i < n; ++i) {
        a[i] = query(0, i) - a[0];
    }
    std::nth_element(a.begin(), a.begin() + k, a.end());
    std::cout << "finish " << a[k] << std::endl;
}