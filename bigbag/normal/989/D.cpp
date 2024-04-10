#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, l, wm;
long long ans;
pair<int, int> p[max_n];

long long triv() {
    long long cl = 0, cr = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i].first + l <= 0 && p[i].second == 1) {
            ++cl;
        }
        if (p[i].first >= 0 && p[i].second == -1) {
            ++cr;
        }
    }
    return cl * cr;
}

void solve() {
    vector<int> all;
    int pos = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (p[i].first + l <= 0) {
            break;
        }
        if (p[i].second == 1) {
            if (p[i].first < 0) {
                ans += all.size();
            } else {
                while (pos < all.size() && wm && 1LL * all[pos] * wm > 2 * p[i].first + 1LL * p[i].first * wm) {
                    ++pos;
                }
                ans += pos;
            }
        } else {
            all.push_back(p[i].first + l);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &l, &wm);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &p[i].first, &p[i].second);
    }
    sort(p, p + n);
    ans += triv();
    --wm;
    solve();
    for (int i = 0; i < n; ++i) {
        p[i].first += l;
        p[i].first *= -1;
        p[i].second *= -1;
    }
    sort(p, p + n);
    solve();
    printf("%I64d\n", ans);
    return 0;
}