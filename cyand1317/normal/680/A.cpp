#include <cstdio>
#include <algorithm>

int t[5];
int ct[104] = { 0 };

int main()
{
    int ans = 0;
    for (int i = 0; i < 5; ++i) {
        scanf("%d", &t[i]);
        ct[t[i]]++;
        ans += t[i];
    }
    int max_discard = 0;
    for (int i = 1; i <= 100; ++i) if (ct[i] >= 2) {
        max_discard = std::max(max_discard, std::min(ct[i], 3) * i);
    }
    printf("%d\n", ans - max_discard);
    return 0;
}