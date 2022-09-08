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

const int max_n = 155555, inf = 1111111111;

int t, n, k, a[max_n], b[max_n], cnt[max_n], cnt2[max_n];
set<int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        q.clear();
        scanf("%d%d", &n, &k);
        --n;
        for (int i = 1; i <= k; ++i) {
            scanf("%d", &cnt[i]);
            cnt2[i] = cnt[i];
        }
        int f = 0, c1 = 0, c2 = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &a[i], &b[i]);
            if (a[i]) {
                if (f) {
                    q.insert(a[i]);
                } else {
                    --cnt[a[i]];
                }
                if (b[i]) {
                    q.insert(a[i]);
                }
                --cnt2[a[i]];
            } else {
                ++c2;
                if (f == 0) {
                    ++c1;
                }
            }
            if (b[i] && f == 0) {
                f = 1;
                if (!a[i]) {
                    --c1;
                }
            }
        }
        int mn = inf;
        for (int i = 1; i <= k; ++i) {
            if (!q.count(i) && c1 >= cnt[i]) {
                mn = min(mn, cnt[i]);
                //cout << i << " - " << cnt[i] << endl;
            }
        }
        //cout << "       " << mn << " " << c1 << " " << c2 << endl;
        if (f) {
            c2 -= mn;
        }
        for (int i = 1; i <= k; ++i) {
            if (c2 >= cnt2[i] || (!q.count(i) && c1 >= cnt[i])) {
                printf("Y");
            } else {
                printf("N");
            }
        }
        printf("\n");
    }
    return 0;
}