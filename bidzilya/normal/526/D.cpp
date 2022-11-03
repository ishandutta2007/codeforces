#include <bits/stdc++.h>
using namespace std;

const int kMaxLen = 1e6 + 100;

char s[kMaxLen + 1];
int n, k;
int mx_oc[kMaxLen + 1];
int z[kMaxLen];
int b[kMaxLen];
char ans[kMaxLen + 1];

int main()
{
    scanf("%d%d", &n, &k);
    ans[n] = '\0';
    if (k == 1) {
        for (int i = 0; i < n; ++i) {
            ans[i] = '1';
        }
        printf("%s\n", ans);
        return 0;
    }
    scanf("%s", s);

    z[0] = 0;
    for (int l = -1, r = -1, i = 1; i < n; ++i) {
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        } else {
            z[i] = 0;
        }
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    for (int i = 1; i < n; ++i) {
        mx_oc[i] = 0;
        int j = i;
        while (j + i - 1 < n) {
            if (z[j] >= i) {
                ++mx_oc[i];
                j += i;
            } else {
                break;
            }
        }
    }
    mx_oc[n] = 0;
    for (int i = 0; i < n; ++i) {
        b[i] = 0;
    }
    for (int i = 1; i < n; ++i) {
        if ((i + 1) % k == 0) {
            int j = (i + 1) / k;
            if (mx_oc[j] + 1 >= k) {
                b[i] = 1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        ans[i] = '0';
    }

    int right = -1;
    for (int i = 0; i < n; ++i) {
        if (b[i]) {
            right = max(right, i);
            if (i + 1 < n) {
                int j = (i + 1) / k;
                right = max(right, i + min(z[i + 1], j));
            }
        }
        if (i <= right) {
            ans[i] = '1';
        }
    }

    printf("%s\n", ans);

    return 0;
}