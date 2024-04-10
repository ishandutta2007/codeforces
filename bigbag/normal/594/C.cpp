#include <map>
#include <set>
#include <stack>
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

int n, k, x[max_n], y[max_n], x1[max_n], x2[max_n], y1[max_n], y2[max_n];
int p1[max_n], p2[max_n], p3[max_n], p4[max_n], f[max_n];

bool cmp1(int a, int b) {
    return x[a] < x[b];
}

bool cmp2(int a, int b) {
    return x[a] > x[b];
}

bool cmp3(int a, int b) {
    return y[a] < y[b];
}

bool cmp4(int a, int b) {
    return y[a] > y[b];
}

long long get() {
    long long mnx, mxx, mny, mxy;
    int q = 0;
    for (int i = 0; i < n; ++i) {
        if (f[i] == 0) {
            ++q;
        }
    }
    //cout << q << endl;
    for (int i = 0; i < n; ++i) {
        if (f[p1[i]] == 0) {
            mnx = x[p1[i]];
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (f[p2[i]] == 0) {
            mxx = x[p2[i]];
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (f[p3[i]] == 0) {
            mny = y[p3[i]];
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (f[p4[i]] == 0) {
            mxy = y[p4[i]];
            break;
        }
    }
    //cout << mnx << " " << mxx << "   " << mny << " " << mxy << " : " << (max(1LL, (mxx - mnx + 1) / 2)) << " " << (max(1LL, (mxy - mny + 1) / 2)) << endl;
    return (max(1LL, (mxx - mnx + 1) / 2)) * (max(1LL, (mxy - mny + 1) / 2));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
        x[i] = (x1[i] + x2[i]);
        y[i] = (y1[i] + y2[i]);
        p1[i] = i;
        p2[i] = i;
        p3[i] = i;
        p4[i] = i;
    }
    sort(p1, p1 + n, cmp1);
    sort(p2, p2 + n, cmp2);
    sort(p3, p3 + n, cmp3);
    sort(p4, p4 + n, cmp4);
    long long ans = inf;
    for (int q1 = 0; q1 <= k; ++q1) {
        int c1 = 0;
        for (int i = 0; c1 < q1 && i < n; ++i) {
            if (f[p1[i]] == 0) {
                ++c1;
                f[p1[i]] = 1;
            }
        }
        for (int q2 = 0; q1 + q2 <= k; ++q2) {
            int c2 = 0;
            for (int i = 0; c2 < q2 && i < n; ++i) {
                if (f[p2[i]] == 0) {
                    ++c2;
                    f[p2[i]] = 2;
                }
            }
            for (int q3 = 0; q1 + q2 + q3 <= k; ++q3) {
                int c3 = 0;
                for (int i = 0; c3 < q3 && i < n; ++i) {
                    if (f[p3[i]] == 0) {
                        ++c3;
                        f[p3[i]] = 3;
                    }
                }
                int q4 = k - q1 - q2 - q3;
                int c4 = 0;
                for (int i = 0; c4 < q4 && i < n; ++i) {
                    if (f[p4[i]] == 0) {
                        ++c4;
                        f[p4[i]] = 4;
                    }
                }
                ans = min(ans, get());
                for (int i = 0; c4 > 0 && i < n; ++i) {
                    if (f[p4[i]] == 4) {
                        --c4;
                        f[p4[i]] = 0;
                    }
                }
                for (int i = 0; c3 > 0 && i < n; ++i) {
                    if (f[p3[i]] == 3) {
                        --c3;
                        f[p3[i]] = 0;
                    }
                }
            }
            for (int i = 0; c2 > 0 && i < n; ++i) {
                if (f[p2[i]] == 2) {
                    --c2;
                    f[p2[i]] = 0;
                }
            }
        }
        for (int i = 0; c1 > 0 && i < n; ++i) {
            if (f[p1[i]] == 1) {
                --c1;
                f[p1[i]] = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}