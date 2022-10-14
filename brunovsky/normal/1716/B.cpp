#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

auto output(const vector<int>& a) {
    int N = a.size();
    for (int i = 0; i < N; i++) {
        cout << a[i] << " \n"[i + 1 == N];
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N);
        iota(begin(a), end(a), 1);
        cout << N << '\n';
        output(a);
        for (int i = 1; i < N; i++) {
            swap(a[i - 1], a[i]);
            output(a);
        }
    }
    return 0;
}