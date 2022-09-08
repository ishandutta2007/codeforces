#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <ctime>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 22;
const long long inf = 1011011011022022022LL;

int cnt[10], c[10], CP[10];
long long L, l, r, ans;
vector<int> v;

long long get_first() {
    int len = 0, mx = 0;
    for (int i = 1; i < 10; ++i) {
        len += cnt[i];
        if (cnt[i]) {
            mx = i;
        }
    }
    if (len > v.size()) {
        long long res = 0;
        for (int i = 1; i < 10; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                res = res * 10 + i;
            }
        }
        return res;
    }
    long long res = inf, X = 0;
    cnt[0] = v.size() - len;
    copy(cnt, cnt + 10, CP);
    int last = 0, mx_pos = 9;
    for (int i = 0; i < v.size(); ++i) {
        int mn = v[i] + 1;
        if (i + 1 == v.size()) {
            mn = v[i];
        }
        while (mx_pos >= 0 && cnt[mx_pos] == 0) {
            --mx_pos;
        }
        if (mn <= mx_pos) {
            last = i;
        }
        if (cnt[v[i]] == 0) {
            break;
        }
        --cnt[v[i]];
    }
    copy(CP, CP + 10, cnt);
    for (int i = 0; i < v.size(); ++i) {
        int mn = v[i] + 1;
        if (i + 1 == v.size()) {
            mn = v[i];
        }
        if (i == last) {
            copy(cnt, cnt + 10, c);
            long long x = -1;
            for (int j = mn; j < 10; ++j) {
                if (c[j]) {
                    x = j;
                    --c[j];
                    break;
                }
            }
            if (x != -1) {
                x = X * 10 + x;
                for (int j = 0; j < 10; ++j) {
                    for (int k = 0; k < c[j]; ++k) {
                        x = x * 10 + j;
                    }
                }
                res = min(res, x);
            }
            break;
        }
        --cnt[v[i]];
        X = X * 10 + v[i];
    }
    if (res == inf) {
        copy(CP, CP + 10, cnt);
        ++cnt[0];
        for (int i = 1; i < 10; ++i) {
            if (cnt[i]) {
                res = i;
                break;
            }
        }
        --cnt[res];
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                res = res * 10 + i;
            }
        }
    }
    copy(CP, CP + 10, cnt);
    return res;
}

bool ok() {
    return get_first() <= r;
}

void get_all(int pos, int sum) {
    if (pos == 10) {
        if (sum != 18 && ok()) {
            ++ans;
        }
        return;
    }
    for (int i = 0; i <= sum; ++i) {
        cnt[pos] = i;
        get_all(pos + 1, sum - i);
    }
}

double st = clock();

double get_time() {
    return (clock() - st) / CLOCKS_PER_SEC;
}

int main() {
    cin >> l >> r;
    L = l;
    while (l) {
        v.push_back(l % 10);
        l /= 10;
    }
    reverse(v.begin(), v.end());
    if (v.size() == 19) {
        cout << 1 << endl;
        return 0;
    }
    get_all(1, 18);
    cout << ans << endl;
    return 0;
}