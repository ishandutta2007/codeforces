#include <bits/stdc++.h>

using namespace std;

const int N = 100010, INF = 0x7fffffff;

int n, m, len;
int a[N], b[N], c[N], pre[N], from[N], temp[N];
bool v[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &b[i]);
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= n; ++i)
        if (~a[i]) {
            int j = lower_bound(c + 1, c + len + 1, a[i]) - c;
            pre[i] = from[j - 1];
            from[j] = i;
            c[j] = a[i];
            if (len < j) len = j;
        } else {
            int j = 1;
            for (int k = 1; k <= m; ++k) {
                while (j <= len && c[j] < b[k]) ++j;
                temp[k] = j;
            }
            if (len < j) len = j;
            for (int k = m; k; --k) {
                c[temp[k]] = b[k];
                from[temp[k]] = from[temp[k] - 1];
            }
        }
    int cnt = 0;
    for (int i = from[len]; i; i = pre[i])
        temp[++cnt] = i;
    temp[0] = n + 1;
    temp[cnt + 1] = 0;
    a[n + 1] = INF;
    for (int i = cnt + 1; i; --i) {
        int last = a[temp[i]];
        for (int j = temp[i] + 1; j < temp[i - 1]; ++j)
            if (!~a[j]) {
                int k = upper_bound(b + 1, b + m + 1, last) - b;
                if (k > m || b[k] >= a[temp[i - 1]]) break;
                last = a[j] = b[k];
                v[k] = 1;
            }
    }
    for (int i = 1, j = 1; i <= n; ++i)
        if (!~a[i]) {
            while (j < m && v[j]) ++j;
            a[i] = b[j];
            v[j] = 1;
        }
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    putchar('\n');
    return 0;
}