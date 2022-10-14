#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename T>
struct vector_rollback : vector<T> {
    using base_t = vector<T>;

    vector<pair<int, T>> history;

    template <typename... Args>
    explicit vector_rollback(Args&&... args) : base_t(forward<Args>(args)...) {}

    int time() const { return history.size(); }
    void rollback(int t) {
        int i = time();
        while (i-- > t) {
            rollback();
        }
    }
    void rollback() {
        auto [i, value] = history.back();
        base_t::at(i) = value;
        history.pop_back();
    }

    void set(int i, T value) {
        history.emplace_back(i, base_t::at(i));
        base_t::at(i) = value;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<vector<pair<int, int>>> query(N);
    for (int q = 0; q < Q; q++) {
        int a, b;
        cin >> a >> b, a--;
        query[a].push_back({q, b});
    }

    // either the LIS contains i or it doesn't
    // (1) it contains i,b[i]:
    //    find predecessor j of i with b[j]<b[i] with largest LIS, size a
    //    find successor j of i with b[j]>b[i] with largest LIS, size b
    //    answer: a+1+b
    // (2) it doesn't contain i,b[i]:
    //    ...

    vector<int> Psuf(N, N - 1);
    vector<int> Lsuf(N, 0);
    vector_rollback<int> Msuf(N + 1, 0);
    for (int L = 0, i = N - 1; i >= 0; i--) {
        int lo = 1, hi = L;
        while (lo <= hi) {
            int mid = (lo + hi + 1) / 2;
            if (h[Msuf[mid]] > h[i])
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        Psuf[i] = lo;
        Msuf.set(lo, i);
        L = max(L, lo);
        Lsuf[i] = L;
    }
    debug(Psuf);
    debug(Msuf);
    int LIS = Lsuf[0];
    debug(LIS);

    vector<int> ans(Q, LIS - 1);
    vector<vector<int>> candidates(LIS + 1);

    vector<int> Ppref(N, 0), Mpref(N + 1, 0);
    for (int L = 0, i = 0; i < N; i++) {
        Msuf.rollback();

        for (auto [q, b] : query[i]) {
            // set a[i] to b

            // first, find predecessor j of i with b[j] < b[i] and largest LIS
            int lo = 1, hi = L;
            while (lo <= hi) {
                int mid = (lo + hi + 1) / 2;
                if (h[Mpref[mid]] < b) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            int left_lis = lo; // includes b

            // second, find successor j of i with b[j] > b[i] and largest LIS
            lo = 1, hi = i + 1 < N ? Lsuf[i + 1] : 0;
            while (lo <= hi) {
                int mid = (lo + hi + 1) / 2;
                if (h[Msuf[mid]] > b) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            int right_lis = lo; // includes b

            int inclusive_lis = left_lis + right_lis - 1; // includes b
            ans[q] = max(ans[q], inclusive_lis);
        }

        int lo = 1, hi = L;
        while (lo <= hi) {
            int mid = (lo + hi + 1) / 2;
            if (h[Mpref[mid]] < h[i])
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        Ppref[i] = lo;
        Mpref[lo] = i;
        L = max(L, lo);

        // can a[i] be in the LIS?
        if (Ppref[i] + Psuf[i] - 1 == LIS) {
            candidates[Ppref[i]].push_back(i);
        }
    }
    debug(Ppref);

    vector<bool> unfortunate(N);

    for (int l = 1; l <= LIS; l++) {
        assert(!candidates[l].empty());
        if (candidates[l].size() == 1u) {
            unfortunate[candidates[l][0]] = true;
        }
    }

    for (int i = 0; i < N; i++) {
        if (!unfortunate[i]) {
            for (auto [q, b] : query[i]) {
                ans[q] = max(ans[q], LIS);
            }
        }
    }

    for (int i = 0; i < Q; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}