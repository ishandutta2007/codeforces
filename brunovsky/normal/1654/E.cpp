#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
namespace gnu = __gnu_pbds;
using namespace std;

template <typename K, typename V, typename Hash = std::hash<K>>
using hash_map = gnu::gp_hash_table<K, V, Hash>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int first = a[0];
    for (int i = 0; i < N; i++) {
        a[i] -= first;
    }
    auto o = a;
    sort(begin(o), end(o));
    int ans = min(2, N);
    for (int l = 0, r = 1; l < N; l = r++) {
        while (r < N && o[l] == o[r])
            r++;
        ans = max(ans, r - l);
    }

    int H = *max_element(begin(a), end(a));
    int M = *min_element(begin(a), end(a));
    int V = H - M;
    if (V <= 1) {
        cout << N - ans << '\n';
        return 0;
    }

    const int S = sqrt(V);
    const int B = V / S + 5;

    vector<int> count(110'000'000);

    for (int i = 0; i < N; i++) {
        vector<int> bs;
        for (int j = i + 1; j < i + B && j < N; j++) {
            int b = (a[j] - a[i]) / (j - i);
            if (abs(b) > S && b * int64_t(j - i) == a[j] - a[i]) {
                ans = max(ans, 1 + ++count[b + V]);
                bs.push_back(b);
            }
        }
        for (int b : bs) {
            count[b + V] = 0;
        }
    }

    for (int ab = 1; ab <= S; ab++) {
        if (V / ab + 1 <= ans) {
            break;
        }
        for (int64_t b : {-ab, ab}) {
            for (int i = 0; i < N; i++) {
                ans = max(ans, ++count[b * i - a[i] + 50'000'000]);
            }
            for (int i = 0; i < N; i++) {
                count[b * i - a[i] + 50'000'000] = 0;
            }
        }
    }

    cout << N - ans << '\n';
    return 0;
}