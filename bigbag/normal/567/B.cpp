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

const int max_n = 111, max_x = 1111111, inf = 1111111111;

int n, ans, a[max_n], f[max_x];
char c[max_n];
set<int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(f, -1, sizeof(f));
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c[i] >> a[i];
        if (f[a[i]] == -1) {
            f[a[i]] = i;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (c[i] == '-' && f[a[i]] == i) {
            ++cnt;
        }
        if (c[i] == '+') {
            q.insert(a[i]);
        } else if (!q.count(a[i])) {
            ++ans;
        }
    }
    q.clear();
    for (int i = 0; i < n; ++i) {
        if (c[i] == '+') {
            q.insert(a[i]);
        } else if (q.count(a[i])) {
            q.erase(a[i]);
        }
        ans = max(ans, cnt + (int) q.size());
        if (c[i] == '-' && f[a[i]] == i) {
            --cnt;
        }
    }
    cout << ans << endl;
    return 0;
}