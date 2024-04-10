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

const int max_n = 111111;
const long long inf = 1111111111111111111LL;
const int dx[] = {1, 1, -1, -1};
const int dy[] = {1, -1, -1, 1};

int n, m, k;
long long res[2 * max_n][2][2];
set<pair<int, int> > all;

void update(int x, int y, int tp, long long tm) {
    int num, f;
    if (tp == 0 || tp == 2) {
        num = x - y + max_n;
        f = 0;
    } else {
        num = x + y;
        f = 1;
    }
    if (tp == 0) {
        res[num][f][0] = min(res[num][f][0], tm);
    } else if (tp == 2) {
        res[num][f][1] = min(res[num][f][1], tm);
    } else if (tp == 1) {
        res[num][f][0] = min(res[num][f][0], tm);
    } else if (tp == 3) {
        res[num][f][1] = min(res[num][f][1], tm);
    }
}

bool is_in(int x, int y) {
    return 0 <= x && 0 <= y && x <= n && y <= m;
}

int get(int x, int y, int tp) {
    int l = 0, r = max_n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (is_in(x + mid * dx[tp], y + mid * dy[tp])) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < 2 * max_n; ++i) {
        res[i][0][0] = inf;
        res[i][0][1] = inf;
        res[i][1][0] = inf;
        res[i][1][1] = inf;
    }
    scanf("%d%d%d", &n, &m, &k);
    all.insert(make_pair(0, 0));
    pair<int, pair<int, int> > q = make_pair(0, make_pair(0, 0));
    long long tm = 0;
    while (true) {
        int x = q.first, y = q.second.first, tp = q.second.second;
        //cout << x << " " << y << " " << tp << endl;
        update(x, y, tp, tm);
        int nx, ny, ntp;
        int l = 0, r = max_n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (is_in(x + mid * dx[tp], y + mid * dy[tp])) {
                l = mid;
            } else {
                r = mid;
            }
        }
        nx = x + l * dx[tp];
        ny = y + l * dy[tp];
        tm += l;
        if (nx == n && ny == m) {
            ntp = 2;
        } else if (nx == n && ny == 0) {
            ntp = 3;
        } else if (nx == 0 && ny == m) {
            ntp = 1;
        } else if (nx == 0 && ny == 0) {
            ntp = 0;
        } else {
            if (ny == m) {
                if (tp == 0) {
                    ntp = 1;
                } else if (tp == 3) {
                    ntp = 2;
                }
            } else if (ny == 0) {
                if (tp == 1) {
                    ntp = 0;
                } else if (tp == 2) {
                    ntp = 3;
                }
            } else if (nx == n) {
                if (tp == 0) {
                    ntp = 3;
                } else if (tp == 1) {
                    ntp = 2;
                }
            } else if (nx == 0) {
                if (tp == 3) {
                    ntp = 0;
                } else if (tp == 2) {
                    ntp = 1;
                }
            }
        }
        if (all.count(make_pair(nx, ny))) {
            break;
        }
        all.insert(make_pair(nx, ny));
        q = make_pair(nx, make_pair(ny, ntp));
    }
    for (int i = 0; i < k; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        long long ans = inf;
        int num1 = x - y + max_n;
        int len = get(x, y, 2);
        ans = min(ans, res[num1][0][0] + len);
        num1 = x - y + max_n;
        len = get(x, y, 0);
        ans = min(ans, res[num1][0][1] + len);

        num1 = x + y;
        len = get(x, y, 3);
        ans = min(ans, res[num1][1][0] + len);
        num1 = x + y;
        len = get(x, y, 1);
        ans = min(ans, res[num1][1][1] + len);
        if (ans == inf) {
            ans = -1;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}