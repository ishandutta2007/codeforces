#include <bits/stdc++.h>

using namespace std;

const int max_n = 303333, inf = 1000111222;

int n, x, y;
pair<int, int> a[max_n];

void wa() {
    printf("No\n");
    exit(0);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i].first);
        a[i].second = i + 1;
    }
    sort(a, a + n);
    int last = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (1LL * a[i].first * (n - i) >= y) {
            last = i;
            break;
        }
    }
    if (last == -1) {
        wa();
    }
    for (int i = 0; i < n; ++i) {
        int need = (x + a[i].first - 1) / a[i].first;
        if (i + need <= last) {
            printf("Yes\n");
            printf("%d %d\n", need, n - last);
            for (int j = i; j < i + need; ++j) {
                printf("%d ", a[j].second);
            }
            printf("\n");
            for (int j = last; j < n; ++j) {
                printf("%d ", a[j].second);
            }
            printf("\n");
            return 0;
        }
    }
    pair<int, int> mn = make_pair(inf, inf);
    for (int i = 0; i < n; ++i) {
        int need = (x + a[i].first - 1) / a[i].first;
        if (mn.first != inf) {
            int cnt = mn.first - i;
            if (i + need + cnt <= n && i + need <= n) {
                printf("Yes\n");
                cnt = mn.first - mn.second;
                printf("%d %d\n", need, cnt);
                for (int j = i; j < i + need; ++j) {
                    printf("%d ", a[j].second);
                }
                printf("\n");
                for (int j = mn.second; j < n && cnt; ++j) {
                    if (j < i || j >= i + need) {
                        printf("%d ", a[j].second);
                        --cnt;
                    }
                }
                printf("\n");
                return 0;
            }
        }
        need = (y + a[i].first - 1) / a[i].first;
        mn = min(mn, make_pair(need + i, i));
    }
    wa();
    return 0;
}