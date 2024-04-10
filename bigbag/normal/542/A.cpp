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

const int max_n = 222222, max_lev = 20, inf = 1000000111;

int n, m, poz1, poz2, res1[max_n], res2[max_n];
long long a[max_n];
pair<int, int> mx[max_n];
pair<int, pair<int, int> > p[max_n], pp[max_n];
pair<int, pair<int, int> > p2[max_n], p22[max_n];
long long ans = 0;
int num[max_n];
pair<long long, int> maxs[max_lev][max_n];

void get_all_maxs(int n) {
    for (int i = 0; i < n; ++i) {
        maxs[0][i] = make_pair(a[i], i);
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

pair<long long, int> get_max(int l, int r) {
    if (l > r) {
        return make_pair(-inf, 0);
    }
    int lev = num[r - l + 1];
    return max(maxs[lev][l], maxs[lev][r - (1 << lev) + 1]);
}

void proc0() {
    sort(p, p + n);
    mx[0] = make_pair(p[0].second.first, 0);
    for (int i = 1; i < n; ++i) {
        if (p[i].second.first > mx[i - 1].first) {
            mx[i] = make_pair(p[i].second.first, i);
        } else {
            mx[i] = mx[i - 1];
        }
    }
    int m2 = 0;
    for (int i = 0; i < m; ++i) {
        int l = 0, r = n;
        if (p[0].first > p2[i].first) {
            p22[m2] = p2[i];
            res2[m2] = res2[i];
            ++m2;
            continue;
        }
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (p[mid].first <= p2[i].first) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (mx[l].first >= p2[i].second.first) {
            long long q = 1LL * (p2[i].second.first - p2[i].first) * p2[i].second.second;
            if (ans < q) {
                ans = q;
                poz1 = p[mx[l].second].second.second;
                poz2 = res2[i];
            }
            //cout << i << " " << q << "     " << l << " " << mx[l].first << endl;
        } else {
            p22[m2] = p2[i];
            res2[m2] = res2[i];
            ++m2;
        }
    }
    m = m2;
    for (int i = 0; i < m; ++i) {
        p2[i] = p22[i];
    }
}

void proc1() {
    int n2 = 0;
    for (int i = 0; i < n;) {
        pp[n2] = p[i];
        res1[n2] = i;
        while (i < n && p[i].second.first <= pp[n2].second.first) {
            ++i;
        }
        ++n2;
    }
    n = n2;
    for (int i = 0; i < n; ++i) {
        p[i] = pp[i];
    }
}

int gpoz1(int x) {//L >= x
    int l = -1, r = n - 1;
    if (p[n - 1].first < x) {
        //cout << x << endl;
        return inf;
    }
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (p[mid].first < x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return r;
}

int gpoz2(int x) {//R >= x
    int l = -1, r = n - 1;
    if (p[n - 1].second.first < x) {
        return inf;
    }
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (p[mid].second.first < x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return r;
}

int gpoz3(int x) {//R <= x
    int l = 0, r = n;
    if (p[0].second.first > x) {
        return inf;
    }
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (p[mid].second.first < x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    //cout << "           " << x << " ! " << l << endl;
    return l;
}

void proc2() {
    for (int i = 0; i < n; ++i) {
        a[i] = p[i].second.first - p[i].first;
    }
    get_all_maxs(n);
    for (int i = 0; i < m; ++i) {
        int L = gpoz1(p2[i].first);
        //cout << i << " - " << L << "   " << p2[i].first << " " << p2[i].second.first << " " << p2[i].second.second << endl;
        if (L == inf) {
            continue;
        }
        int R = gpoz2(p2[i].second.first);
        if (R != inf) {
            long long q = 1LL * (p2[i].second.first - p[R].first) * p2[i].second.second;
            //cout << i << " upd = " << q << "     " << p[R].first << " " << p2[i].second.first << endl;
            if (ans < q) {
                ans = q;
                poz1 = p[R].second.second;
                poz2 = res2[i];
            }
        }
        int R2 = gpoz3(p2[i].second.first);
        if (R2 == inf) {
            continue;
        }
        //cout << i << " - " << L << " " << R2 << endl;
        if (L <= R2) {
            pair<long long, int> mx = get_max(L, R2);
            long long q = 1LL * mx.first * p2[i].second.second;
            //cout << i << "  upd = " << q << "   " << L << "  " << R << "     mx = " << mx.first << endl;
            if (ans < q) {
                ans = q;
                poz1 = p[mx.second].second.second;
                poz2 = res2[i];
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        res1[i] = i;
        scanf("%d%d", &p[i].first, &p[i].second.first);
        p[i].second.second = i;
    }
    for (int i = 0; i < m; ++i) {
        res2[i] = i;
        scanf("%d%d%d", &p2[i].first, &p2[i].second.first, &p2[i].second.second);
    }
    proc0();
    proc1();
    proc2();
    for (int i = 0; i < m; ++i) {
        p2[i].first *= -1;
        p2[i].second.first *= -1;
        swap(p2[i].first, p2[i].second.first);
    }
    for (int i = 0; i < n; ++i) {
        p[i].first *= -1;
        p[i].second.first *= -1;
        swap(p[i].first, p[i].second.first);
    }
    proc0();
    proc1();
    proc2();
    cout << ans << endl;
    if (ans == 0) {
        return 0;
    }
    cout << poz1 + 1 << " " << poz2 + 1 << endl;
    return 0;
}