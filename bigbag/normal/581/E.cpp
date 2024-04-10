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

const int max_n = 422222, inf = 1111111111;
const int max_lev = 20;

int fin, s, n, m, num[max_n], nxt[max_n], qqq[max_n];
pair<int, int> p[max_n], dp[max_n];
pair<int, int> maxs[max_lev][max_n];

void get_all_maxs(int n) {
    for (int i = 0; i < n; ++i) {
        maxs[0][i] = make_pair(p[i].second, -i);
    }
    for (int i = 1; i < max_lev; ++i) {
        for (int j = 0; j < n && j + (1 << (i - 1)) < n; ++j) {
            maxs[i][j] = max(maxs[i - 1][j], maxs[i - 1][j + (1 << (i - 1))]);
        }
    }
    for (int i = 1, x = 0; i <= n; i *= 2, ++x) {
        for (int j = i; j <= n && j < i * 2; ++j) {
            num[j] = x;
        }
    }
}

pair<int, int> get_max(int l, int r) {
    if (l > r) {
        return make_pair(-inf, 0);
    }
    int lev = num[r - l + 1];
    pair<int, int> p = max(maxs[lev][l], maxs[lev][r - (1 << lev) + 1]);
    p.second *= -1;
    return p;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d", &fin, &s, &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &p[i].second, &p[i].first);
    }
    for (int i = n; i < n + m; ++i) {
        scanf("%d", &p[i].first);
        qqq[i - n] = p[i].first;
        p[i].second = 0;
    }
    sort(p, p + n + m);
    get_all_maxs(n + m);
    int p2 = -1, p3 = -1;
    /*for (int i = 0; i < n + m; ++i) {
        cout << p[i].first << " " << p[i].second << endl;
    }
    cout << endl;*/
    for (int i = n + m - 1; i >= 0; --i) {
        nxt[i] = -1;
        if (p[i].second == 1) {
            if (p2 == -1) {
                nxt[i] = p3;
            } else if (p3 == -1) {
                nxt[i] = p2;
            } else {
                nxt[i] = min(p2, p3);
            }
        }
        if (p[i].second == 2) {
            nxt[i] = p3;
        }
        if (p[i].second == 2) {
            p2 = i;
        }
        if (p[i].second == 3) {
            p3 = i;
        }
    }
    for (int i = n + m - 1; i >= 0; --i) {
        if (p[i].first + s >= fin) {
            dp[i] = make_pair(0, 0);
            continue;
        }
        int l = i, r = n + m;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (p[mid].first <= p[i].first + s) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (l == i) {
            dp[i] = make_pair(-1, -1);
        }
        if (l > i) {
            pair<int, int> mx = get_max(i + 1, l);
            //cout << i << " " << l << "   " << mx.first << " " << mx.second << endl;
            if (mx.first == 0 || dp[mx.second] == make_pair(-1, -1)) {
                dp[i] = make_pair(-1, -1);
            } else {
                if (mx.first == 1) {
                    int to = p[mx.second].first;
                    int poz2 = nxt[mx.second];
                    if (poz2 == -1 || to + s < p[poz2].first) {
                        dp[i] = dp[mx.second];
                        if (to + s >= fin) {
                            dp[i].first += max(0, fin - p[i].first - s);
                        } else {
                            dp[i].first += to - p[i].first;
                        }
                        if (dp[mx.second] == make_pair(-1, -1)) dp[i] = make_pair(-1, -1);
                    } else {
                        int q = s;
                        int to2 = p[poz2].first;
                        q -= (to2 - p[i].first);
                        q *= -1;
                        dp[i].first += q;
                        int poz3 = nxt[poz2];
                        if (poz3 == -1 || to2 + s < p[poz3].first) {
                            if (p[poz2].second == 2) {
                                if (to2 + s >= fin) {
                                    dp[i].second += max(0, fin - to2);
                                } else {
                                    dp[i].second += s;
                                }
                            }
                            dp[i].first += dp[poz2].first;
                            dp[i].second += dp[poz2].second;
                            if (dp[poz2] == make_pair(-1, -1)) dp[i] = make_pair(-1, -1);
                        } else {//@#@
                            dp[i].second += p[poz3].first - to2;
                            dp[i].first += dp[poz3].first;
                            dp[i].second += dp[poz3].second;
                            if (dp[poz3] == make_pair(-1, -1)) dp[i] = make_pair(-1, -1);
                        }
                    }
                }
                if (mx.first == 2) {
                    int to = p[mx.second].first;
                    int poz2 = nxt[mx.second];
                    if (poz2 == -1 || to + s < p[poz2].first) {
                        dp[i] = dp[mx.second];
                        if (to + s >= fin) {
                            dp[i].second += max(0, fin - s - p[i].first);
                        } else {
                            dp[i].second += to - p[i].first;
                        }
                        if (dp[mx.second] == make_pair(-1, -1)) dp[i] = make_pair(-1, -1);
                    } else {
                        int q = s;
                        int to2 = p[poz2].first;
                        q -= (to2 - p[i].first);
                        q *= -1;
                        dp[i].second += q;
                        dp[i].first += dp[poz2].first;
                        dp[i].second += dp[poz2].second;
                        if (dp[poz2] == make_pair(-1, -1)) dp[i] = make_pair(-1, -1);
                    }
                }
                if (mx.first == 3) {
                    dp[i] = dp[mx.second];
                }
            }
        }
    }
    /*for (int i = 0; i < n + m; ++i) {
        cout << dp[i].first << " " << dp[i].second << endl;
    }
    cout << endl;*/
    for (int i = 0; i < m; ++i) {
        int l = 0, r = n + m;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (p[mid].first <= qqq[i]) {
                l = mid;
            } else {
                r = mid;
            }
        }
        printf("%d %d\n", dp[l].first, dp[l].second);
    }
    return 0;
}