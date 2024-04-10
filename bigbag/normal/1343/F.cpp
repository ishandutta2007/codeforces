#include <bits/stdc++.h>

using namespace std;

const int max_n = 222, inf = 1000111222;

int t, n, p[max_n], cnt[max_n], used[max_n], kused[max_n];
vector<int> v[max_n];

bool check() {
    set<int> diff(p, p + n);
    if (diff.size() != n) {
        return false;
    }
    for (int i = 1; i < n; ++i) {
        vector<int> cur;
        cur.push_back(p[i]);
        bool ok = false;
        for (int j = i - 1; j >= 0; --j) {
            cur.push_back(p[j]);
            sort(cur.begin(), cur.end());
            int pos = lower_bound(v, v + n - 1, cur) - v;
            if (pos + 1 < n && v[pos] == cur) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            return false;
        }
    }
    return true;
}

bool solve(int pos) {
    if (0) {
        for (int i = pos + 1; i < n; ++i) {
            cout << p[i] + 1 << " ";
        }
        cout << endl;
    }
    if (pos == 0) {
        p[0] = 0;
        for (int i = 1; i < n; ++i) {
            p[0] ^= i;
            p[0] ^= p[i];
        }
        return check();
    }
    vector<int> all;
    memset(cnt, 0, sizeof(cnt));
    for (int j = 0; j < n; ++j) {
        if (used[j]) {
            continue;
        }
        for (int x : v[j]) {
            ++cnt[x];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (cnt[i] == 1) {
            all.push_back(i);
        }
    }
    if (all.empty()) {
        return false;
    }
    assert(all.size() <= 2);
    if (all.size() == 1) {
        p[pos] = all[0];
        for (int i = 0; i + 1 < n; ++i) {
            if (used[i]) {
                continue;
            }
            for (int x : v[i]) {
                if (x == p[pos]) {
                    used[i] = 1;
                    break;
                }
            }
        }
        return solve(pos - 1);
    }
    copy(used, used + n, kused);
    for (int x : all) {
        p[pos] = x;
        for (int i = 0; i + 1 < n; ++i) {
            if (used[i]) {
                continue;
            }
            for (int x : v[i]) {
                if (x == p[pos]) {
                    used[i] = 1;
                    break;
                }
            }
        }
        v[n - 1].clear();
        v[n - 1].push_back(all[0] ^ all[1] ^ x);

        if (solve(pos - 1)) {
            return true;
        }
        copy(kused, kused + n, used);
    }
    assert(false);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        v[n - 1].clear();
        for (int i = 0; i + 1 < n; ++i) {
            used[i] = 0;
            int k;
            scanf("%d", &k);
            v[i].resize(k);
            for (int &x : v[i]) {
                scanf("%d", &x);
                --x;
                ++cnt[x];
            }
        }
        sort(v, v + n - 1);
        memset(used, 0, sizeof(used));
        solve(n - 1);
        for (int i = 0; i < n; ++i) {
            printf("%d ", p[i] + 1);
        }
        puts("");
    }
    return 0;
}