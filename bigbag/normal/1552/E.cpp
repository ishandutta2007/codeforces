/**
 *  created: 25/07/2021, 18:25:46
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 10111, inf = 1000111222;

int n, k, a[max_n];
int ans_l[max_n], ans_r[max_n];
vector<int> all[max_n];

void solve(int l, int r) {
    //cout << "!solve " << l << " " << r << endl;
    int last = -1;
    for (int it = 0; it < r - l; ++it) {
        pair<int, pair<int, int>> shortest(inf, {inf, inf});
        for (int col = l; col < r; ++col) {
            if (ans_l[col]) {
                continue;
            }
            for (int i = 0; i + 1 < all[col].size(); ++i) {
                if (all[col][i] > last) {
                    shortest = min(shortest, make_pair(all[col][i + 1], make_pair(all[col][i], all[col][i + 1])));
                }
            }
        }
        const int L = shortest.second.first, R = shortest.second.second;
        assert(L != inf);
        //cout << "#" << L << " " << R << endl;
        ans_l[a[L]] = L + 1;
        ans_r[a[R]] = R + 1;
        last = R;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n * k; ++i) {
        scanf("%d", &a[i]);
        --a[i];
        all[a[i]].push_back(i);
    }
    for (int i = 0; i < n; i += k - 1) {
        solve(i, min(n, i + k - 1));
    }
    for (int i = 0; i < n; ++i) {
        printf("%d %d\n", ans_l[i], ans_r[i]);
    }
    return 0;
}