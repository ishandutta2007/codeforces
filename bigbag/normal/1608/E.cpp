/**
 *  created: 11/12/2021, 13:25:16
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

struct segment_tree {
    int sum[4 * max_n][2];

    void clr() {
        memset(sum, 0, sizeof(sum));
    }

    void update(int v, int l, int r, int x, int c) {
        if (l == r) {
            ++sum[v][c];
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            update(2 * v, l, mid, x, c);
        } else {
            update(2 * v + 1, mid + 1, r, x, c);
        }
        sum[v][0] = sum[2 * v][0] + sum[2 * v + 1][0];
        sum[v][1] = sum[2 * v][1] + sum[2 * v + 1][1];
    }

    int get(int v, int l, int r, int add0, int add1) {
        if (l == r) {
            return max(min(add0 + sum[v][0], add1),
                       min(add0, add1 + sum[v][1]));
        }
        int mid = (l + r) / 2;
        if (add0 + sum[2 * v][0] <= add1 + sum[2 * v + 1][1]) {
            return get(2 * v + 1, mid + 1, r, add0 + sum[2 * v][0], add1);
        }
        return get(2 * v, l, mid, add0, add1 + sum[2 * v + 1][1]);
    }
};

struct Point {
    int x, y, c;

    bool operator < (const Point &p) const {
        return x < p.x;
    }
};

int n;
Point p[max_n];
vector<int> vx, vy;
segment_tree st;

int compress(const vector<int> &v, int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

int solve() {
    sort(p, p + n);
    vector<int> perm{0, 1, 2};
    int res = 0;
    do {
        st.clr();
        int c3 = n / 3;
        for (int i = 0; i < n; ) {
            int pos = i;
            while (i < n && p[i].x == p[pos].x) {
                if (p[i].c == perm[2]) {
                    --c3;
                } else {
                    int tp = (p[i].c == perm[1]);
                    st.update(1, 0, n - 1, p[i].x, tp);
                }
                ++i;
            }
            res = max(res, min(c3, st.get(1, 0, n - 1, 0, 0)));
            /*if (res == 3) {
                cout << "#" << i << endl;
                cout << perm[0] << " " << perm[1] << " " << perm[2] << endl;


                exit(9);
            }*/
        }


        for (int it = 0; it < 2; ++it) {
            st.clr();
            int c3 = n / 3;
            for (int i = 0; i < n; ) {
                int pos = i;
                while (i < n && p[i].x == p[pos].x) {
                    if (p[i].c == perm[2]) {
                        --c3;
                    } else {
                        int tp = (p[i].c == perm[1]);
                        st.update(1, 0, n - 1, p[i].y, tp);
                    }
                    ++i;
                }
                res = max(res, min(c3, st.get(1, 0, n - 1, 0, 0)));
            }

            for (int i = 0; i < n; ++i) {
                p[i].x = n - 1 - p[i].x;
            }
            reverse(p, p + n);
        }
    } while (next_permutation(perm.begin(), perm.end()));
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y >> p[i].c;
        --p[i].c;
        vx.push_back(p[i].x);
        vy.push_back(p[i].y);
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    vy.erase(unique(vy.begin(), vy.end()), vy.end());
    for (int i = 0; i < n; ++i) {
        p[i].x = compress(vx, p[i].x);
        p[i].y = compress(vy, p[i].y);
    }
    int ans = 0;
    for (int it = 0; it < 2; ++it) {
        //cout << "$" << it << endl;
        ans = max(ans, solve());
        for (int i = 0; i < n; ++i) {
            swap(p[i].x, p[i].y);
        }
    }
    cout << ans * 3 << "\n";
    return 0;
}