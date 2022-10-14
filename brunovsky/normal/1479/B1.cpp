#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> a(N + 1, -1);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<int> b1 = {0}, b2 = {0};
    int B1 = 0, B2 = 0;
    for (int i = 0; i < N; i++) {
        if (b1.back() != a[i] && b1.back() == a[i + 1]) {
            b1.push_back(a[i]), B1++;
        } else if (b2.back() != a[i] && b2.back() == a[i + 1]) {
            b2.push_back(a[i]), B2++;
        } else if (b1.back() != a[i]) {
            b1.push_back(a[i]), B1++;
        } else if (b2.back() != a[i]) {
            b2.push_back(a[i]), B2++;
        }
    }
    cout << B1 + B2 << '\n';
    return 0;
}