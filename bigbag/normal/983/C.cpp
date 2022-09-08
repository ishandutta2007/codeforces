#include <bits/stdc++.h>

using namespace std;

const int max_n = 2022, inf = 1000111222;
const int floors = 9;
const int max_x = 2000222;
const int masks = 733;

ostream& operator << (ostream &os, const std::vector<char> &v) {
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        if (i) {
            os << ", ";
        }
        os << (int) v[i];
    }
    os << "]";
    return os;
}

int num[max_x], can_enter[max_x];
int n, from[max_n], to[max_n], dp[max_n][masks][floors];
int pos[max_n][floors];
vector<char> g[floors], v;
vector<vector<char>> all;
vector<int> id[floors];

int get_mask(const vector<char> &v) {
    int res = 0;
    for (int x : v) {
        res = res * 5 + x;
    }
    return res;
}

void gen(int pos, int sum) {
    if (pos == 9) {
        num[get_mask(v)] = all.size();
        can_enter[all.size()] = sum;
        all.push_back(v);
        return;
    }
    for (int x = 0; x <= sum; ++x) {
        v[pos] = x;
        gen(pos + 1, sum - x);
    }
}

void update(int a, int b, int c, int x) {
    dp[a][b][c] = min(dp[a][b][c], x);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &from[i], &to[i]);
        --from[i];
        --to[i];
        g[from[i]].push_back(to[i]);
        for (int j = 0; j < floors; ++j) {
            pos[i][j] = pos[i - 1][j];
        }
        ++pos[i][from[i]];
        id[from[i]].push_back(i);
    }
    v.resize(9);
    gen(0, 4);
    memset(dp, 127, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int mask = all.size() - 1; mask >= 0; --mask) {
            for (int f = 0; f + 1 < floors; ++f) {
                dp[i][mask][f + 1] = min(dp[i][mask][f + 1], dp[i][mask][f] + 1);
            }
            for (int f = floors - 1; f > 0; --f) {
                dp[i][mask][f - 1] = min(dp[i][mask][f - 1], dp[i][mask][f] + 1);
            }
            for (int f = 0; f < floors; ++f) {
                if (dp[i][mask][f] > inf) {
                    continue;
                }
                vector<char> cur = all[mask];
                int can = can_enter[mask] + cur[f];
                //cout << i << " " << all[mask] << " " << f << ": " << dp[i][mask][f] << "   " << can << endl;
                cur[f] = 0;
                int j = i + 1;
                int cur_pos = pos[i][f];
                //cout << i << " " << mask << " " << f << " -> " << j << " " << cur_pos << endl;
                while (j <= n && cur_pos < id[f].size() && id[f][cur_pos] == j && can > 0) {
                    --can;
                    //cout << "#" << to[j] << endl;
                    ++cur[to[j]];
                    ++j;
                    ++cur_pos;
                }
                //cout << "-> " << cur << endl;
                update(j - 1, num[get_mask(cur)], f, dp[i][mask][f]);
            }
        }
    }
    int ans = inf;
    for (int i = 0; i < floors; ++i) {
        ans = min(ans, dp[n][0][i]);
    }
    printf("%d\n", 2 * n + ans);
    return 0;
}