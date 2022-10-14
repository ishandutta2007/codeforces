#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

auto solve() {
    int N;
    cin >> N;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    vector<int> index(N);
    iota(begin(index), end(index), 1);
    sort(begin(index), end(index), [&](int a, int b) { return A[a] > A[b]; });

    set<int> forgot;
    forgot.insert(0), forgot.insert(N + 1);

    map<int, int> lengths;
    lengths[N] = 1;

    vector<int> ans(N + 1); // ans[i]: length i+1
    int prevlen = N;

    while (!index.empty()) {
        int r = index.size() - 1, v = A[index[r]];
        int l = r;
        while (l > 0 && A[index[l - 1]] == v)
            l--;

        // eliminate [l..r]
        for (int i = l; i <= r; i++) {
            auto it = forgot.insert(index[i]).first;
            int left = *prev(it), right = *next(it);
            int before = index[i] - left - 1, after = right - index[i] - 1;
            int len = right - left - 1;
            lengths[len]--;
            lengths[before]++, lengths[after]++;
            if (lengths[len] == 0) {
                lengths.erase(len);
            }
        }

        int maxlen = lengths.rbegin()->first;
        for (int i = maxlen + 1; i <= prevlen; i++) {
            ans[i] = v;
        }
        prevlen = maxlen;
        index.erase(begin(index) + l, end(index));
    }
    assert(prevlen == 0);

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << "\n "[i < N];
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}