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

const int max_n = 111111, inf = 1111111111;

int n, m, cnt[333], cnt2[333], f[max_n], nxt[max_n];
string s, a;

void read() {
    char a[max_n];
    scanf("%s", a);
    s = a;
}

void update(int &r) {
    while (r < n && f[r] == 1) {
        ++r;
    }
}

bool check(int len) {
    memset(cnt2, 0, sizeof(cnt2));
    for (int i = 0; i < len; ++i) {
        ++cnt2[a[i]];
    }
    char mx = 'z' + 1;
    for (char c = 'a'; c <= 'z'; ++c) {
        if (cnt[c] != cnt2[c]) {
            mx = c;
            break;
        }
    }
    memset(f, 0, sizeof(f));
    int r = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] < mx) {
            for (int j = max(r, i - m + 1); j < n && j <= i; ++j) {
                f[j] = 1;
            }
            r = i + 1;
        }
    }
    int res = 0;
    nxt[n] = inf;
    for (int j = n - 1; j >= 0; --j) {
        nxt[j] = nxt[j + 1];
        if (s[j] == mx) {
            nxt[j] = j;
        }
    }
    /*for (int i = 0; i < n; ++i) {
        cout << f[i];
    }
    cout << endl;*/
    /*for (int i = 0; i < n; ++i) {
        cout << nxt[i] << " ";
    }
    cout << endl;*/
    r = 0;
    update(r);
    for (int j = 0; j < n; ++j) {
        if (r >= n - m + 1) {
            break;
        }
        if (nxt[j + 1] - m + 1 <= r) {
            continue;
        }
        //cout << j << endl;
        if (s[j] != mx) {
            res = inf;
            break;
        }
        ++res;
        r = j + 1;
        update(r);
    }
    return res <= cnt2[mx];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &m);
    read();
    n = s.length();
    a = s;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        ++cnt[s[i]];
    }
    //cout << check(1) << endl;
    //return 0;
    int l = 0, r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    printf("%s\n", a.substr(0, r).c_str());
    return 0;
}