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

const int max_n = 2022, sz = 25, inf = 1111111111;

int n, m, k, q, f[max_n], l[max_n], r[max_n], a[max_n][max_n], num[max_n][max_n];
char s[11];
long long res[max_n / sz + 5][max_n / sz + 5];
vector<pair<pair<int, int>, long long> > id[max_n], Q;

inline int get_id(int x) {
    return x / sz;
}

inline void build() {
    for (int i = 0; i < max_n; ++i) {
        l[i] = i * sz;
        r[i] = (i + 1) * sz - 1;
    }
}

void intersect(int &lx, int &rx, int l1, int r1, int l2, int r2) {
    if (l1 > l2) {
        swap(l1, l2);
        swap(r1, r2);
    }
    if (l2 > r1) {
        lx = rx = -1;
        return;
    }
    lx = l2;
    rx = min(r1, r2);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    build();
    for (int i = 0; i < k; ++i) {
        f[i] = 1;
        int cnt;
        scanf("%d", &cnt);
        Q.clear();
        while (cnt--) {
            int x, y, d;
            scanf("%d%d%d", &x, &y, &d);
            --x;
            --y;
            a[x][y] = d;
            num[x][y] = i;
            Q.push_back(make_pair(make_pair(get_id(x), get_id(y)), d));
        }
        sort(Q.begin(), Q.end());
        for (int j = 0; j < Q.size(); ++j) {
            pair<pair<int, int>, long long> p = Q[j];
            while (j + 1 < Q.size() && Q[j].first == Q[j + 1].first) {
                ++j;
                p.second += Q[j].second;
            }
            id[i].push_back(p);
        }
        for (int j = 0; j < id[i].size(); ++j) {
            res[id[i][j].first.first][id[i][j].first.second] += id[i][j].second;
        }
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%s", s);
        if (s[0] == 'S') {
            int num;
            scanf("%d", &num);
            --num;
            if (f[num] == 1) {
                for (int i = 0; i < id[num].size(); ++i) {
                    res[id[num][i].first.first][id[num][i].first.second] -= id[num][i].second;
                }
                f[num] = 0;
            } else {
                for (int i = 0; i < id[num].size(); ++i) {
                    res[id[num][i].first.first][id[num][i].first.second] += id[num][i].second;
                }
                f[num] = 1;
            }
        } else {
            int lx, ly, rx, ry;
            int llx, lly, rrx, rry;
            scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
            --lx;
            --rx;
            --ly;
            --ry;
            long long ans = 0;
            for (int i = 0; l[i] < n; ++i) {
                for (int j = 0; l[j] < m; ++j) {
                    if (lx <= l[i] && r[i] <= rx && ly <= l[j] && r[j] <= ry) {
                        ans += res[i][j];
                    } else {
                        intersect(llx, rrx, l[i], r[i], lx, rx);
                        intersect(lly, rry, l[j], r[j], ly, ry);
                        if (llx == -1 || lly == -1) {
                            continue;
                        }
                        for (int x = llx; x <= rrx; ++x) {
                            for (int y = lly; y <= rry; ++y) {
                                if (f[num[x][y]]) {
                                    //cout << x << " " << y << " : " << a[x][y] << endl;
                                    ans += a[x][y];
                                }
                            }
                        }
                    }
                }
            }
            printf("%I64d\n", ans);
        }
    }
    return 0;
}