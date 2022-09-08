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

const int max_n = 111111, inf = 1111111111;

int n, a[max_n], x[2][max_n];
vector<pair<int, int> > ans;

int fun(int f, int l, int r) {
    if (l == 0) {
        return x[f][r];
    }
    return x[f][r] - x[f][l - 1];
}

bool ok(int mid, int poz, int t) {
    int xx = fun(0, poz, mid);
    int y = fun(1, poz, mid);
    //cout << "@" << xx << " " << y << endl;
    if (xx > t || y > t) {
        return false;
    }
    if (xx == t && y == t) {
        return false;
    }
    if (xx == t) {
        if (a[mid] == 1) {
            return false;
        }
    }
    if (y == t) {
        if (a[mid] == 0) {
            return false;
        }
    }
    return true;
}

bool ok2(int mid, int poz, int t) {
    int xx = fun(0, poz, mid);
    int y = fun(1, poz, mid);
    if (xx < t && y < t) return true;
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        --a[i];
        if (i) {
            x[0][i] = x[0][i - 1];
            x[1][i] = x[1][i - 1];
        }
        ++x[a[i]][i];
    }
    for (int t = 1; t <= n; ++t) {
        int poz = 0, c1 = 0, c2 = 0, s = 0, last = 0;
        //cout << t << " : ";
        while (poz < n) {
            //if (t == 3 && poz == 0) cout << ok(0, 3, 3) << endl;
            //cout << poz << " ";
            //cout << "%" << ok(poz, poz, t) << endl;
            int l = poz, r = n;
            if (ok2(n - 1, poz, t)) {
                    //cout << "!";
                break;
            }
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (ok(mid, poz, t)) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            int x0 = fun(0, poz, l);
            int x1 = fun(1, poz, l);
            if (x0 == t) {
                ++c1;
                last = 1;
            } else if (x1 == t) {                ++c2;
                last = 2;
            }
            //cout << "(" << l << " " << r << ") ";
            poz = l + 1;
        }
        if (poz == n) {
            if (c1 > c2 && last == 1) {
                ans.push_back(make_pair(c1, t));
            }
            if (c2 > c1 && last == 2) {
                ans.push_back(make_pair(c2, t));
            }
        }
        //cout << poz << endl;
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}