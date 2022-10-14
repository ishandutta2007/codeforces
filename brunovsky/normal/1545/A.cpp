#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        vector<int> index(N);
        iota(begin(index), end(index), 0);
        sort(begin(index), end(index), [&](int u, int v) { return a[u] < a[v]; });
        bool busted = false;
        for (int l = 0, r = 1; l < N; l = r, r = l + 1) {
            while (r < N && a[index[l]] == a[index[r]])
                r++;
            array<int, 2> cnt_index = {};
            array<int, 2> cnt_sort = {};
            for (int i = l; i < r; i++) {
                cnt_index[index[i] & 1]++;
                cnt_sort[i & 1]++;
            }
            if (cnt_index != cnt_sort) {
                busted = true;
                break;
            }
        }
        if (busted) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}