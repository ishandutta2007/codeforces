#include <bits/stdc++.h>

using namespace std;


const int BITS = 30;
const int BITS_FULL = 32;
const int MOD = 998244353;


int getBitValue(int x, int bit) {
    return (x & (1 << bit)) != 0;
}

array <vector <int>, 2> splitByBit(int bit, const vector <int> &values) {
    array <vector <int>, 2> groups;
    for (int v : values) {
        groups[getBitValue(v, bit)].push_back(v);
    }

    return groups;
}

void fix(int &x) {
    if (x >= MOD) {
        x -= MOD;
    }
}

int numSubsets(int m) {
    int ans = 1;
    while (m--) {
        ans *= 2;
        fix(ans);
    }

    ans += MOD - 1;
    fix(ans);

    return ans;
}

int solveBipartite(int bit, int k, const array <vector <int>, 2> &values) {
    if (bit == -1 || values[0].empty() || values[1].empty()) {
        return numSubsets(values[0].size() + values[1].size());
    }

    array <array<vector <int>, 2>, 2> valuesSplit;
    for (int b = 0; b < 2; b++) {
        valuesSplit[b] = splitByBit(bit, values[b]);
    }

    if (getBitValue(k, bit) == 0) {
        int ans = (
            solveBipartite(bit - 1, k, {valuesSplit[0][0], valuesSplit[1][0]}) +
            solveBipartite(bit - 1, k, {valuesSplit[0][1], valuesSplit[1][1]})
        );

        fix(ans);

        for (int t = 0; t <= 1; t++) {
            ans += numSubsets(values[t].size());
            fix(ans);

            ans += MOD - numSubsets(valuesSplit[t][0].size());
            fix(ans);

            ans += MOD - numSubsets(valuesSplit[t][1].size());
            fix(ans);
        }

        return ans;
    } else {
        int ans1 = solveBipartite(bit - 1, k, {valuesSplit[0][0], valuesSplit[1][1]});
        int ans2 = solveBipartite(bit - 1, k, {valuesSplit[0][1], valuesSplit[1][0]});
        return ((long long) (ans1 + 1) * (ans2 + 1) - 1) % MOD;
    }
}

int solve(int k, const vector <int> &values) {
    if (k == 0) {
        map <int,int> cnt;
        for (int v : values) {
            cnt[v]++;
        }

        int ans = 0;
        for (auto &e : cnt) {
            ans += numSubsets(e.second);
            fix(ans);
        }

        return ans;
    }

    int prefMask = 0;
    for (int i = 1; i <= __builtin_clz(k); i++) {
        prefMask |= 1 << (BITS_FULL - i);
    }

    map <int,vector<int>> valuesByPref;
    for (int v : values) {
        int pref = v & prefMask;
        valuesByPref[pref].push_back(v ^ pref);
    }

    int leadingBit = BITS_FULL - 1 - __builtin_clz(k);
    int ans = 0;

    for (auto &e : valuesByPref) {
        ans += solveBipartite(leadingBit - 1, k, splitByBit(leadingBit, e.second));
        fix(ans);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector <int> values(n);
    for (int &v : values) {
        cin >> v;
    }

    cout << solve(k, values) << '\n';

    return 0;
}