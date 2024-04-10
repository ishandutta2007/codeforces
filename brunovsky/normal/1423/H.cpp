#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

struct disjoint_set_rollback {
    int N, S;
    vector<int> nxt;
    vector<pair<int, int>> hist;

    explicit disjoint_set_rollback(int N = 0) : N(N), S(N), nxt(N, -1) {}

    void assign(int n) { *this = disjoint_set_rollback(n); }
    void reset() { *this = disjoint_set_rollback(N); }
    bool same(int i, int j) { return find(i) == find(j); }
    bool unit(int i) { return nxt[i] == -1; }
    bool root(int i) { return nxt[i] < 0; }
    int size(int i) { return -nxt[find(i)]; }
    int time() const { return hist.size(); }

    void rollback(int t) {
        int i = time();
        while (i > t) {
            i--, nxt[hist[i].first] = hist[i].second;
            i--, nxt[hist[i].first] = hist[i].second;
            S++;
        }
        hist.resize(t);
    }

    int find(int i) {
        while (nxt[i] >= 0) {
            i = nxt[i];
        }
        return i;
    }

    bool join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (size(i) < size(j)) {
                swap(i, j);
            }
            hist.emplace_back(i, nxt[i]);
            hist.emplace_back(j, nxt[j]);
            nxt[i] += nxt[j];
            nxt[j] = i, S--;
            return true;
        }
        return false;
    }
};

template <typename E, typename Insert, typename Rollback>
struct undo_stack_to_queue {
    Insert inserter;
    Rollback rollbacker;
    vector<pair<int, E>> stack; // A=1, B=0
    int A = 0, S = 0;

    undo_stack_to_queue(const Insert& insert, const Rollback& rollback)
        : inserter(insert), rollbacker(rollback) {}

    void push(E elem) {
        stack.emplace_back(0, elem), S++;
        inserter(elem);
    }

    void pop() {
        if (stack.back().first == 1) {
            stack.pop_back(), A--, S--;
            rollbacker();
            return;
        } else if (A == 0) {
            for (int i = 0; i < S; i++) {
                rollbacker();
            }
            reverse(begin(stack), end(stack));
            for (int i = 0; i < S; i++) {
                stack[i].first = 1, A++;
                inserter(stack[i].second);
            }
            stack.pop_back(), A--, S--;
            rollbacker();
        } else {
            int D = 0; // Bs - As
            vector<pair<int, E>> popped[2] = {};
            do {
                int t = stack.back().first;
                popped[t].push_back(stack.back()), stack.pop_back();
                rollbacker();
                A -= t, D += t ? -1 : +1;
            } while (stack.size() && A > 0 && D > 0);
            while (popped[0].size()) {
                stack.push_back(popped[0].back()), popped[0].pop_back();
                inserter(stack.back().second);
            }
            while (popped[1].size()) {
                stack.push_back(popped[1].back()), popped[1].pop_back(), A++;
                inserter(stack.back().second);
            }
            stack.pop_back(), A--, S--;
            rollbacker();
        }
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q, K;
    cin >> N >> Q >> K;
    vector<int> times;
    list<int> days;
    disjoint_set_rollback dsu(N);
    auto insert = [&](auto uv) {
        times.push_back(dsu.time());
        dsu.join(uv[0], uv[1]);
    };
    auto rollback = [&]() {
        dsu.rollback(times.back());
        times.pop_back();
    };
    undo_stack_to_queue<array<int, 2>, decltype(insert), decltype(rollback)> undo(
        insert, rollback);

    int day = 0;
    while (Q--) {
        if (int t; cin >> t, t == 1) {
            int x, y;
            cin >> x >> y, x--, y--;
            undo.push({x, y});
            days.push_back(day);
        } else if (t == 2) {
            int x;
            cin >> x, x--;
            cout << dsu.size(x) << '\n';
        } else if (t == 3) {
            day++;
            while (days.size() && day - days.front() == K) {
                undo.pop();
                days.pop_front();
            }
        } else {
            assert(false);
        }
    }

    return 0;
}