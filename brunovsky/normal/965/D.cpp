#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

auto solve() {
    int l, w;
    cin >> w >> l;
    vector<int> A(w);
    vector<int> prefix(w);
    for (int i = 1; i < w; i++) {
        cin >> A[i];
        prefix[i] = prefix[i - 1] + A[i];
    }
    // prefix[d]: stones in spots [1..d].
    int ans = prefix[w - 1];
    for (int i = 1, r = l; r < w; i++, r++) {
        ans = min(ans, prefix[r] - prefix[i - 1]);
    }
    return ans;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}