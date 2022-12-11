#include <cstdio>
#include <algorithm>
static const int MAXN = 100007;

int n;
int a[MAXN];
long long s[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        s[i] = (i == 0 ? 0 : s[i - 1]) + a[i];
    }

    std::sort(s, s + n);
    int max_occ = 0;
    int i = 0, j;
    for (; i < n; i = j) {
        j = i + 1;
        while (j < n && s[j] == s[i]) ++j;
        if (max_occ < j - i) max_occ = j - i;
    }

    printf("%d\n", n - max_occ);
    return 0;
}