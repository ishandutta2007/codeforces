#include <bits/stdc++.h>

int a[10], suf[10], pos[10], tot;

void testCase() {
    int k;
    scanf("%d", &k);
    tot = 0;
    for (int i = 1; i <= 7; ++i) {
        scanf("%d", a + i);
        if (a[i]) {
            pos[++tot] = i;
        }
    }
    for (int i = 7; i; --i) {
        suf[i] = suf[i + 1] + a[i];
    }
    int ret = 0x3f3f3f3f;
    for (int st = 1; st <= 7; ++st) {
        int tmp = 0;
        if (suf[st] >= k) {
            for (int ed = st; ed <= 7; ++ed) {
                if (suf[st] - suf[ed + 1] >= k) {
                    tmp = ed - st + 1;
                    break;
                }
            }
        } else {
            tmp += 7 - st + 1;
            int kk = k - suf[st];
            tmp += (kk / tot) * 7;
            if (kk % tot == 0) {
                tmp -= 7;
                tmp += pos[tot];
            } else {
                tmp += pos[kk % tot];
            }
        }
        ret = std::min(ret, tmp);
    }
    printf("%d\n", ret);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        testCase();
    }
}
/*
 3
 2
 0 1 0 0 0 0 0
 100000000
 1 0 0 0 1 0 1
 1
 1 0 0 0 0 0 0
 */