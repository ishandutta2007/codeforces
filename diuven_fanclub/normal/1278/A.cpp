#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int _t = 0; _t < t; _t++) {
        char p[105], h[105];
        scanf("%s", p);
        scanf("%s", h);
        int n = strlen(p), m = strlen(h);
        bool ans = 0;
        for (int i = 0; i + n <= m; i++) {
            int cnt[256] = {};
            for (int j = 0; j < n; j++) {
                cnt[p[j]]++;
                cnt[h[i + j]]--;
            }
            ans = 1;
            for (int j = 0; j < 256; j++) {
                if (cnt[j] == 0) continue;
                ans = 0;
                break;
            }
            if (ans) break;
        }
        if (ans) printf("YES\n");
        else printf("NO\n");
    }
}