/**
 *  created: 25/12/2020, 15:54:36
**/

#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2") // WINDOWS ONLY

#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define all(a) a.begin(),a.end()
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;
const int magic = 166;
const int max_x = 200222;

int t, n, last[max_x], curt;
vector<int> a[max_n], v;

int compress(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

const int max_p = (max_x * magic) / 2;

pair<pair<int, int>, int> all[max_p], res[max_p];
int cnt[max_x];

void my_sort2(int n) {
    fill(cnt, cnt + v.size(), 0);
    for (int i = 0; i < n; ++i) {
        ++cnt[all[i].first.second + 1];
    }
    for (int i = 1; i < v.size(); ++i) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        res[cnt[all[i].first.second]++] = all[i];
    }
    copy(res, res + n, all);
}

void my_sort1(int n) {
    fill(cnt, cnt + v.size(), 0);
    for (int i = 0; i < n; ++i) {
        ++cnt[all[i].first.first + 1];
    }
    for (int i = 1; i < v.size(); ++i) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        res[cnt[all[i].first.first]++] = all[i];
    }
    copy(res, res + n, all);
}

void my_sort(int n) {
    my_sort2(n);
    my_sort1(n);
}

void solve() {
    for (int i = 0; i < n; ++i) {
        if (a[i].size() >= magic) {
            ++curt;
            for (int x : a[i]) {
                last[x] = curt;
            }
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }
                int cnt = 0;
                for (int x : a[j]) {
                    cnt += last[x] == curt;
                }
                if (cnt >= 2) {
                    printf("%d %d\n", i + 1, j + 1);
                    return;
                }
            }
        }
    }
    int all_sz = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i].size() < magic) {
            for (int j = 0; j < a[i].size(); ++j) {
                for (int k = j + 1; k < a[i].size(); ++k) {
                    all[all_sz++] = {{a[i][j], a[i][k]}, i};
                }
            }
        }
    }
    my_sort(all_sz);
    for (int i = 0; i + 1 < all_sz; ++i) {
        if (all[i].first == all[i + 1].first) {
            printf("%d %d\n", all[i].second + 1, all[i + 1].second + 1);
            return;
        }
    }
    puts("-1");
}

const bool debug = 0;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (debug) {
        t = 1;
    } else {
        scanf("%d", &t);
    }
    while (t--) {
        if (debug) {
            n = max_n / magic;
            for (int i = 0; i < n; ++i) {
                a[i].resize(magic);
                for (int j = 0; j < a[i].size(); ++j) {
                    a[i][j] = v.size();
                    v.push_back(a[i][j]);
                }
            }
        } else {
            scanf("%d", &n);
            v.clear();
            for (int i = 0; i < n; ++i) {
                int k;
                scanf("%d", &k);
                a[i].resize(k);
                for (int &x : a[i]) {
                    scanf("%d", &x);
                    v.push_back(x);
                }
            }
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int i = 0; i < n; ++i) {
            for (int &x : a[i]) {
                x = compress(x);
            }
            sort(a[i].begin(), a[i].end());
        }
        solve();
    }
    return 0;
}