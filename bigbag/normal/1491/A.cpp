/**
 *  created: 28/02/2021, 15:35:26
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, q, a[max_n];
int cnt[2];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ++cnt[a[i]];
    }
    while (q--) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            int pos;
            scanf("%d", &pos);
            --pos;
            --cnt[a[pos]];
            a[pos] ^= 1;
            ++cnt[a[pos]];
        } else {
            int k;
            scanf("%d", &k);
            if (cnt[1] >= k) {
                puts("1");
            } else {
                puts("0");
            }
        }
    }
    return 0;
}