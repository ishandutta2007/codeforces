/**
 *  created: 30/05/2021, 18:12:02
**/

#include <bits/stdc++.h>

using namespace std;

const int seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 generator(seed);

int rnd() {
    return generator() >> 1;
}

int rnd(int r) {
    return rnd() % r;
}

const int max_n = 200222, inf = 1000111222;
const int max_m = 66;
const int max_mask = 1 << 15;

int n, m, p, dp[max_mask];
char s[max_n][max_m];

bool get_bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
    }
    vector<int> ans;
    for (int it = 0; it < 30; ++it) {
        int id = rnd(n);
        vector<int> v;
        for (int i = 0; i < m; ++i) {
            if (s[id][i] == '1') {
                v.push_back(i);
            }
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            int mask = 0;
            for (int j = 0; j < v.size(); ++j) {
                if (s[i][v[j]] == '1') {
                    mask += 1 << j;
                }
            }
            //cout << "#" << mask << " " << v.size() << " " << id << endl;
            ++dp[mask];
        }
        //cout << endl;
        for (int i = 0; i < v.size(); ++i) {
            for (int mask = 0; mask < (1 << v.size()); ++mask) {
                if (get_bit(mask, i)) {
                    dp[mask ^ (1 << i)] += dp[mask];
                }
            }
        }
        int res = 0;
        for (int mask = 0; mask < (1 << v.size()); ++mask) {
            if (dp[mask] >= (n + 1) / 2) {
                if (__builtin_popcount(res) < __builtin_popcount(mask)) {
                    res = mask;
                }
            }
        }
        if (ans.size() < __builtin_popcount(res)) {
            ans.clear();
            for (int i = 0; i < v.size(); ++i) {
                if (get_bit(res, i)) {
                    ans.push_back(v[i]);
                }
            }
        }
    }
    string q(m, '0');
    for (int x : ans) {
        q[x] = '1';
    }
    puts(q.c_str());
    return 0;
}