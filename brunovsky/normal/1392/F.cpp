#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

auto stress(vector<int64_t> h) {
    int N = h.size();
    while (true) {
        vector<int> drop;
        for (int i = 1; i < N; i++) {
            if (h[i - 1] + 2 <= h[i]) {
                drop.push_back(i);
            }
        }
        if (drop.empty()) {
            break;
        }
        for (int i : drop) {
            h[i - 1]++, h[i]--;
        }
    }
    return h;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int64_t> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }
    int plat = 0;
    int64_t base = h[0];
    for (int i = 1; i < N; i++) {
        if (int64_t p = base + i - 2; plat < i - 1 && p + 1 < h[i]) {
            int transfer = min<int64_t>(h[i] - p - 1, i - 1 - plat);
            plat += transfer;
            h[i] -= transfer;
        }
        if (int64_t p = base + i - 1; plat == i - 1 && p + 1 < h[i]) {
            // p + k < h[i] - ki
            // <=> (i+1)k < h[i] - p
            // k < (h[i] - p)/(i+1)
            int64_t k = (h[i] - p - 1) / (i + 1);
            base += k;
            p += k;
            h[i] -= i * k;
            if (h[i] > p + 1) {
                plat = h[i] - p - 2;
                base++;
            } else {
                plat = i;
            }
        } else if (plat == i - 1 && p < h[i]) {
            plat = i;
        }

#ifdef LOCAL
        vector<int64_t> a(i + 1);
        for (int k = 0; k < i + 1; k++) {
            a[k] = base + k - (k > plat);
        }
#endif
    }
    for (int i = 0; i < N; i++) {
        h[i] = base + i - (i > plat);
    }
    for (int i = 0; i < N; i++) {
        cout << h[i] << " \n"[i + 1 == N];
    }
    return 0;
}