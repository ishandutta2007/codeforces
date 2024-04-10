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

const int max_n = 311111, inf = 1111111111;

int n, a[max_n], mn[2][max_n], mx[2][max_n];

long long ans(int l, int r) {
    if (l == r) {
        return 1;
    }
    int mid = (l + r) / 2;
    long long res = ans(l, mid) + ans(mid + 1, r);
    mn[0][mid] = mx[0][mid] = a[mid];
    mn[1][mid + 1] = mx[1][mid + 1] = a[mid + 1];
    for (int i = mid - 1; i >= l; --i) {
        mn[0][i] = min(a[i], mn[0][i + 1]);
        mx[0][i] = max(a[i], mx[0][i + 1]);
    }
    for (int i = mid + 2; i <= r; ++i) {
        mn[1][i] = min(a[i], mn[1][i - 1]);
        mx[1][i] = max(a[i], mx[1][i - 1]);
    }
    for (int i = l; i <= mid; ++i) {
        int mn1 = mn[0][i];
        int mx1 = mx[0][i];
        int len = mx1 - mn1 + 1;
        int poz = i + len - 1;
        if (mid + 1 <= poz && poz <= r) {
            int mn2 = mn[1][poz];
            int mx2 = mx[1][poz];
            if (mn1 <= mn2 && mx2 <= mx1) {
                ++res;
            }
        }
    }
    for (int i = mid + 1; i <= r; ++i) {
        int mn1 = mn[1][i];
        int mx1 = mx[1][i];
        int len = mx1 - mn1 + 1;
        int poz = i - len + 1;
        if (l <= poz && poz <= mid) {
            int mn2 = mn[0][poz];
            int mx2 = mx[0][poz];
            if (mn1 <= mn2 && mx2 <= mx1) {
                ++res;
            }
        }
    }
    //cout << l << " " << r << " pres1 = " << res << endl;
    vector<pair<int, int> > v;
    for (int i = mid + 1; i <= r; ++i) {
        v.push_back(make_pair(mx[1][i] - i, i));
    }
    v.push_back(make_pair(inf, inf));
    sort(v.begin(), v.end());
    for (int i = l; i <= mid; ++i) {
        int mn1 = mn[0][i];
        int mx1 = mx[0][i];
        if (mn[1][mid + 1] < mn1) {
            continue;
        }
        if (mx[1][r] < mx1) {
            continue;
        }
        int l1 = mid, r1 = r;
        while (r1 - l1 > 1) {
            int md = (l1 + r1) / 2;
            if (mx[1][md] > mx1) {
                r1 = md;
            } else {
                l1 = md;
            }
        }
        int ll = r1;
        l1 = mid + 1, r1 = r + 1;
        while (r1 - l1 > 1) {
            int md = (l1 + r1) / 2;
            if (mn[1][md] < mn1) {
                r1 = md;
            } else {
                l1 = md;
            }
        }
        int rr = l1;
        int d = mn1 - i;
        if (ll > rr) {
            continue;
        }
        vector<pair<int, int> >::iterator it1 = lower_bound(v.begin(), v.end(), make_pair(d, ll));
        vector<pair<int, int> >::iterator it2 = upper_bound(v.begin(), v.end(), make_pair(d, rr));
        res += it2 - it1;
    }
    //cout << l << " " << r << " pres2 = " << res << endl;
    v.clear();
    for (int i = l; i <= mid; ++i) {
        v.push_back(make_pair(mx[0][i] + i, i));
    }
    v.push_back(make_pair(inf, inf));
    sort(v.begin(), v.end());
    for (int i = mid + 1; i <= r; ++i) {
        int mn1 = mn[1][i];
        int mx1 = mx[1][i];
        if (mn[0][mid] < mn1) {
            continue;
        }
        if (mx[0][l] < mx1) {
            continue;
        }
        int l1 = l, r1 = mid + 1;
        while (r1 - l1 > 1) {
            int md = (l1 + r1) / 2;
            if (mx[0][md] > mx1) {
                l1 = md;
            } else {
                r1 = md;
            }
        }
        int rr = l1;
        l1 = l - 1, r1 = mid;
        while (r1 - l1 > 1) {
            int md = (l1 + r1) / 2;
            if (mn[0][md] < mn1) {
                l1 = md;
            } else {
                r1 = md;
            }
        }
        int ll = r1;
        int d = mn1 + i;
        if (ll > rr) {
            continue;
        }
        vector<pair<int, int> >::iterator it1 = lower_bound(v.begin(), v.end(), make_pair(d, ll));
        vector<pair<int, int> >::iterator it2 = upper_bound(v.begin(), v.end(), make_pair(d, rr));
        res += it2 - it1;
        /*if (it2 - it1 > 0 && l == 1 && r == 7) {
            cout << "       " << i << " " << ll << " " << rr << endl;
            cout << "       " << (*it1).first << " " << (*it1).second << endl;
            cout << "       " << (*it2).first << " " << (*it2).second << endl;
        }*/
    }
    //cout << l << " " << r << "   res = " << res << endl << endl;
    v.clear();
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x] = y;
    }
    printf("%I64d\n", ans(1, n));
    return 0;
}