#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#include "code/random.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

auto choose3(int n) { return n * (n - 1) * (n - 2) / 6; }

#ifdef LOCAL

vector<int> orig, secret;

auto compute() {
    int N = secret.size() - 1;
    int U = 0, V = 0;
    for (int v = 1; v <= N; v++) {
        U += choose3(secret[v]);
    }
    for (int u = 3; u <= N; u++) {
        V += secret[u - 2] * secret[u - 1] * secret[u];
    }
    return make_pair(U, V);
}

auto ADD(int x) {
    secret[x]++;
    return compute();
}

void ANSWER(const vector<int>& answ) {
    if (answ != orig) {
        debug(answ);
        debug(orig);
    }
}

auto make_secret() {
    int N = rand_unif<int>(4, 10);
    secret = rands_unif<int>(N + 1, 0, 5);
    secret[0] = 0;
    orig = secret;
    auto [U, V] = compute();
    return make_tuple(N, U, V);
}

#else

auto ADD(int x) {
    cout << "+ " << x << endl;
    int triplets, straights;
    cin >> triplets >> straights;
    return make_pair(triplets, straights);
}

void ANSWER(const vector<int>& a) {
    int N = a.size() - 1;
    cout << "!";
    for (int i = 1; i <= N; i++) {
        cout << ' ' << a[i];
    }
    cout << endl;
    exit(0);
}

auto make_secret() {
    int N, U, V;
    cin >> N >> U >> V;
    return make_tuple(N, U, V);
}

#endif

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, U, V;
    tie(N, U, V) = make_secret();

    vector<int> a(N + 1);

    map<int, int> increment;
    for (int a = 1; a <= N + 5; a++) {
        int v = choose3(a + 1) - choose3(a);
        assert(!increment.count(v));
        increment[v] = a;
    }

    vector<array<int, 2>> delta(N + 1);
    delta[N] = {U, V};

    auto insert = [&](int i) {
        auto [u, v] = ADD(i);
        delta[i] = {u - U, v - V};
        U = u, V = v;
    };

    for (int i = N - 1; i >= 3; i--) {
        insert(i);
    }
    insert(1);
    insert(2);
    auto [_, b] = delta[1];
    auto [c, d] = delta[2];
    insert(1);
    auto [u, v] = delta[1];

    a[1] = u == 0 ? 0 : increment.at(u) - 1;
    a[3] = v - b - 1;
    a[2] = b / (a[3] + 1);
    a[4] = d / (a[3] + 1) - a[1] - 1 - (N > 4);

    for (int i = 5; i <= N; i++) {
        int f = delta[i - 2][1] - a[i - 4] * a[i - 3];
        a[i] = f / (a[i - 1] + 1) - a[i - 3] - (i < N);
    }

    ANSWER(a);
    return 0;
}