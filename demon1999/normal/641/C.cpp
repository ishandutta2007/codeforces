#include <bits/stdc++.h>

using namespace std;

#define mp make_pair

const int maxn = 2500000;

int a[maxn], ans[maxn];

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, q;
    scanf("%d%d", &n, &q);
    int c = 0;
    int r = 0;
    for (int i = 0; i < q; ++i) {
        int x;
        scanf("%d", &x);
        if (x == 1) {
            int y;
            scanf("%d", &y);
            c += y;
            if (c >= n) c -= n;
            if (c < 0) c += n;
        } else {
            int d = c & 1;
            if (r > 0 && a[r - 1] == d) r--;
            else {
                a[r] = d;
                r++;
            }
        }
    }
    r %= n;
    for (int i = 0; i < n; ++i) {
        if ((i & 1) != (a[0] & 1)) {
            ans[(i - r + n) % n] = i;
        } else {
            ans[(i + r) % n] = i;
        }
    }
    for (int i = n - c; i < n; ++i) printf("%d ", ans[i] + 1);
    for (int i = 0; i < n - c; ++i) printf("%d ", ans[i] + 1);

    return 0;
}