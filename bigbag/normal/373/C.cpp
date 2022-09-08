#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 511111, inf = 111111111;

int n, a[max_n], ans[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    ans[0] = 1;
    set <int> s, p;
    s.insert(0);
    for (int i = 1; i < n; ++i) {
        int x = inf;
        if (s.size() != 0) {
            x = *s.begin();
        }
        if (s.size() == 0 || a[x] * 2 > a[i]) {
            ans[i] = ans[i - 1] + 1;
            if (p.size() != 0) {
                int y = *p.begin();
                p.erase(y);
                s.insert(y);
                p.insert(i);
            } else {
                s.insert(i);
            }
        } else {
            ans[i] = ans[i - 1];
            s.erase(x);
            p.insert(i);
        }
    }
    cout << ans[n - 1] << endl;
    return 0;
}