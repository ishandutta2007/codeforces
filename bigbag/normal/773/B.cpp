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

const int max_n = 133, inf = 1011111111;

int n, l[9], r[9], a[max_n][9], cnt[9], tp[9];
int mn[9], mx[9], add[9];

int get(int a[]) {
    int res = 0;
    for (int i = 0; i < 5; ++i) {
        if (a[i] != -1) {
            int mx = (tp[i] + 1) * 500;
            res += mx - mx / 250 * a[i];
        }
    }
    return res;
}

bool rec(int pos, int x) {
    if (x < 0) {
        return false;
    }
    if (pos == 5) {
        if (get(a[0]) > get(a[1])) {
            /*for (int i = 0; i < 5; ++i) {
                cout << tp[i] << " ";
            }
            cout << endl;
            for (int i = 0; i < 5; ++i) {
                cout << add[i] << " ";
            }
            cout << endl;
            cout << get(a[0]) << " " << get(a[1]) << endl;*/
            return true;
        }
        return false;
    }
    for (int i = 0; i < 6; ++i) {
        if (a[0][pos] == -1) {
            if (!(l[i] <= cnt[pos] && cnt[pos] <= r[i])) {
                continue;
            }
        }
        tp[pos] = i;
        if (l[i] > r[i] || cnt[pos] > r[i]) {
            continue;
        }
        int pl = 0;
        if (cnt[pos] < l[i]) {
            pl = l[i] - cnt[pos];
        }
        add[pos] = pl;
        if (pl > x) {
            continue;
        }
        if (rec(pos + 1, x)) {
            return true;
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> a[i][j];
            if (a[i][j] != -1) {
                ++cnt[j];
            }
        }
    }
    for (int x = 0; x < 4444; ++x) {
        int all = n + x, pw = 1;
        for (int i = 0; i < 6; ++i) {
            r[i] = all / pw;
            pw *= 2;
            l[i] = all / pw + 1;
        }
        l[5] = 0;
        if (rec(0, x)) {
            cout << x << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}