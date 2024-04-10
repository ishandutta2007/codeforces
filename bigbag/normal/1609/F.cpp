/**
 *  created: 28/11/2021, 17:22:33
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;
const int max_b = 62;

const bool debug = 0;

int n;
pair<int, int> a[max_n];
pair<int, int> mn[max_n];
pair<int, int> mx[max_n];
long long A[max_n];
vector<long long> all;
int cnt[max_b];

int compress(long long x) {
    return lower_bound(all.begin(), all.end(), x) - all.begin();
}

long long solve(int l, int r) {
    if (l == r) {
        return 1;
    }
    int mid = (l + r) / 2;
    long long res = solve(l, mid);
    res += solve(mid + 1, r);
    {
        pair<int, int> MN(inf, inf);
        pair<int, int> MX(-inf, -inf);
        for (int i = mid; i >= l; --i) {
            MN = min(MN, a[i]);
            MX = max(MX, a[i]);
            mn[i] = MN;
            mx[i] = MX;
        }
    }
    {
        pair<int, int> MN(inf, inf);
        pair<int, int> MX(-inf, -inf);
        for (int i = mid + 1; i <= r; ++i) {
            MN = min(MN, a[i]);
            MX = max(MX, a[i]);
            mn[i] = MN;
            mx[i] = MX;
        }
    }
    { // mn1, mx1
        int pos = mid + 1;
        for (int i = mid; i >= l; --i) {
            if (mn[i].second != mx[i].second) {
                continue;
            }
            while (pos <= r && mn[i].first <= mn[pos].first && mx[i].first >= mx[pos].first) {
                ++pos;
            }
            res += pos - mid - 1;
        }
    }
    { // mn2, mx2
        int pos = mid;
        for (int i = mid + 1; i <= r; ++i) {
            if (mn[i].second != mx[i].second) {
                continue;
            }
            while (pos >= l && mn[pos].first > mn[i].first && mx[pos].first < mx[i].first) {
                --pos;
            }
            res += mid - pos;
        }
    }
    { // mn1, mx2
        memset(cnt, 0, sizeof(cnt));
        int pos1 = mid + 1, pos2 = mid + 1;
        for (int i = mid; i >= l; --i) {
            while (pos1 <= r && mn[i].first <= mn[pos1].first) {
                ++cnt[mx[pos1].second];
                ++pos1;
            }
            while (pos2 < pos1 && mx[i].first >= mx[pos2].first) {
                --cnt[mx[pos2].second];
                ++pos2;
            }
            res += cnt[mn[i].second];
        }
    }


    { // mx1, mn2
        memset(cnt, 0, sizeof(cnt));
        int pos1 = mid, pos2 = mid;
        for (int i = mid + 1; i <= r; ++i) {
            while (pos1 >= l && mn[i].first < mn[pos1].first) {
                ++cnt[mx[pos1].second];
                --pos1;
            }
            while (pos2 > pos1 && mx[i].first > mx[pos2].first) {
                --cnt[mx[pos2].second];
                --pos2;
            }
            res += cnt[mn[i].second];
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (debug) {
        n = 1000000;
        mt19937_64 gen;
        for (int i = 0; i < n; ++i) {
            A[i] = gen() % 1000000000000000000LL;
        }
    } else {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        a[i].second = __builtin_popcountll(A[i]);
        all.push_back(A[i]);
    }
    sort(all.begin(), all.end());
    for (int i = 0; i < n; ++i) {
        a[i].first = compress(A[i]);
    }
    long long ans = solve(0, n - 1);
    cout << ans << "\n";
    return 0;
}