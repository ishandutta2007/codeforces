#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

void setmax(int64_t& a, int64_t b) { a = max(a, b); }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, C;
    cin >> N >> C;

    vector<int64_t> units(C + 1);
    for (int i = 0; i < N; i++) {
        int cost, damage, health;
        cin >> cost >> damage >> health;
        setmax(units[cost], 1LL * damage * health);
    }

    vector<int64_t> top(C + 1);
    for (int c = 1; c <= C; c++) {
        if (auto P = units[c]) {
            for (int k = 1; c * k <= C; k++) {
                setmax(top[c * k], P * k);
            }
        }
    }
    for (int c = 1; c <= C; c++) {
        setmax(top[c], top[c - 1]);
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int damage;
        int64_t health;
        cin >> damage >> health;
        int c = lower_bound(begin(top), end(top), 1 + damage * health) - begin(top);
        cout << (c > C ? -1 : c) << " \n"[i + 1 == M];
    }

    return 0;
}