#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

constexpr int A = 26;
int N, K;
string s, ans;
int cnt[A], blocks;

bool construct(int i) {
    if (i == N) {
        return true;
    }
    int c = s[i] - 'a';
    if (cnt[c] == 0 && K * blocks < N) {
        cnt[c] = K, blocks++;
        ans[i] = 'a' + c, cnt[c]--;
        if (construct(i + 1)) {
            return true;
        }
        cnt[c] = 0, blocks--;
    } else if (cnt[c] > 0) {
        ans[i] = 'a' + c, cnt[c]--;
        if (construct(i + 1)) {
            return true;
        }
        cnt[c]++;
    }
    if (c + 1 == A) {
        return false;
    }
    int x = c + 1;
    if (cnt[x] == 0 && K * blocks < N) {
        cnt[x] = K, blocks++;
        ans[i++] = 'a' + x, cnt[x]--;
    } else if (cnt[x] > 0) {
        ans[i++] = 'a' + x, cnt[x]--;
    } else {
        bool found = false;
        for (int d = c + 1; d < 26 && !found; d++) {
            if (cnt[d] > 0) {
                ans[i++] = 'a' + d, cnt[d]--, found = true;
            }
        }
        if (!found) {
            return false;
        }
    }
    while (K * blocks < N) {
        cnt[0] += K, blocks++;
    }
    for (int d = 0; d < A; d++) {
        while (cnt[d]--) {
            ans[i++] = 'a' + d;
        }
    }
    assert(i == N);
    return true;
}

auto solve() {
    cin >> N >> K >> s;
    if (N % K != 0) {
        return "-1"s;
    }
    if (K == 1) {
        return s;
    }

    blocks = 0;
    memset(cnt, 0, sizeof(cnt));
    ans.assign(N, '\0');

    bool ok = construct(0);
    if (ok) {
        return ans;
    } else {
        return "-1"s;
    }
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