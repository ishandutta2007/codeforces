#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> cost(N);
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
    }
    int A, B;
    cin >> A;
    vector<int> a(A);
    for (int i = 0; i < A; i++) {
        cin >> a[i], a[i]--;
    }
    cin >> B;
    vector<int> b(B);
    for (int i = 0; i < B; i++) {
        cin >> b[i], b[i]--;
    }
    if (A < K || B < K || M < K) {
        cout << "-1\n";
        return 0;
    }
    sort(begin(a), end(a), [&](int i, int j) {
        return make_pair(cost[i], i) < make_pair(cost[j], j); //
    });
    sort(begin(b), end(b), [&](int i, int j) {
        return make_pair(cost[i], i) < make_pair(cost[j], j); //
    });
    static constexpr int NEITHER = 0, A_LIKES = 1, B_LIKES = 2, BOTH = 3;
    vector<int> likes(N);
    for (int x : a) {
        likes[x] += A_LIKES;
    }
    for (int x : b) {
        likes[x] += B_LIKES;
    }
    array<set<pair<int, int>>, 4> open = {}, pick = {};
    for (int i = 0; i < N; i++) {
        open[likes[i]].insert({cost[i], i});
    }
    int Ac = 0, Bc = 0;
    int64_t sum = 0;
    auto add = [&](int i) {
        pick[likes[i]].insert({cost[i], i});
        open[likes[i]].erase({cost[i], i});
        sum += cost[i];
        Ac += likes[i] == A_LIKES || likes[i] == BOTH;
        Bc += likes[i] == B_LIKES || likes[i] == BOTH;
    };
    auto rem = [&](int i) {
        pick[likes[i]].erase({cost[i], i});
        open[likes[i]].insert({cost[i], i});
        sum -= cost[i];
        Ac -= likes[i] == A_LIKES || likes[i] == BOTH;
        Bc -= likes[i] == B_LIKES || likes[i] == BOTH;
    };
    constexpr int inf = INT_MAX - 1e9;
    auto max_pick = [&](int l) {
        if (pick[l].empty()) {
            return make_pair(0, -1);
        } else {
            return *pick[l].rbegin();
        }
    };
    auto min_open = [&](int l) {
        if (open[l].empty()) {
            return make_pair(inf, -1);
        } else {
            return *open[l].begin();
        }
    };
    vector<int> order(N);
    iota(begin(order), end(order), 0);
    sort(begin(order), end(order), [&](int i, int j) {
        return make_pair(cost[i], i) < make_pair(cost[j], j); //
    });
    for (int i = 0; i < M; i++) {
        add(order[i]);
    }
    while (Ac < K) {
        // {NEITHER | B_LIKES} -> {A_LIKES | BOTH}
        // Pick the most expensive not liked by A, replace with cheapest liked by A
        int i = max(max_pick(NEITHER), max_pick(B_LIKES)).second;
        int j = min(min_open(A_LIKES), min_open(BOTH)).second;
        assert(i != -1 && j != -1);
        rem(i), add(j);
    }
    while (Bc < K) {
        if (Ac > K) {
            // {NEITHER | A_LIKES} -> {B_LIKES | BOTH}
            // Pick the most expensive over all, replace with cheapest liked by B
            int i = max(max_pick(NEITHER), max_pick(A_LIKES)).second;
            int j = min(min_open(B_LIKES), min_open(BOTH)).second;
            assert(i != -1 && j != -1);
            rem(i), add(j);
        } else {
            // {NEITHER} -> {B_LIKES | BOTH} or {A_LIKES} -> {BOTH}
            int i = max_pick(NEITHER).second;
            int j = min(min_open(B_LIKES), min_open(BOTH)).second;
            int k = max_pick(A_LIKES).second;
            int l = min_open(BOTH).second;
            assert(j != -1 && k != -1);
            if (i == -1 && l == -1) {
                cout << "-1\n";
                return 0;
            }
            int cij = i == -1 ? inf : cost[j] - cost[i];
            int ckl = l == -1 ? inf : cost[l] - cost[k];
            if (cij <= ckl) {
                rem(i), add(j);
            } else {
                rem(k), add(l);
            }
        }
    }
    while (true) {
        // {NEITHER and BOTH} -> {A_LIKES and B_LIKES}
        if (pick[NEITHER].size() && pick[BOTH].size()) {
            if (open[A_LIKES].size() && open[B_LIKES].size()) {
                int i = max_pick(NEITHER).second;
                int j = max_pick(BOTH).second;
                int k = min_open(A_LIKES).second;
                int l = min_open(B_LIKES).second;
                if (cost[k] + cost[l] < cost[i] + cost[j]) {
                    rem(i), rem(j);
                    add(k), add(l);
                    continue;
                }
            }
        }
        // {A_LIKES and B_LIKES} -> {NEITHER and BOTH}
        if (pick[A_LIKES].size() && pick[B_LIKES].size()) {
            if (open[NEITHER].size() && open[BOTH].size()) {
                int i = max_pick(A_LIKES).second;
                int j = max_pick(B_LIKES).second;
                int k = min_open(NEITHER).second;
                int l = min_open(BOTH).second;
                if (cost[k] + cost[l] < cost[i] + cost[j]) {
                    rem(i), rem(j);
                    add(k), add(l);
                    continue;
                }
            }
        }
        break;
    }
    cout << sum << '\n';
    return 0;
}