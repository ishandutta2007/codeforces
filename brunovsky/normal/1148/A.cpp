#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int64_t a, b, c;
    cin >> a >> b >> c;
    cout << 2 * c + 2 * min(a, b) + (a != b) << '\n';
    return 0;
}