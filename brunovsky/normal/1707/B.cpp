#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#include "code/random.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

struct Run {
    int value, count;
    Run(int value, int count) : value(value), count(count) {}
    friend bool operator<(Run x, Run y) { return x.value < y.value; }
    friend string to_string(Run x) {
        return "(" + to_string(x.value) + ',' + to_string(x.count) + ")";
    }
};

auto make_runs(const vector<int>& a) {
    vector<Run> runs;
    for (int l = 0, r = 1, N = a.size(); l < N; l = r++) {
        while (r < N && a[l] == a[r])
            r++;
        runs.emplace_back(a[l], r - l);
    }
    return runs;
}

auto merge_runs(const vector<Run>& a) {
    vector<Run> runs;
    for (int l = 0, r = 1, N = a.size(); l < N; l = r++) {
        int s = a[l].count;
        while (r < N && a[l].value == a[r].value)
            s += a[r++].count;
        runs.emplace_back(a[l].value, s);
    }
    return runs;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
#ifdef LOCAL
        int N = rand_unif<int>(1, 100'000);
        auto a = rands_unif<int>(N, 1, 500'000);
        sort(begin(a), end(a));
#else
        int N;
        cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
#endif
        if (N == 1) {
            cout << a[0] << '\n';
            continue;
        }
        auto b = make_runs(a);
        int B = b.size();
        while (B > 1 || b[0].count > 1) {
            vector<Run> c;
            for (int i = 0; i < B; i++) {
                if (b[i].count > 1) {
                    c.emplace_back(0, b[i].count - 1);
                }
                if (i + 1 < B) {
                    c.emplace_back(b[i + 1].value - b[i].value, 1);
                }
            }
            sort(begin(c), end(c));
            c = merge_runs(c);
            swap(b, c);
            B = b.size();
        }
        int got = b[0].value;
        cout << got << '\n';
    }
    return 0;
}