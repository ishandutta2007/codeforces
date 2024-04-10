/**
 *  created: 06/03/2021, 17:04:24
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1111, inf = 1000111222;

int n, m;

bool query(int h, int w, int lx1, int ly1, int lx2, int ly2) {
    cout << "? " << h << " " << w << " " << lx1 + 1 << " " << ly1 + 1 << " " << lx2 + 1 << " " << ly2 + 1 << endl;
    int res = 1;
    cin >> res;
    return res;
}

bool query(int h, int w, int lx1, int ly1, int lx2, int ly2, bool rev) {
    if (rev) {
        swap(h, w);
        swap(lx1, ly1);
        swap(lx2, ly2);
    }
    return query(h, w, lx1, ly1, lx2, ly2);
}

vector<pair<int, int>> factorize(int x) {
    vector<pair<int, int>> res;
    for (int p = 2; p * p <= x; ++p) {
        int cnt = 0;
        while (x % p == 0) {
            x /= p;
            ++cnt;
        }
        if (cnt) {
            res.push_back({p, cnt});
        }
    }
    if (x > 1) {
        res.push_back({x, 1});
    }
    return res;
}

bool check(int lx, int rx, int H, int cnt, bool rev) {
    int len = (rx - lx + 1) / cnt;
    len *= cnt / 2;
    if (!query(len, H, lx, 0, lx + len, 0, rev)) {
        return false;
    }
    if (cnt == 2) {
        return true;
    }
    return check(lx + len, rx, H, cnt - cnt / 2, rev);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    int d1 = 1, d2 = 1;
    for (auto p : factorize(n)) {
        int x = 1, ans = 1;
        for (int i = 0; i < p.second; ++i) {
            if (check(0, n / x - 1, m, p.first, 0)) {
                ++ans;
                x *= p.first;
            } else {
                break;
            }
        }
        d1 *= ans;
    }
    for (auto p : factorize(m)) {
        int x = 1, ans = 1;
        for (int i = 0; i < p.second; ++i) {
            if (check(0, m / x - 1, n, p.first, 1)) {
                ++ans;
                x *= p.first;
            } else {
                break;
            }
        }
        d2 *= ans;
    }
    int ans = d1 * d2;
    cout << "! " << ans << endl;
    return 0;
}