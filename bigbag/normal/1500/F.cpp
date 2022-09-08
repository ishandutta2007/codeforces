/**
 *  created: 25/03/2021, 21:49:52
 *  pause: 22:50 - 23:11
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

int n;
int q1 = 0, q2 = 1;
long long C, add[2], a[max_n], ans[max_n];
multiset<pair<long long, long long>> q[2];
vector<pair<int, pair<long long, long long>>> del[max_n];
long long old_add[max_n][2];
bool good[max_n];

long long get_max() {
    long long res = 0;
    if (!q[q1].empty()) {
        res = q[q1].rbegin()->second + add[q1];
    }
    if (!q[q2].empty()) {
        long long val = add[q2] - q[q2].begin()->first;
        res = max(res, val);
    }
    return res;
}

long long get_min() {
    long long res = 1LL * inf * inf;
    if (!q[q1].empty()) {
        res = q[q1].begin()->first + add[q1];
    }
    if (!q[q2].empty()) {
        long long val = add[q2] - q[q2].rbegin()->second;
        res = min(res, val);
    }
    return res;
}

void write() {
    for (auto p : q[q1]) {
        cout << "[" << p.first + add[q1] << " " << p.second + add[q1] << "] ";
    }
    cout << "   ";
    for (auto p : q[q2]) {
        cout << "[" << -p.second + add[q2] << " " << -p.first + add[q2] << "] ";
    }
    cout << endl;
}

const int seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 generator(seed);

int rnd() {
    return generator() >> 1;
}

int rnd(int r) {
    return rnd() % r;
}

int rnd(int l, int r) {
    return l + rnd(r - l + 1);
}

const bool debug = 0;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (debug) {
        n = rnd(6, 75);
        vector<long long> hid(n);
        for (int i = 0; i < n; ++i) {
            hid[i] = rnd(9);
        }
        cout << "hid = ";
        for (int i = 0; i < n; ++i) {
            cout << hid[i] << " ";
        }
        cout << endl;
        cout << n << " 0" << endl;
        for (int i = 2; i < n; ++i) {
            long long x = *max_element(hid.begin() + i - 2, hid.begin() + i + 1) - *min_element(hid.begin() + i - 2, hid.begin() + i + 1);
            a[i] = x;
            cout << x << " ";
        }
        cout << endl;
    } else {
        scanf("%d%lld", &n, &C);
        for (int i = 2; i < n; ++i) {
            scanf("%lld", &a[i]);
        }
    }
    q[q1].insert({0, a[2]});
    for (int i = 3; i < n; ++i) {
        //cout << i - 1 << ": ";
        //write();
        while (!q[q1].empty()) {
            auto it = --q[q1].end();
            long long l = it->first + add[q1], r = it->second + add[q1];
            if (r < a[i]) {
                break;
            }
            del[i].push_back({q1, *it});
            q[q1].erase(it);
            if (l > a[i]) {
                continue;
            }
            good[i] = 1;
            break;
        }
        while (!q[q2].empty()) {
            auto it = q[q2].begin();
            long long l = add[q2] - it->second, r = add[q2] - it->first;
            if (r < a[i]) {
                break;
            }
            del[i].push_back({q2, *it});
            q[q2].erase(it);
            if (l > a[i]) {
                continue;
            }
            good[i] = 1;
            break;
        }
        if (!good[i] && q[q1].empty() && q[q2].empty()) {
            puts("NO");
            return 0;
        }
        if (good[i]) {
            for (auto p : q[q1]) {
                del[i].push_back({q1, p});
            }
            for (auto p : q[q2]) {
                del[i].push_back({q2, p});
            }
            q[q1].clear();
            q[q2].clear();
            old_add[i][q1] = add[q1];
            old_add[i][q2] = add[q2];
            add[q1] = add[q2] = 0;
            q[q1].insert({0, a[i]});
            continue;
        }
        swap(q1, q2);
        add[q1] = a[i] - add[q1];
        add[q2] = a[i] - add[q2];
        q[q1].insert({a[i] - add[q1], a[i] - add[q1]});
    }
    //cout << n - 1 << ": ";
    //write();

    long long val = get_max();
    for (int i = n - 1; i >= 3; --i) {
        //cout << i << ": good = " << good[i] << ", val = " << val << endl;
        ans[i] = val;
        assert(-a[i] <= val && val <= a[i]);
        if (good[i]) {
            q[q1].clear();
            q[q2].clear();
            add[q1] = old_add[i][q1];
            add[q2] = old_add[i][q2];
            for (auto p : del[i]) {
                q[p.first].insert(p.second);
            }
        } else {
            q[q1].erase(q[q1].find({a[i] - add[q1], a[i] - add[q1]}));
            add[q1] = a[i] - add[q1];
            add[q2] = a[i] - add[q2];
            swap(q1, q2);
            for (auto p : del[i]) {
                q[p.first].insert(p.second);
            }
        }
        if (good[i]) {
            if (val >= 0) {
                val = -a[i];
            } else {
                val = a[i];
            }
        } else if (abs(val) == a[i]) {
            if (val < 0) {
                val = get_min();
            } else {
                val = -get_min();
            }
        } else {
            if (val > 0) { // a[i] - old_val = val => old_val = a[i] - val
                val = a[i] - val;
            } else { // -a[i] - old_val = val => old_val = -a[i] - val
                val = -a[i] - val;
            }
        }
        //cout << i - 1 << ": ";
        //write();
    }
    //cout << "###"  << val << endl;
    if (val < 0) {
        ans[1] = a[2];
    } else {
        ans[1] = -a[2];
    }
    ans[2] = val;
    for (int i = 2; i < n; ++i) {
        ans[i] += ans[i - 1];
    }
    long long mn = *min_element(ans, ans + n);
    for (int i = 0; i < n; ++i) {
        ans[i] -= mn;
    }
    puts("YES");
    for (int i = 0; i < n; ++i) {
        printf("%lld ", ans[i]);
        if (i >= 2) {
            long long d = *max_element(ans + i - 2, ans + i + 1) - *min_element(ans + i - 2, ans + i + 1);
            if (!(d == a[i])) {
                //while (1);
            }
        }
    }
    puts("");
    return 0;
}