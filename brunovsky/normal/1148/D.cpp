#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i], a[i]--, b[i]--;
    }
    vector<array<int, 2>> where(2 * N);
    for (int i = 0; i < N; i++) {
        where[a[i]] = {i, 0};
        where[b[i]] = {i, 1};
    }
    vector<int> ups, downs;
    for (int i = 0; i < N; i++) {
        if (a[i] < b[i]) {
            ups.push_back(i);
        } else {
            downs.push_back(i);
        }
    }
    sort(begin(ups), end(ups), [&](int i, int j) { return a[i] > a[j]; });
    sort(begin(downs), end(downs), [&](int i, int j) { return a[i] < a[j]; });
    if (ups.size() > downs.size()) {
        int S = ups.size();
        cout << S << '\n';
        for (int i = 0; i < S; i++) {
            cout << ups[i] + 1 << " \n"[i + 1 == S];
        }
    } else {
        int S = downs.size();
        cout << S << '\n';
        for (int i = 0; i < S; i++) {
            cout << downs[i] + 1 << " \n"[i + 1 == S];
        }
    }
    return 0;
}