#include <bits/stdc++.h>

using namespace std;

#define long int64_t
#define DV(a) (" [" #a "=" + to_string(a) + "]")

// *****

long solve() {
    int N;
    string s;
    cin >> N >> s;
    vector<int> sheep;
    for (int i = 0; i < N; i++) {
        if (s[i] == '*') {
            sheep.push_back(i);
        }
    }
    int S = sheep.size();
    long ans = 0;
    for (int i = 0; i + 1 < S; i++) {
        ans += 1LL * (sheep[i + 1] - sheep[i] - 1) * min(i + 1, S - (i + 1));
    }
    return ans;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        cout << solve() << endl;
    }
    return 0;
}