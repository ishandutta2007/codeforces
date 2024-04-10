#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename O, typename T>
auto compress(const vector<T>& u, T s = 0) {
    int N = u.size();
    if (N == 0)
        return vector<O>();

    vector<pair<T, int>> ps(N);
    for (int i = 0; i < N; i++) {
        ps[i] = {u[i], i};
    }
    sort(begin(ps), end(ps));

    vector<O> v(N);
    v[ps[0].second] = s;
    for (int i = 1; i < N; i++) {
        v[ps[i].second] = v[ps[i - 1].second] + (ps[i].first != ps[i - 1].first);
    }
    return v;
}

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
        a = compress<int>(a);
        const int V = 1 + *max_element(begin(a), end(a));
        vector<int> left(V, N), right(V);
        for (int i = 0; i < N; i++) {
            left[a[i]] = min(i, left[a[i]]);
            right[a[i]] = max(i, right[a[i]]);
        }
        int ans = V - 1;
        for (int l = 0, r = 1; r < V; l = r++) {
            while (r < V && right[r - 1] < left[r])
                r++;
            ans = min(ans, V - r + l);
        }
        cout << ans << '\n';
    }
    return 0;
}