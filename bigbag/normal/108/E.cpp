#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 16, inf = 1111111111;

int n, m, l[max_n], r[max_n], used[max_n], P;
long long y, cnt, dp[1 << max_n], f[1 << max_n];
pair<int, int> a[111];
vector<int> g[max_n], rg[max_n], v, q;
vector<vector<int> > ans;

void update() {
    sort(a, a + m);
    int poz = 0;
    for (int i = 0; i < m;) {
        a[poz] = a[i];
        while (i < m && a[poz] == a[i]) {
            ++i;
        }
        ++poz;
    }
    m = poz;
    for (int i = 0; i < m; ++i) {
        if (a[i].first < a[i].second) g[a[i].first].push_back(a[i].second);
        if (a[i].first > a[i].second) rg[a[i].second].push_back(a[i].first);
    }
}

void rec(int poz) {
    if (poz == n) {
        ans.push_back(v);
        return;
    }
    int k[max_n];
    for (int i = l[poz]; i <= r[poz]; ++i) {
        if (used[i] == 0) {
            v[poz] = i;
            for (int j = 0; j < g[poz].size(); ++j) {
                k[g[poz][j]] = l[g[poz][j]];
            }
            for (int j = 0; j < rg[poz].size(); ++j) {
                k[rg[poz][j]] = r[rg[poz][j]];
            }
            for (int j = 0; j < g[poz].size(); ++j) {
                l[g[poz][j]] = max(l[g[poz][j]], i + 1);
            }
            for (int j = 0; j < rg[poz].size(); ++j) {
                r[rg[poz][j]] = min(r[rg[poz][j]], i - 1);
            }
            used[i] = 1;
            rec(poz + 1);
            used[i] = 0;
            for (int j = 0; j < g[poz].size(); ++j) {
                l[g[poz][j]] = k[g[poz][j]];
            }
            for (int j = 0; j < rg[poz].size(); ++j) {
                r[rg[poz][j]] = k[rg[poz][j]];
            }
        }
    }
}

bool get_bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

long long get_dp(int mask, int c) {
    if (f[mask]) {
        return dp[mask];
    }
    if ((mask + 1) == (1 << cnt)) {
        return 1;
    }
    f[mask] = 1;
    dp[mask] = 0;
    for (int i = 0; i < cnt; ++i) {
        int poz = P + i;
        if (get_bit(mask, i) == 0 && l[poz] <= q[c] && q[c] <= r[poz]) {
            int fff = 0;
            for (int j = 0; j < g[poz].size(); ++j) {
                if (g[poz][j] >= P && get_bit(mask, g[poz][j] - P)) {
                    fff = 1;
                    break;
                }
            }
            for (int j = 0; j < rg[poz].size(); ++j) {
                if (rg[poz][j] >= P && get_bit(mask, rg[poz][j] - P) == 0) {
                    fff = 1;
                    break;
                }
            }
            //cout << mask << " " << c << " " << q[c]
            if (fff == 0) {
                dp[mask] += get_dp(mask | (1 << i), c + 1);
            }
        }
    }
    //cout << mask << " " << c << " - " << dp[mask] << endl;
    return dp[mask];
}

long long get_cnt(int poz) {
    if (poz == n) {
        return 1;
    }
    q.clear();
    for (int i = 0; i < n; ++i) {
        if (used[i] == 0) {
            q.push_back(i);
        }
    }
    cnt = n - poz;
    memset(f, 0, sizeof(f));
    return get_dp(0, 0);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> y >> m;
    y -= 2000;
    for (int i = 0; i < m; ++i) {
        cin >> a[i].first >> a[i].second;
        --a[i].first;
        --a[i].second;
    }
    for (int i = 0; i < n; ++i) {
        l[i] = 0;
        r[i] = n - 1;
        v.push_back(0);
    }
    update();
    if (m >= 200) {
        rec(0);
        if (ans.size() >= y) {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < n; ++i) {
                cout << 1 + ans[y - 1][i] << " ";
            }
            cout << endl;
            return 0;
        }
        cout << "The times have changed" << endl;
        return 0;
    }
    int k[max_n];
    for (int i = 0; i < n; ++i) {
        P = i + 1;
        int FFF = 0;
        for (int x = l[i]; x <= r[i]; ++x) {
            if (used[x] == 0) {
                for (int j = 0; j < g[i].size(); ++j) {
                    k[g[i][j]] = l[g[i][j]];
                }
                for (int j = 0; j < rg[i].size(); ++j) {
                    k[rg[i][j]] = r[rg[i][j]];
                }
                for (int j = 0; j < g[i].size(); ++j) {
                    l[g[i][j]] = max(l[g[i][j]], x + 1);
                }
                for (int j = 0; j < rg[i].size(); ++j) {
                    r[rg[i][j]] = min(r[rg[i][j]], x - 1);
                }
                used[x] = 1;
                long long c = get_cnt(i + 1);
                //cout << y << " " << c << endl;
                if (y > c) {
                    y -= c;
                } else {
                    FFF = 1;
                    v[i] = x;
                    //cout <<i  << " " << x + 1 << " " << c << endl;
                    cout << x + 1 << " ";
                    break;
                }
                used[x] = 0;
                for (int j = 0; j < g[i].size(); ++j) {
                    l[g[i][j]] = k[g[i][j]];
                }
                for (int j = 0; j < rg[i].size(); ++j) {
                    r[rg[i][j]] = k[rg[i][j]];
                }
            }
        }
        if (FFF == 0) {
            cout << "The times have changed" << endl;
            return 0;
        }
    }
    return 0;
}