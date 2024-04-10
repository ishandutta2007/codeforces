#include <bits/stdc++.h>

using namespace std;

// *****
template <typename T>
string to_string(const vector<T>& v) {
    string s;
    for (const auto& el : v)
        s += to_string(el) + " ";
    return s.empty() ? s : (s.pop_back(), s);
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    return out << to_string(v) << endl;
}

auto solve() {
    int N;
    cin >> N;
    vector<int> A(N + 1);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    A[N] = A[0];

    vector<int> next(N), prev(N);
    for (int i = 0; i < N; i++)
        prev[i] = i - 1, next[i] = i + 1;
    prev[0] = N - 1, next[N - 1] = 0;

    vector<int> G(N);
    for (int i = 0; i < N; i++)
        G[i] = gcd(A[i], A[prev[i]]);

    set<int> ones;
    for (int i = 0; i < N; i++)
        if (G[i] == 1)
            ones.insert(i);

    vector<int> removed;

    int i = 0;
    while (!ones.empty()) {
        auto it = ones.lower_bound(next[i]);
        i = it == ones.end() ? *ones.begin() : *it;
        ones.erase(i), ones.erase(next[i]);
        removed.push_back(i);

        next[prev[i]] = next[i], prev[next[i]] = prev[i];
        G[next[i]] = gcd(A[prev[i]], A[next[i]]);
        if (i != next[i] && G[next[i]] == 1)
            ones.insert(next[i]);

        i = next[i];
    }

    cout << removed.size();
    for (int n : removed)
        cout << ' ' << (n + 1);
    cout << endl;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        solve();
    }
    return 0;
}