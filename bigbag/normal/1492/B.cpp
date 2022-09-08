/**
 *  created: 23/02/2021, 11:08:47
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        set<int> q(a, a + n);
        int last = n;
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] == *q.rbegin()) {
                for (int j = i; j < last; ++j) {
                    printf("%d ", a[j]);
                    q.erase(a[j]);
                }
                last = i;
            }
        }
        puts("");
    }
    return 0;
}