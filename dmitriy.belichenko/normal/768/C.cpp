#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int cnt[2][1024];

int main() {
    int n, k, x;
    scanf("%d%d%d", &n, &k, &x);

    int mx = 1024;

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        cnt[0][a]++;
    }

    int flag = 0;
    while (k--) {
        int old = flag;
        flag ^= 1;
        int len = 0;
        for (int i = 0; i < mx; i++) {
            if (cnt[old][i] > 0) {
                int t1, t2;
                if (len & 1) {
                    t1 = (cnt[old][i] >> 1);
                    t2 = cnt[old][i] - t1;
                }
                else {
                    t2 = (cnt[old][i] >> 1);
                    t1 = cnt[old][i] - t2;
                }
                len += cnt[old][i];
                cnt[old][i] = 0;
                cnt[flag][i] += t2;
                cnt[flag][i^x] += t1;
            }
        }
    }
    int mi = 0;
    while (cnt[flag][mi] == 0) mi++;
    mx = 1023;
    while (cnt[flag][mx] == 0) mx--;
    printf("%d %d", mx, mi);
}