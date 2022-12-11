#include <cstdio>
#include <algorithm>
#include <functional>

int main()
{
    int n;
    scanf("%d", &n);
    int l[n];
    for (int i = 0; i < n; i++) scanf("%d", &l[i]);
    std::sort(l, l + n, std::greater<int>());

    long long ans = 0, last = -1;
    for (int i = 1; i < n; i++) if (l[i - 1] - l[i] <= 1) {
        if (last == -1) last = l[i];
        else { ans += last * l[i]; last = -1; }
        i++;
    }

    printf("%I64d\n", ans);
    return 0;
}