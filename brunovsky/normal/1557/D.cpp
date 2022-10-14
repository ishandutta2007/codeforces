#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

template <typename T, typename V>
struct merging_interval_processor : map<array<T, 2>, V> {
    static constexpr inline T inf = numeric_limits<T>::max();
    using run_t = array<T, 2>;
    using base_t = map<array<T, 2>, V>;

    run_t universe() const {
        return {base_t::begin()->first[0], base_t::rbegin()->first[1]};
    }

    template <typename Fn>
    void write(run_t intv, V color, Fn&& processor) {
        auto& [L, R] = intv;
        auto lo = base_t::lower_bound({L, L});
        auto hi = base_t::upper_bound({R, inf});
        if (hi != base_t::begin()) {
            if (auto phi = prev(hi); phi->first[1] > R) {
                if (phi->second == color) { // extend new rightwards, removing old
                    R = phi->first[1];
                } else if (phi->first[0] < L) { // splice
                    auto [x, y] = phi->first;
                    auto red = phi->second;
                    processor(intv, red);
                    base_t::erase(phi);
                    base_t::emplace_hint(hi, run_t{x, L}, red);
                    base_t::emplace_hint(hi, run_t{L, R}, color);
                    base_t::emplace_hint(hi, run_t{R, y}, red);
                    return;
                } else { // cut old rightwards and don't remove it
                    if (phi->first[0] < R) {
                        processor(run_t{phi->first[0], R}, phi->second);
                        const_cast<T&>(phi->first[0]) = R;
                    }
                    hi = phi;
                }
            }
        }
        if (lo != base_t::begin()) {
            if (auto plo = prev(lo); plo->first[1] >= L) {
                if (plo->second == color) { // extend new leftwards, removing old
                    L = plo->first[0], lo = plo;
                } else if (plo->first[0] < L) { // cut old leftwards and don't remove it
                    if (plo->first[1] > L) {
                        processor(run_t{L, plo->first[1]}, plo->second);
                        const_cast<T&>(plo->first[1]) = L;
                    }
                } else { // just cut old
                    lo = plo;
                }
            }
        }
        for (auto it = lo; it != hi; ++it) {
            if (it->second != color) {
                processor(it->first, it->second);
            }
        }
        base_t::erase(lo, hi);
        base_t::emplace_hint(hi, intv, color);
    }

    template <typename Fn>
    void cut(run_t intv, Fn&& processor) {
        auto& [L, R] = intv;
        auto lo = base_t::lower_bound({L, L});
        auto hi = base_t::lower_bound({R, R});
        if (hi != base_t::begin()) {
            if (auto phi = prev(hi); phi->first[0] < L && phi->first[1] > R) { // splice
                auto [x, y] = phi->first;
                auto color = phi->second;
                processor(intv, color);
                base_t::erase(phi);
                base_t::emplace_hint(hi, run_t{x, L}, color);
                base_t::emplace_hint(hi, run_t{R, y}, color);
                return;
            } else if (phi->first[1] > R) { // cut old rightwards and don't remove it
                if (phi->first[0] < R) {
                    processor(run_t{phi->first[0], R}, phi->second);
                    const_cast<T&>(phi->first[0]) = R;
                }
                hi = phi;
            }
        }
        if (lo != base_t::begin()) {
            if (auto plo = prev(lo); plo->first[1] > L) { // cut old leftwards
                processor(run_t{L, plo->first[1]}, plo->second);
                const_cast<T&>(plo->first[1]) = L;
            }
        }
        for (auto it = lo; it != hi; ++it) {
            processor(it->first, it->second);
        }
        base_t::erase(lo, hi);
    }

    optional<run_t> get_run(T x) const {
        auto it = base_t::upper_bound({x, inf});
        if (it != base_t::begin() && prev(it)->first[0] <= x && x < prev(it)->first[1]) {
            return prev(it)->first;
        }
        return std::nullopt;
    }

    optional<V> get(T x) const {
        auto it = base_t::upper_bound({x, inf});
        if (it != base_t::begin() && prev(it)->first[0] <= x && x < prev(it)->first[1]) {
            return prev(it)->second;
        }
        return std::nullopt;
    }

    V& at(T x) { return prev(base_t::upper_bound({x, inf}))->second; }

    bool contains(T x) const { return get_run(x).has_value(); }

    bool contains(run_t intv) const {
        auto wrap = get_run(intv[0]);
        return wrap.has_value() && wrap->first[1] >= intv[1];
    }

    bool overlaps(run_t intv) const {
        auto lo = base_t::lower_bound({intv[0], intv[0]});
        return !(lo == base_t::end() || lo->first[0] >= intv[1]) ||
               !(lo == base_t::begin() || prev(lo)->first[1] <= intv[0]);
    }
};

// Based on Aeren's submission

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<array<int, 2>>> runs(N);
    for (int i = 0; i < M; i++) {
        int u, l, r;
        cin >> u >> l >> r, u--, l--;
        runs[u].push_back({l, r});
    }

    merging_interval_processor<int, pair<int, int>> mip;
    vector<pair<int, int>> score(N);

    int last = 0;

    for (int u = 0; u < N; u++) {
        pair<int, int> tag = {-1, -1};
        pair<int, int> best = {1, -1};
        for (auto [l, r] : runs[u]) {
            mip.write({l, r}, tag, [&](auto, auto old) {
                best = max(best, make_pair(old.first + 1, old.second));
            });
        }
        score[u] = best;
        if (score[last].first < score[u].first) {
            last = u;
        }
        best.second = u;
        for (auto [l, r] : runs[u]) {
            mip.at(l) = best;
        }
    }

    int K = 0;

    vector<int> keep(N, false);
    while (last != -1) {
        keep[last] = true;
        last = score[last].second;
        K++;
    }

    cout << N - K << endl;
    vector<int> rows;
    for (int u = 0; u < N; u++) {
        if (!keep[u]) {
            rows.push_back(u + 1);
        }
    }
    for (int i = 0; i < N - K; i++) {
        cout << rows[i] << " \n"[i + 1 == N - K];
    }
    return 0;
}